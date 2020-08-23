#include <Servo.h>

#define NB_LASERS 12
#define NB_SERVOS 6
#define SERVO_LEFT 120
#define SERVO_RIGHT 60
#define SERVO_MID 90
#define SPEAKER_PIN 23
#define THREASHOLD 400 // Below that threshold the laser is considered to be cut

const int SERVO_PINS[NB_SERVOS] = {2,3,4,5,6,7};
const int RESISTOR_PINS[NB_LASERS] = {A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12};
const int LED_PINS[8] = {24,25,26,27,28,29,30,31}
Servo servos[NB_SERVOS];
#define OCTAVE_UP 32
#define OCTAVE_DOWN 33

const unsigned int frequencies[] = {
    { /*C1*/33,/*C#1*/35,/*D1*/37,/*D#1*/39,/*E1*/41,/*F1*/44,/*F#1*/46,/*G1*/49,/*G#1*/52,/*A1*/55,/*A#1*/58,/*B1*/62, },
    { /*C2*/65,/*C#2*/69,/*D2*/73,/*D#2*/78,/*E2*/82,/*F2*/87,/*F#2*/92,/*G2*/98,/*G#2*/104,/*A2*/110,/*A#2*/117,/*B2*/123, },
    { /*C3*/131,/*C#3*/139,/*D3*/147,/*D#3*/156,/*E3*/165,/*F3*/175,/*F#3*/185,/*G3*/196,/*G#3*/208,/*A3*/220,/*A#3*/233,/*B3*/247, },
    { /*C4*/262,/*C#4*/277,/*D4*/294,/*D#4*/311,/*E4*/330,/*F4*/349,/*F#4*/370,/*G4*/392,/*G#4*/415,/*A4*/440,/*A#4*/466,/*B4*/494, },
    { /*C5*/523,/*C#5*/554,/*D5*/587,/*D#5*/622,/*E5*/659,/*F5*/698,/*F#5*/740,/*G5*/784,/*G#5*/831,/*A5*/880,/*A#5*/932,/*B5*/988, },
    { /*C6*/1046,/*C#6*/1109,/*D6*/1175,/*D#6*/1244,/*E6*/1318,/*F6*/1397,/*F#6*/1480,/*G6*/1568,/*G#6*/1661,/*A6*/1760,/*A#6*/1865,/*B6*/1976, },
    { /*C7*/2093,/*C#7*/2218,/*D7*/2349,/*D#7*/2489,/*E7*/2637,/*F7*/2794,/*F#7*/2960,/*G7*/3136,/*G#7*/3322,/*A7*/3520,/*A#7*/3729,/*B7*/3951, },
    { /*C8*/4186,/*C#8*/4435,/*D8*/4699,/*D#8*/4978,/*E8*/5274,/*F8*/5587,/*F#8*/5920,/*G8*/6272,/*G#8*/6644,/*A8*/7040,/*A#8*/7459,/*B8*/7903, },
}

// The notes are encoded as midi pitches
const PROGMEM uint16_t notes[] = {
    69, 71, 73, 74, 76, 78, 80, 81, 0
};
const PROGMEM uint32_t times[] = {
    1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 4294967295
};

int currentOctave = 4;
int octaveUpPressed = 0;
int octaveDownPressed = 0;
int index = 0;

void setup() {
    // Servos
    for(int i = 0; i < sizeof(SERVO_PINS); i++) {
        int pin = SERVO_PINS[i];
        pinMode(pin, OUTPUT);
        servos[i].attach(pin);
        servos[i].write(SERVO_MID);
    }
    // Photoresistors
    for(int i = 0; i < sizeof(RESISTOR_PINS); i++)
        pinMode(RESISTOR_PINS[i], INPUT);
    // Leds
    for(int i = 0; i < sizeof(LED_PINS); i++)
        pinMode(LED_PINS[i], OUTPUT);
    // Others
    pinMode(SPEAKER_PIN, OUTPUT);
    pinMode(OCTAVE_UP, INPUT);
    pinMode(OCTAVE_DOWN, INPUT);
}

void loop() {
    controlLoop();
    harpLoop();
}

// Changes the currently selected octave. Can be called
// by the control loop or by the harp loop (buttons)
void changeOctave(octave) {
    for(int i = 1; i <= 8; i++)
        digitalWrite(LED_PINS[i-1], i == octave);
    currentOctave = octave;
}

// Harp section -----------------------------------------------------------------------

// Finds the laser that is being cut if there is one 
// Returns the index of the laser, -1 if no laser is cut
int findCutLaser() {
    int res = NB_LASERS;
    while(res > 0 && analogRead(RESISTOR_PINS) > THRESHOLD)
        res--;
    return res;
}

// Plays the given note for 25 ms
void playNote(int note) {
    int oct = note/12 -1;
    int nte = note%12;
    int freq = frequencies[oct-1][nte];
    tone(SPEAKER_PIN,freq,25);
}

// Checks the octave control buttons and changes the current octave if necessary
void changeOctaveButtons() {
    
    if(!octaveUpPressed && digitalRead(OCTAVE_UP)) {
        changeOctave(currentOctave+1);
        octaveUpPressed = 1;
    }
    else octaveUpPressed = 0;
    
    if(!octaveDownPressed && digitalRead(OCTAVE_DOWN)) {
        changeOctave(currentOctave-1);
        octaveDownPressed = 1;
    }
    else octaveDownPressed = 0;
}

// Part of the loop function that handles the harp 
// (finding what laser is being cut and playing the appropriate sound)
void harpLoop() {
    int cutLaser = findCutLaser();
    if(cutLaser > 0) {
        int note = 12*(currentOctave+1) + cutLaser;
        playNote(note);
    }
}

// Control section --------------------------------------------------------------------

void changeNote(note) {

    int toUse = -1; // Index of the servo that will cut a laser
    
    if(note != 0) {
        changeOctave(note/12); // Changes the octave if there is a note to play
        toUse = (note%12)/2;
    }

    for(int i = 0; i < NB_SERVOS; i++) {
        if(i != toUse) {
            servos[i].write(SERVO_MID);
            continue;
        }
        servos[i].write(note%2 == 0 ? SERVO_RIGHT : SERVO_LEFT);
    }
}

void controlLoop() {
    
    unsigned long now = millis();
    
    if(now > pgm_read_dword(times + index)) {
        changeNote(pgm_read_word(notes + index));
        index++;
    }
}
