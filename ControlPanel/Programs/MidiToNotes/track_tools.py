from sortedcontainers import SortedList
from music21.chord import Chord


NOTE_ON = 0
NOTE_OFF = 1


class Event:
    def __init__(self, time, pitch, eventType, noteIndex):
        self.time, self.pitch, self.type, self.noteIndex = time, pitch, eventType, noteIndex


class Chunk:
    def __init__(self, start, end, notes): # notes is an array of (pitch, index)
        self.start, self.end, self.notes = start, end, notes


# Converts a list of messages from mido to a sorted list of on/off events (timeMs, pitch, type, index)
# Takes into account tempo changes. The sorted list is in increasing timeMs
def preprocess(messages, ticks_per_beat, start_tempo):
    res = SortedList(key=lambda e: e.time)
    ticks = 0 # Counts the ticks from the beginning
    tempo = start_tempo
    noteIndex = 0
    for m in messages:
        ticks += m.time
        # Tempo change
        if m.type == 'set_tempo':
            tempo = m.tempo
            continue
        # ON or OFF events
        if m.type in ['note_on', 'note_off']:
            on_event = m.type == 'note_on'
            if on_event and m.velocity == 0: on_event = False # note_on with velocity 0 is actually a note_off
            res.add(Event(
                (ticks * tempo) / (ticks_per_beat * 1000),
                m.note,
                NOTE_ON if on_event else NOTE_OFF,
                noteIndex if on_event else 0 # The note index is only saved for the ON event
            ))
            if on_event: noteIndex += 1
    return res


# Removes unnecessarily overlapping notes. Notes are considered overlapping if
# the off event of the first note is less than threshold milliseconds before the on event of the second note.
# The notes can be of any pitch. In that case, the off event will be moved to the on event time.
# The output is the sorted list of events given in input
def clean_overlapping(events, threshold=30):
    # TODO: on on off off samepitch
    for e in events:
        # Only processes ON events
        if e.type == NOTE_OFF: continue
        # Gets all the OFF events between the time of this event and threshold ms after
        tocorrect = events.irange(e, Event(e.time+threshold,0,0,0))
        tocorrect = list(filter(lambda ev: ev.type == NOTE_OFF, tocorrect))
        if not tocorrect: continue
        # Moves these events to the time of the on event
        first = events.index(tocorrect[0])
        for i in range(len(tocorrect)):
            event = events[i+first]
            events.remove(event)
            event.time = e.time
            events.add(event)


# Takes a sorted list of on/off events (timeMs, pitch, type, index) and translates it into a list of chunks,
# each chunk containing a start point, an end point (milliseconds) and a list of notes (pitch, index)
def to_chunks(events):
    res = []
    notes = SortedList()
    chunkStartTime = events[0].time
    for event in events:
        # Saves the last chunk everytime the played notes change (only if there are notes playing)
        if event.time != chunkStartTime and len(notes) > 0:
            res.append(Chunk(
                chunkStartTime,
                event.time,
                notes[:]
            ))
        if event.type == NOTE_ON: notes.add((event.pitch, event.noteIndex))
        if event.type == NOTE_OFF:
            for n in notes:
                if n[0] == event.pitch: notes.remove(n)
        chunkStartTime = event.time
    return res


# Takes a list of chunks from the to_chunks function and separates it into lists of
# notes (start, end, pitch, index). The returned lists are the root and the list of harmonics
def separate_chords(chunks):
    root = []
    harmonics = []
    nbHarmonics = 0
    for chunk in chunks:
        nbNotes = len(chunk.notes)
        # Adds harmonics partitions if necessary
        while nbNotes > nbHarmonics+1:
            l = []
            harmonics.append(l)
            nbHarmonics += 1
        # Determines the root of the chord
        chord = Chord(list(n for n,i in chunk.notes))
        rootIndex = list(chord.pitches).index(chord.root())
        # Distributes the notes in the lists
        harmonicIndex = 0
        for i in range(nbNotes):
            note = (
                chunk.start,
                chunk.end,
                chunk.notes[i][0], # pitch
                chunk.notes[i][1]  # index
            )
            if i == rootIndex:
                root.append(note)
            else:
                harmonics[harmonicIndex].append(note)
                harmonicIndex += 1
    return root, harmonics


# Takes a list of notes (start, end, pitch, index) and adds stops (the first note stops sooner)
# when a note stops and starts again with the same pitch. It also combines these notes when it is
# the same index. The returned value is a list of notes (start, end, pitch)
def process_stops(track, stopLength=10):
    res = []
    current = list(track[0])
    for note in track[1:]:
        if current[3] == note[3]: # Same note (same index)
            current[1] = note[1] # Moves the note end
            continue
        # Different indices
        res.append((
            current[0],
            current[1] - (stopLength if current[2] == note[2] else 0), # Adds an empty space if pitches are equal
            current[2]
        ))
        current = list(note)
    # Adds the last note
    res.append((current[0], current[1], current[2]))
    return res


# Merges two list of notes (start, end, pitch). Makes sure the notes are ordered by starting time
def merge(tracks):
    sl = SortedList(key=lambda n: n[0]) # Sorts by start time
    for track in tracks:
        sl.update(track)
    return sl[:]