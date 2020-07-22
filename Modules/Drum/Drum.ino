#include <Servo.h>

#define SERVO1 8
#define SERVO2 9
#define MOVEMENT_TIME 125

#define S1_UP   120 // Punches the top instrument (wood)
#define S1_MID  90  // Rest
#define S1_DOWN 60  // Punches the bottom instrument (drum)
#define S2_UP   60  // Punches the top instrument (cymbal)
#define S2_MID  90  // Rest
#define S2_DOWN 120 // Punches the bottom instrument (drum)

Servo servo1;
Servo servo2;
unsigned long indexServo1 = 0;
unsigned long indexServo2 = 0;
unsigned long restServo1 = 0;
unsigned long restServo2 = 0;

const PROGMEM int32_t times1[] = {
    0, -1000, 2000, -3000
};
const PROGMEM int32_t times2[] = {
    500, 2500 
};

void setup() {
    pinMode(SERVO1, OUTPUT);
    pinMode(SERVO2, OUTPUT);
    servo1.attach(SERVO1);
    servo2.attach(SERVO2);
    delay(1000);
}

void loop() {

    unsigned long now = millis();

    // Plays a note
    int32_t time1 = pgm_read_dword(times1 + indexServo1);
    if(now > abs(time1)) {
         servo1.write(time1 > 0 ? S1_UP : S1_DOWN);
         restServo1 = now + MOVEMENT_TIME;
         indexServo1 += 1;
    }
    int32_t time2 = pgm_read_dword(times2 + indexServo2);
    if(now > abs(time2)) {
         servo2.write(time2 > 0 ? S2_UP : S2_DOWN);
         restServo2 = now + MOVEMENT_TIME;
         indexServo2 += 1;
    }

    // Returns to middle position
    if(restServo1 != 0 && now > restServo1) {
        servo1.write(S1_MID);
        restServo1 = 0;
    }
    if(restServo2 != 0 && now > restServo2) {
        servo2.write(S2_MID);
        restServo2 = 0;
    }
}
