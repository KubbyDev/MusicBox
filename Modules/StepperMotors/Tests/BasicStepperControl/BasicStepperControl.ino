// This is my first attempt at controlling a stepper motor
// The motor I used is the 28BYJ-48

#include <Stepper.h>

#define STEPS_PER_REV 32
#define GEAR_RED 64
#define STEPS_PER_OUT_REV STEPS_PER_REV*GEAR_RED

int stepsRequired;
Stepper motor(STEPS_PER_REV, 8, 10, 9, 11); // The order is not an error

void setup() {
    Serial.begin(9600);
}

void loop() {
    motor.setSpeed(1000); // 1000 internal rpm = 16 rpm with the 64 reductor. Can't go higher :(
    motor.step(STEPS_PER_OUT_REV / 2); // Half a turn, blocking (~ 2 seconds)
    delay(1000);
}
