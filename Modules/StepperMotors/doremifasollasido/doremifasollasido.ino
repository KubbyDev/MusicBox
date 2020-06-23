// Step pin of each motor driver
#define M1 3
#define M2 4
#define M3 5

#define C4 3768 // DO
#define D4 3355 // RE
#define E4 2989 // MI
#define F4 2821 // FA
#define G4 2511 // SOL
#define A5 2236 // LA
#define B5 1992 // SI
#define C5 1879 // DO

void setup() {
    Serial.begin(9600);
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);    
    pinMode(M3, OUTPUT);
}

void loop() {    
    doremifasollasido(M1);
    doremifasollasido(M2);
    doremifasollasido(M3);
}

void play(int delayUS, int durationMS, int motor) {
    for(long i = 0; i < (durationMS*1000L)/delayUS; i++) {
        digitalWrite(motor, HIGH);
        delayMicroseconds(delayUS - 5);
        digitalWrite(motor, LOW);
        delayMicroseconds(5);
    }
}

void doremifasollasido(int motor) {
    play(C4, 333, motor);
    play(D4, 333, motor);
    play(E4, 333, motor);
    play(F4, 333, motor);
    play(G4, 333, motor);
    play(A5, 333, motor);
    play(B5, 333, motor);
    play(C5, 333, motor);
}
