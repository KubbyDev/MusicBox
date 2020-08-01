# This file contains general functions for the generation part

def notes_and_times(track):
    notes = []
    times = []
    lastNoteEnd = 0
    for note in track['notes']:
        # If there is a hole between the last note and this one, adds a 0 note
        if note['start'] > lastNoteEnd:
            notes.append(0)
            times.append(lastNoteEnd)
        # Adds this note
        notes.append(note['pitch'])
        times.append(note['start'])
        lastNoteEnd = note['end']
    return {'notes':notes, 'times':times}