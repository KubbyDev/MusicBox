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
    pinMode(M1, OUTPUT);
    pinMode(M2, OUTPUT);    
    pinMode(M3, OUTPUT);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(M3, LOW);
}

void loop() {    

    Serial.begin(9600);
    
    // Index of the note currently played by each motor
    int index1 = -1; int index2 = -1; int index3 = -1;
    // Time before the next rise of the STEP pin
    // The value registered here is the given one -100 us
    // To ensure we have time for the low state
    int delay1 = 0; int delay2 = 0; int delay3 = 0;
    // Saves the state of the STEP pin
    bool step1 = false; bool step2 = false; bool step3 = false;
    // Moment the motor need to switch to the next note
    unsigned long next1 = 0; unsigned long next2 = 0; unsigned long next3 = 0;

    unsigned long lastUpdate = micros();
    while(1) {
                
        unsigned long t = micros();
        unsigned long delta = t - lastUpdate;
        lastUpdate = t;

        delay1 -= delta;
        delay2 -= delta;
        delay3 -= delta;

        // Goes low for the last 100 us of the oscillation
        if(delay1 < 0 && step1) {
            step1 = false;
            digitalWrite(M1, LOW);
        }
        if(delay2 < 0 && step2) {
            step2 = false;
            digitalWrite(M2, LOW);
        }
        if(delay3 < 0 && step3) {
            step3 = false;
            digitalWrite(M3, LOW);
        }

        // When the low state has ended, goes to the next oscillation (and note if necessary)
        if(delay1 < -95) {
            // If the duration is over: next note
            if(t > next1) {
                index1++;
                next1 = t + 1000UL*(durations1[index1]); // The next note change moment
            }
            // Starts a new oscillation
            int note = notes1[index1];
            // Starts the oscillation if the note is not 0
            if(note) {
                step1 = true;
                digitalWrite(M1, HIGH);
            }
            // Makes the fake oscillation last 1 ms if the note is 0
            else 
                note = 1000;  
            delay1 += note; // note - 100 - (overtime on last oscillation)
        }
        if(delay2 < -95) {
            if(t > next2) {
                index2++;
                next2 = t + 1000UL*(durations2[index2]);
            }
            int note = notes2[index2];
            if(note) {
                step2 = true;
                digitalWrite(M2, HIGH);
            }
            else 
                note = 1000;  
            delay2 += note;
        }
        if(delay3 < -95) {
            if(t > next3) {
                index3++;
                next3 = t + 1000UL*(durations3[index3]);
            }
            int note = notes3[index3];
            if(note) {
                step3 = true;
                digitalWrite(M3, HIGH);
            }
            else 
                note = 1000;  
            delay3 += note;
        }
    }
}
