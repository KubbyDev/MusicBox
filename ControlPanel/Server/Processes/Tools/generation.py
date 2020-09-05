# This file contains general functions for the generation part

# Generates the melody as an array of notes and an array of times
def notes_and_times(track):
    notes = []
    times = []
    lastNoteEnd = 0
    for note in track['notes']:
        # If there is a hole between the last note and this one, adds a 0 note
        if note['start'] > lastNoteEnd:
            notes.append(0)
            times.append(round(lastNoteEnd))
        # Adds this note
        notes.append(round(note['pitch']))
        times.append(round(note['start']))
        lastNoteEnd = note['end']
    return {'notes':notes, 'times':times}