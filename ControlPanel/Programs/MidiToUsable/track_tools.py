from sortedcontainers import SortedList


__NOTE_ON = 0
__NOTE_OFF = 1


class __Event:
    def __init__(self, time, pitch, eventType, noteIndex):
        self.time, self.pitch, self.type, self.noteIndex = time, pitch, eventType, noteIndex


class __Chunk:
    def __init__(self, start, end, notes): # notes is an array of (pitch, index)
        self.start, self.end, self.notes = start, end, notes


# Converts a list of messages from mido to a sorted list of on/off events (timeMs, pitch, type, index)
# Takes into account tempo changes. The sorted list is in increasing timeMs
def preprocess(messages, ticks_per_beat, start_tempo):
    # TODO Aftertouch
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
            res.add(__Event(
                (ticks * tempo) / (ticks_per_beat * 1000),
                m.note,
                __NOTE_ON if m.type == 'note_on' else __NOTE_OFF,
                noteIndex
            ))
            if m.type == 'note_on': noteIndex += 1
    return res


# Removes unnecessarily overlapping notes. Notes are considered overlapping if
# the off event of the first note is less than threshold milliseconds before the on event of the second note.
# The notes can be of any pitch. In that case, the off event will be moved to the on event time.
# The output is the sorted list of events given in input
def clean_overlapping(events, threshold=25):
    # TODO: on on off off samepitch
    for e in events:
        # Only processes ON events
        if e.type == __NOTE_OFF: continue
        # Gets all the OFF events between the time of this event and threshold ms after
        tocorrect = events.irange(e.time, e.time+threshold)
        tocorrect = list(filter(lambda ev: ev.type == __NOTE_OFF, tocorrect))
        if not tocorrect: continue
        # Moves these events to the time of the on event
        first = events.index(tocorrect[0])
        for i in range(len(tocorrect)):
            events[i+first].time = e.time


# Takes a sorted list of on/off events (timeMs, pitch, type, index) and translates it into a list of chunks,
# each chunk containing a start point, an end point (milliseconds) and a list of notes (pitch, index)
def to_chunks(events):
    res = []
    notes = []
    chunkStartTime = events[0].time
    for event in events:
        # Saves the last chunk everytime the played notes change
        if event.time != chunkStartTime:
            res.append(__Chunk(
                chunkStartTime,
                event.time,
                notes
            ))
        if event.type == __NOTE_OFF: notes.remove((event.pitch, event.noteIndex))
        if event.type == __NOTE_ON: notes.append((event.pitch, event.noteIndex))
        chunkStartTime = event.time


# Takes a list of chunks from the to_chunks function and separates it into lists of
# notes (pitch, start, end, index).
def separate_chords(chunks):
    pass


# Takes a list of notes (pitch, start, end, index) and adds stops when a note stops
# and starts again with the same pitch. It also combines these notes when it is the same index.
# The return value is a list of notes (pitch, start, end)
def process_stops(track, stopLength=10):
    pass
