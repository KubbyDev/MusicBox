import mido
import track_tools


mid = mido.MidiFile('C:\\Users\\gbrlj\\Desktop\\test.mid')
track = mid.tracks[1]

tempo = 0
for m in mid.tracks[0]:
    if m.type == 'set_tempo':
        tempo = m.tempo

events = track_tools.preprocess(track, mid.ticks_per_beat, tempo)
track_tools.clean_overlapping(events)
chunks = track_tools.to_chunks(events)
root, harmonics = track_tools.separate_chords(chunks)
tr = [root] + harmonics
tracks = []
for t in tr:
    tracks.append(track_tools.process_stops(t))

i = 0
end = 0
print('const tracks = [')
for t in tracks:
    name = "Track" + str(i)
    lowest = 100000
    highest = 0
    for n in t:
        if n[1] > end: end = n[1]
        if n[2] > highest: highest = n[2]
        if n[2] < lowest: lowest = n[2]
    print('    {name:"%s",lowest:%i,highest:%i,notes:[' % (name, lowest, highest), end='')
    for n in t:
        print('{start:%i,end:%i,pitch:%i}' % (round(n[0]), round(n[1]), n[2]), end=',')
    print(']},')
    i+=1
print('];\nconst totallength = %i;' % round(end))
