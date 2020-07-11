import mido


mid = mido.MidiFile('C:\\Users\\gbrlj\\Desktop\\PiratesOfTheCaribbean.mid')
t1 = mid.tracks[2]
t2 = mid.tracks[1]
t3 = mid.tracks[3]

tempo = 0
for m in mid.tracks[0]:
    if m.type == 'set_tempo':
        tempo = m.tempo
mult = tempo / (mid.ticks_per_beat * 1000) # millisecond per tick


def notes(trk):

    res = []
    currentNote = 0
    lastNote = 0
    lastNoteStopTime = 0
    time = 0

    for n in trk:
        time += n.time
        if n.type == 'note_on':
            # If a note was playing, stops and saves it
            if currentNote != 0:
                res.append((currentNote, time))
                # If a note appears twice, saves a small delay even if there is no silence
                if currentNote == n.note:
                    res.append((0, time + 10 / mult))  # 10 milliseconds
                lastNoteStopTime = time
                lastNote = n.note
            # If no note was playing, saves a silence note
            elif time - lastNoteStopTime > 0:
                res.append((0, time))
            # If a note appears twice, saves a small delay even if there is no silence
            elif lastNote == n.note:
                res.append((0, time + 10/mult)) # 10 milliseconds
            # Starts playing the new note
            currentNote = n.note
        if n.type == 'note_off':
            # Saves the note that was playing if it's the right one
            if n.note == currentNote:
                res.append((currentNote, time))
                currentNote = 0
                lastNoteStopTime = time
                lastNote = n.note

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


def results(nts, nb, offset=0):
    global mult

    n = []
    for i in nts: n.append(i[0])
    d = []
    for i in nts: d.append(i[1])

    print("const PROGMEM uint16_t notes"+str(nb)+"[] = {")
    print("    ", end='')
    for i in n: print(nb_to_english(i, offset), end=',')
    print(0)
    print("};")

    print("const PROGMEM uint32_t durations"+str(nb)+"[] = {")
    print("    ", end='')
    for i in d: print(round(i*mult), end=',')
    print(4294967295)
    print("};")


nts1 = notes(t1)
nts2 = notes(t2)
nts3 = notes(t3)
results(nts1, 1, 3)
results(nts2, 2, 0)
results(nts3, 3, 0)