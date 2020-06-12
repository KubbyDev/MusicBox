#include <Stepper.h>

#define STEPS_PER_REV 32
#define GEAR_RED 64
#define STEPS_PER_OUT_REV STEPS_PER_REV*GEAR_RED

int stepsRequired;
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11); // The order is not an error (the library has its parameters unordered)

void setup() {
    Serial.begin(9600);
}

void loop() {
    motor.setSpeed(100);
    motor.step(1000);
}
