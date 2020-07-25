import mido
import threading
from Programs import tools as programtools, jobmanager
import Programs.Notes.Tools.translation as translation
import Programs.Notes.Tools.tools as tools
from Programs.Instruments import instruments_list


def get_tempo(midifile):
    tempo = 0
    for m in midifile.tracks[0]:
        if m.type == 'set_tempo':
            tempo = m.tempo
    if tempo == 0:
        print("ERROR: Couldn't find tempo")
    return tempo


# Does the midi to notes conversion on the specified track and computes
# some additionnal information. The result is stored in the specified
# list at the specified index in a dictionnary
# Results list:
# Each index corresponds to a thread during a conversion. Each thread
# will place in its spot a list of tracks. Each track is a dictionnary
# containing information about the track and a list of notes. Each note
# is a dictionnary with information about the note
def _to_notes(miditrack, results, index, tpb, tempo):
    # Converts the midi events to a more usable list of event
    events = translation.preprocess(miditrack, tpb, tempo)
    # Does some cleaning with overlapping notes
    translation.clean_overlapping(events)
    # Converts the events list to a chunk list with notes in each chunk
    chunks = translation.to_chunks(events)
    # Separates the chunk list into multiple tracks, one for the
    # main notes and the others for the harmonics
    root, harmonics = translation.separate_chords(chunks)
    tracks = [root] + harmonics
    for i in range(len(tracks)):
        # Adds stops and combines some notes
        resultTrack = translation.process_stops(tracks[i])
        # Computes the highest and lowest pitch, and the total length
        # Converts the notes to dictionnaries
        notes = []
        highest = 0
        lowest = 10000
        length = 0
        for note in resultTrack:
            if note[1] > length: length = note[1] # Latest end
            if note[2] > highest: highest = note[2] # Highest pitch
            if note[2] < lowest: lowest = note[2] # Lowest pitch
            notes.append({'start':note[0],'end':note[1],'pitch':note[2]})
        # Saves the results
        results[index].append({
            'name': miditrack.name + str(i),
            'lowest': lowest,
            'highest': highest,
            'length': length,
            'notes': notes,
        })


# Converts all the tracks in the musicfile in ServerStorage
def _convert(results, progress, file):
    # Starts a thread for the conversion of each track
    threads = []
    for i in range(1, len(file.tracks)):
        results.append([])
        t = threading.Thread(target=_to_notes, args=(
            file.tracks[i],
            results,
            i-1,
            file.ticks_per_beat,
            get_tempo(file),
        ))
        threads.append(t)
    # Starts the threads when the results list is fully formed to avoid race condition
    for t in threads: t.start()
    # Waits for the threads to terminate
    programtools.wait_for_threads(threads)


# Starts the conversion of all the tracks in the
# musicfile in ServerStorage (asynchronously)
def start_musicfile_conversion():
    try:
        file = mido.MidiFile('ServerStorage/musicfile')
        jobmanager.launch_job(
            main=_convert,
            args=file,
            name='notes',
            progress=None,
            postprocess=tools.post_process,
            done=instruments_list.start_instruments_computation
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started converting musicfile'