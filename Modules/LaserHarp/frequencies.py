note_names = ['C','C#','D','D#','E','F','F#','G','G#','A','A#','B']
oct = [
    32.70,
    34.65,
    36.71,
    38.89,
    41.20,
    43.65,
    46.25,
    49.00,
    51.91,
    55.00,
    58.27,
    61.74
]

def print_octave(octave, number):
    print('    { ', end='')
    for i in range(12):
        print("/*%s%i*/%i," % (
            note_names[i],
            number,
            round(octave[i])
        ), end='')
    print(' },')

for o in range(1, 8+1):
    print_octave(oct, o)
    for i in range(12):
        oct[i] *= 2
    
