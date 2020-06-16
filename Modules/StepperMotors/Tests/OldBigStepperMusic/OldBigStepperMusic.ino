#include <Stepper.h>

#define STEPS 200

// Used this website for this: https://tuner.ninja/
// The highest notes didn't show up (don't know why)
// so I had to do them with the hear
#define B_SOL 236
#define B_LA 264
#define B_SI 298
#define DO 315
#define RE 355
#define MI 398
#define FA 422
#define SOL 470
#define LA 525
#define SI 585
#define A_DO 620

Stepper motor(STEPS, 8, 10, 9, 11); // The order is not an error (the library has its parameters unordered)

void setup() {
    Serial.begin(9600);
}

void loop() {    
    auclairdelalune();
}

int getint() {
    
    char inChar = 0;
    String inString;

    while (inChar != '\n') {
        while(Serial.available() <= 0)
            delay(1);
        inChar = Serial.read();
        inString += inChar;
    }

    Serial.flush();
    return inString.toInt();
}

// This function helps finding the notes associated with each speed (using this https://tuner.ninja/)
void tune() {
    Serial.println("Waiting for an int");
    int speed = getint();
    Serial.println(speed);
    motor.setSpeed(speed);
    motor.step((long)speed*STEPS/30); // Turns for 2 seconds
}

void play(int note, int duration) {
    motor.setSpeed(note);
    motor.step((long)STEPS*note*duration/(60L*1000L));
}

void doremifasollasido() {
    play(DO, 333);
    play(RE, 333);
    play(MI, 333);
    play(FA, 333);
    play(SOL, 333);
    play(LA, 333);
    play(SI, 333);
    play(A_DO, 333);
}

void auclairdelalune() {
    play(SOL, 200);
    delay(100);
    play(SOL, 200);
    delay(100);
    play(SOL, 200);
    delay(100);
    play(LA, 200);
    delay(100);
    play(SI, 400);
    delay(100);
    play(LA, 400);
    delay(100);
    play(SOL, 200);
    delay(100);
    play(SI, 200);
    delay(100);
    play(LA, 200);
    delay(100);
    play(LA, 200);
    delay(100);
    play(SOL, 400);
    delay(100);
}
