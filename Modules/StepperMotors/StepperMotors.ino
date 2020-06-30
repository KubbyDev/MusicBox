// Step pin of each motor driver
#define M1 3
#define M2 4
#define M3 5

#define A4 4489 // LA
#define A4d 4239 // LA#
#define B4 4001 // SI

#define C4 3778 // DO
#define C4d 3567 // DO#
#define D4 3363 // RE
#define D4d 3175 // RE#
#define E4 2995 // MI
#define F4 2825 // FA
#define F4d 2674 // FA#
#define G4 2515 // SOL
#define G4d 2375 // SOL#
#define A5 2243 // LA
#define A5d 2112 // LA#
#define B5 1996 // SI

#define C5 1886 // DO
#define C5d 1776 // DO#
#define D5 1678 // RE
#define D5d 1584 // RE#
#define E5 1495 // MI
#define F5 1409 // FA
#define F5d 1328 // FA#
#define G5 1252 // SOL
#define G5d 1182 // SOL#
#define A6 1116 // LA
#define A6d 1053 // LA#
#define B6 993 // SI

#define C6 936 // DO

int notes1[] = {
    0, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    0, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    0, 
    C5, D5, E5, F5, G5, A6, B6, C6, 
    0,
    C5, D5, E5, F5, G5, A6, B6, C6, 
    0
};
int durations1[] = {
    1000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    8000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    1000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    8000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    30000
};

int notes2[] = {
    0, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    0, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    0, 
    C5, D5, E5, F5, G5, A6, B6, C6, 
    0,
    C5, D5, E5, F5, G5, A6, B6, C6, 
    0
};
int durations2[] = {
    5000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    4000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    5000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    4000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    30000
};

int notes3[] = {
    0, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    C4, D4, E4, F4, G4, A5, B5, C5, 
    0, 
    C5, D5, E5, F5, G5, A6, B6, C6, 
    C5, D5, E5, F5, G5, A6, B6, C6, 
    0
};
int durations3[] = {
    9000, 
    500, 500, 500, 500, 500, 500, 500, 500,
    500, 500, 500, 500, 500, 500, 500, 500, 
    9000, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    500, 500, 500, 500, 500, 500, 500, 500, 
    30000
};

void setup() {
}

struct Motor {
    int* notes;
    int* durations;
    int stepPin;
    // Index of the note currently played
    int index;
    // Time before the next rise of the STEP pin
    // The value registered here is the given one -100 us
    // To ensure we have time for the low state
    int current;
    // Saves the state of the STEP pin
    bool stepHigh;
    // Moment the motor need to switch to the next note
    unsigned long next;
};

void initMotor(struct Motor* m, int* notes, int* durations, int pin) {
    m->notes = notes;
    m->durations = durations;
    m->stepPin = pin;
    m->index = -1;
    m->current = 0;
    m->stepHigh = false;
    m->next = 0;
    pinMode(m->stepPin, OUTPUT);
    digitalWrite(m->stepPin, LOW);
}

void loop() {    
    
    struct Motor motors[3];
    initMotor(motors+0, notes1, durations1, M1);
    initMotor(motors+1, notes2, durations2, M2);
    initMotor(motors+2, notes3, durations3, M3);

    unsigned long lastUpdate = micros();
    while(1) {
                
        unsigned long t = micros();
        unsigned long delta = t - lastUpdate;
        lastUpdate = t;

        for(int i = 0; i < 3; i++) 
            motors[i].current -= delta;

        // Goes low for the last 100 us of the oscillation
        for(int i = 0; i < 3; i++) {
            if(motors[i].current < 0 && motors[i].stepHigh) {
                motors[i].stepHigh = false;
                digitalWrite(motors[i].stepPin, LOW);
            }
        }

        // When the low state has ended, goes to the next oscillation (and note if necessary)
        for(int i = 0; i < 3; i++) {
            if(motors[i].current < -95) {
                // If the duration is over: next note
                if(t > motors[i].next) {
                    motors[i].index++;
                    motors[i].next = t + 1000UL*((motors[i].durations)[motors[i].index]); // The next note change moment
                }
                // Starts a new oscillation
                int note = (motors[i].notes)[motors[i].index];
                // Starts the oscillation if the note is not 0
                if(note) {
                    motors[i].stepHigh = true;
                    digitalWrite(motors[i].stepPin, HIGH);
                }
                // Makes the fake oscillation last 1 ms if the note is 0
                else 
                    note = 1000;  
                motors[i].current += note; // note - 100 - (overtime on last oscillation)
            }
        }
    }
}
