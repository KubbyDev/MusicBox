import mido
import threading

from Server import config
from Server.Processes.Tools import tools, translation, postprocess, progress as progress_functions
from Server.Processes import instruments_list
from Server.Processes.JobManager import jobmanager


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
# containing information about the track and a list of note dictionnaries
# with start milliseconds, end milliseconds and midi pitch
def _to_notes(miditrack, results, progress, index, tpb, tempo):
    # Converts the midi events to a more usable list of event
    events = translation.preprocess(miditrack, tpb, tempo)
    progress[index] += 1
    # Does some cleaning with overlapping notes
    translation.clean_overlapping(events)
    progress[index] += 1
    # Converts the events list to a chunk list with notes in each chunk
    chunks = translation.to_chunks(events)
    progress[index] += 1
    # Separates the chunk list into multiple tracks, one for the
    # main notes and the others for the harmonics
    root, harmonics = translation.separate_chords(chunks)
    progress[index] += 96
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
        for n in resultTrack:
            if n[1] > length: length = n[1]  # Latest end
            if n[2] > highest: highest = n[2]  # Highest pitch
            if n[2] < lowest: lowest = n[2]  # Lowest pitch
            notes.append({'start': n[0], 'end': n[1], 'pitch': n[2]})
        # Saves the results
        results[index].append({
            'name': miditrack.name + str(i),
            'lowest': lowest,
            'highest': highest,
            'length': length,
            'notes': notes,
        })
    progress[index] += 1


# Converts all the tracks in the musicfile in Storage
def _convert(results, progress, file):
    # Starts a thread for the conversion of each track
    threads = []
    for i in range(1, len(file.tracks)):
        results.append([])
        progress.append(0)
        t = threading.Thread(target=_to_notes, args=(
            file.tracks[i],
            results,
            progress,
            i-1,
            file.ticks_per_beat,
            get_tempo(file),
        ))
        threads.append(t)
    # Progress is calculated with the sum of the progress of each track (0 to 100)
    progress.append(len(threads)*100)
    # Starts the threads when the results list is fully formed to avoid race condition
    for t in threads: t.start()
    # Waits for the threads to terminate
    tools.wait_for_threads(threads)


# Starts the conversion of all the tracks in the
# musicfile in Storage (asynchronously)
def start_musicfile_conversion():
    try:
        file = mido.MidiFile(config.Storage.cache_folder + 'musicfile')
        jobmanager.launch_job(
            main=_convert,
            args=file,
            name='notes',
            progress=progress_functions.from_numbers_fixed_status('Converting from MIDI to notes'),
            postprocess=postprocess.notes,
            done=instruments_list.start_instruments_computation
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started converting musicfile'
