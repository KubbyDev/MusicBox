// Step pin of each motor driver
#define M1 3
#define M2 4
#define M3 5

#define A3 4489 // LA
#define A3d 4239 // LA#
#define B3 4001 // SI

#define C4 3778 // DO
#define C4d 3567 // DO#
#define D4 3363 // RE
#define D4d 3175 // RE#
#define E4 2995 // MI
#define F4 2825 // FA
#define F4d 2674 // FA#
#define G4 2515 // SOL
#define G4d 2375 // SOL#
#define A4 2243 // LA
#define A4d 2112 // LA#
#define B4 1996 // SI

#define C5 1886 // DO
#define C5d 1776 // DO#
#define D5 1678 // RE
#define D5d 1584 // RE#
#define E5 1495 // MI
#define F5 1409 // FA
#define F5d 1328 // FA#
#define G5 1252 // SOL
#define G5d 1182 // SOL#
#define A5 1116 // LA
#define A5d 1053 // LA#
#define B5 993 // SI

#define C6 936 // DO

void setup() {
    Serial.begin(9600);
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);    
    pinMode(M3, OUTPUT);
}

void loop() {
    doremifasollasidoLOW(M1);
    doremifasollasidoLOW(M2);
    doremifasollasidoLOW(M3);

    doremifasollasidoHIGH(M1);
    doremifasollasidoHIGH(M2);
    doremifasollasidoHIGH(M3);
}

void play(int delayUS, int durationMS, int motor) {
    for(long i = 0; i < (durationMS*1000L)/delayUS; i++) {
        digitalWrite(motor, HIGH);
        delayMicroseconds(delayUS - 5);
        digitalWrite(motor, LOW);
        delayMicroseconds(5);
    }
}

void doremifasollasidoLOW(int motor) {
    play(C4, 333, motor);
    play(D4, 333, motor);
    play(E4, 333, motor);
    play(F4, 333, motor);
    play(G4, 333, motor);
    play(A4, 333, motor);
    play(B4, 333, motor);
    play(C5, 333, motor);
}

void doremifasollasidoHIGH(int motor) {
    play(C5, 333, motor);
    play(D5, 333, motor);
    play(E5, 333, motor);
    play(F5, 333, motor);
    play(G5, 333, motor);
    play(A5, 333, motor);
    play(B5, 333, motor);
    play(C6, 333, motor);
}
