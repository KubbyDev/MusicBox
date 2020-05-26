#include <Servo.h>

#define SERVO_PIN 9
#define SERVO_REST 0
#define SERVO_BEAT 60

Servo servo;

void play(int durationMS) {
    servo.write(SERVO_BEAT);
    delay(durationMS/2);
    servo.write(SERVO_REST);
    delay(durationMS/2);
}

void setup() {
    servo.attach(SERVO_PIN);
}

void loop() {
    for(int i = 0; i < 3; i++) play(250);
    play(500);
    play(250);
    play(500);
}
