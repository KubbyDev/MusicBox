import mido
import threading
from Programs import tools
import Programs.MidiToNotes.track_tools as track_tools
from Programs.NotesToInstrument import main as notestoinstrument


# True until the conversion is done
_working = False
# Stores the last conversion results
conversion_results = {'tracks':[],'totalLength':0}


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
    events = track_tools.preprocess(miditrack, tpb, tempo)
    # Does some cleaning with overlapping notes
    track_tools.clean_overlapping(events)
    # Converts the events list to a chunk list with notes in each chunk
    chunks = track_tools.to_chunks(events)
    # Separates the chunk list into multiple tracks, one for the
    # main notes and the others for the harmonics
    root, harmonics = track_tools.separate_chords(chunks)
    tracks = [root] + harmonics
    for i in range(len(tracks)):
        # Adds stops and combines some notes
        resultTrack = track_tools.process_stops(tracks[i])
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
def _convert(file):
    global _working
    global conversion_results
    # Starts a thread for the conversion of each track
    results = []
    threads = []
    for i in range(1, len(file.tracks)):
        results.append([])
        t = threading.Thread(target=_to_notes, args=(
            file.tracks[i],
            results,
            i-1,
            file.ticks_per_beat,
            get_tempo(file)
        ))
        t.start()
        threads.append(t)
    # Waits for the threads to terminate
    tools.wait_for_threads(threads)
    # Post processes the results
    total_length = 0
    tracks = []
    for thread in results:
        for track in thread:
            length = track.pop('length')
            if length > total_length: total_length = length
            tracks.append(track)
    conversion_results = {'tracks':tracks,'totalLength':total_length}
    _working = False
    # Starts the requirements computation
    notestoinstrument.start_instruments_computation()


# Starts the conversion of all the tracks in the
# musicfile in ServerStorage (asynchronously)
def start_musicfile_conversion():
    global _working
    if _working:
        return 'A conversion is already running', 500
    try:
        _working = True
        file = mido.MidiFile('ServerStorage/musicfile')
        threading.Thread(target=_convert, args=(file,)).start()
    except:
        _working = False
        return "Couldn't open musicfile or start thread", 500
    return 'Started converting musicfile'


# Gives a rough conversion progression percentage and a status message
def get_progression():
    if _working: return {'percent': 50, 'status':'Converting...'}
    else: return {'percent': 100, 'status':'Done'}