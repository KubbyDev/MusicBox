// I tried using an old industrial stepper motor found in my fathers garage

#include <Stepper.h>

#define STEPS_PER_REV 200
#define GEAR_RED 1
#define STEPS_PER_OUT_REV STEPS_PER_REV*GEAR_RED

int stepsRequired;
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11); // The order is not an error (the library has its parameters unordered)

void setup() {
    Serial.begin(9600);
}

void loop() {
    for(int i = 1; i < 600; i++) {
        motor.setSpeed(i);
        motor.step(STEPS_PER_OUT_REV*i/600); // Turns for 0.1 seconds
    }
}
