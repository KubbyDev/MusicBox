// Step pin of each motor driver
#define M1 3
#define M2 4
#define M3 5

#define C4  3768 // DO
#define C4d 3557 // DO#
#define D4  3355 // RE
#define D4d 3171 // RE#
#define E4  2989 // MI
#define F4  2821 // FA
#define F4d 2660 // FA#
#define G4  2511 // SOL
#define G4d 2365 // SOL#
#define A5  2236 // LA
#define A5d 2106 // LA#
#define B5  1992 // SI
#define C5  1879 // DO

int notes1[] = {
    0, C4, D4, E4, F4, G4, A5, B5, C5, 0, C4, D4, E4, F4, G4, A5, B5, C5, 0
};
int durations1[] = {
    1000, 500, 500, 500, 500, 500, 500, 500, 500, 8000, 500, 500, 500, 500, 500, 500, 500, 500, 30000
};

int notes2[] = {
    0, C4, D4, E4, F4, G4, A5, B5, C5, 0, C4, D4, E4, F4, G4, A5, B5, C5, 0
};
int durations2[] = {
    5000, 500, 500, 500, 500, 500, 500, 500, 500, 4000, 500, 500, 500, 500, 500, 500, 500, 500, 30000
};

int notes3[] = {
    0, C4, D4, E4, F4, G4, A5, B5, C5, C4, D4, E4, F4, G4, A5, B5, C5, 0
};
int durations3[] = {
    9000, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 30000
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
