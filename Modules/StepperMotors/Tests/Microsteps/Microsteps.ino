// This test was made to see if it was possible to get clearer notes 
// using the microstep functionnality (especially for the low frequencies)
// Turns out playing with 4th steps or full steps doesn't change the sound
// if you make steps at the same rate. This can't be used to play better low
// notes but it could be used to play higher high notes.
// Also the notes produces with microstepping are less loud

// Step pin of each motor driver
#define STEP 3
#define MS2 2

#define C4 3778 // DO
#define C4d 3567 // DO#
#define D4 3363 // RE
#define D4d 3175 // RE#
#define E4 2995 // MI
#define F4 2825 // FA
#define F4d 2674 // FA#
#define G4 2515 // SOL
#define G4d 2375 // SOL#
#define A5 2243 // LA
#define A5d 2112 // LA#
#define B5 1996 // SI
#define C5 1886 // DO

void setup() {
    pinMode(STEP, OUTPUT);
    pinMode(MS2, OUTPUT);    
}

void loop() {    
    play(C4, 333);
    play(D4, 333);
    play(E4, 333);
    play(F4, 333);
    play(G4, 333);
    play(A5, 333);
    play(B5, 333);
    play(C5, 333);

    playMicrostep(C4, 333);
    playMicrostep(D4, 333);
    playMicrostep(E4, 333);
    playMicrostep(F4, 333);
    playMicrostep(G4, 333);
    playMicrostep(A5, 333);
    playMicrostep(B5, 333);
    playMicrostep(C5, 333);
}

void playMicrostep(int delayUS, int durationMS) {
    digitalWrite(MS2, HIGH);
    for(int i = 0; i < 4; i++)
        play(delayUS/4, durationMS/4);
    digitalWrite(MS2, LOW);
}

void play(int delayUS, int durationMS) {
    for(long i = 0; i < (durationMS*1000L)/delayUS; i++) {
        digitalWrite(STEP, HIGH);
        delayMicroseconds(delayUS - 5);
        digitalWrite(STEP, LOW);
        delayMicroseconds(5);
    }
}
