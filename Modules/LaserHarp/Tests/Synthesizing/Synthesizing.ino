#define PIN 10
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494
#define C5 523

void playNote(int note, int timeMS) {
    tone(PIN,note,timeMS);
    delay(timeMS);
}

void setup() {

    pinMode(PIN, OUTPUT);

    playNote(C4, 300);
    playNote(D4, 300);
    playNote(E4, 300);
    playNote(F4, 300);
    playNote(G4, 300);
    playNote(A4, 300);
    playNote(B4, 300);  
    playNote(C5, 300);
}

void loop() {
}
