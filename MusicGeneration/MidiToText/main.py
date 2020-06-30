import mido

mid = mido.MidiFile('D:\\Bordel\\test.mid')
track = mid.tracks[1]

def notes(trk):

    res = []
    currentNote = 0
    currentStartTime = 0
    lastNoteStopTime = 0
    time = 0

    for n in trk:
        time += n.time
        if n.type == 'note_on':
            # If a note was playing, stops and saves it
            if currentNote != 0:
                res.append((currentNote, time - currentStartTime))
                lastNoteStopTime = time
            # If no note was playing, saves a silence note
            elif time - lastNoteStopTime > 0:
                res.append((0, time - lastNoteStopTime))
            # Starts playing the new note
            currentNote = n.note
            currentStartTime = time
        if n.type == 'note_off':
            # Saves the note that was playing if it's the right one
            if n.note == currentNote:
                res.append((currentNote, time - currentStartTime))
                currentNote = 0
                lastNoteStopTime = time

    return res


def nb_to_english(number, offset=0):
    if number == 0: return '0'
    number += offset*12
    if number == 57: return 'A4'
    elif number == 58: return 'A4d'
    elif number == 59: return 'B4'
    elif number == 60: return 'C4'
    elif number == 61: return 'C4d'
    elif number == 62: return 'D4'
    elif number == 63: return 'D4d'
    elif number == 64: return 'E4'
    elif number == 65: return 'F4'
    elif number == 66: return 'F4d'
    elif number == 67: return 'G4'
    elif number == 68: return 'G4d'
    elif number == 69: return 'A5'
    elif number == 70: return 'A5d'
    elif number == 71: return 'B5'
    elif number == 72: return 'C5'
    elif number == 73: return 'C5d'
    elif number == 74: return 'D5'
    elif number == 75: return 'D5d'
    elif number == 76: return 'E5'
    elif number == 77: return 'F5'
    elif number == 78: return 'F5d'
    elif number == 79: return 'G5'
    elif number == 80: return 'G5d'
    elif number == 81: return 'A6'
    elif number == 82: return 'A6d'
    elif number == 83: return 'B6'
    elif number == 84: return 'C6'
    else: raise Exception("Unknown note " + str(number))


nts = notes(track)
print(nts)

offset = 2

n = []
for i in nts: n.append(i[0])
d = []
for i in nts: d.append(i[1])

print("int notes1[] = {")
print("    ", end='')
for i in n[:-1]: print(nb_to_english(i, offset), end=',')
print(nb_to_english(n[-1], offset))
print("};")

print("int durations1[] = {")
print("    ", end='')
for i in d[:-1]: print(i, end=',')
print(d[-1])
print("};")