// I tried using an old industrial stepper motor found in my fathers garage

#include <Stepper.h>

#define STEPS_PER_REV 48
#define GEAR_RED 1
#define STEPS_PER_OUT_REV STEPS_PER_REV*GEAR_RED

int stepsRequired;
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11); // The order is not an error (the library has its parameters unordered)

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Can't go higher than 200 :(
    for(int i = 0; i < 200; i++) {
        motor.setSpeed(i);
        motor.step(STEPS_PER_OUT_REV*i/300); // Turns for 0.2 seconds
        delay(0.1);
    }
}
