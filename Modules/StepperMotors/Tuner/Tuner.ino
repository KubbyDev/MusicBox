// This script can be used to find the values of the delay 
// for each note for the stepper motors
// This site is pretty good to find the right value for each note: https://www.flutetunes.com/tuner/

#define STEP_PIN 3

#define UP_PIN 6
#define DOWN_PIN 7
#define NEXT_PIN 5

// Play function of the main program:
void play(int delayUS, int durationMS) {
    for(long i = 0; i < (durationMS*1000L)/delayUS; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(delayUS - 5);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(5);
    }
}

// This function plays the note, lets the user adjust it
// And returns when the user presses the next button
// The note parameter is the result and should be initialised to a hint note 
void getnote(int* note) {

    int up = 0;
    int down = 0;

    while(digitalRead(NEXT_PIN) == LOW) {

        // If the UP button is pressed
        if(digitalRead(UP_PIN) == HIGH) {

            // If it's the first update where the button is pressed
            // Or if there has already been more than 50 updates (one second)
            if(up == 0 || up > 50)  {
                *note -= 1;
                Serial.println(*note);
            }
            up += 1;
        }
        else up = 0;
        
        if(digitalRead(DOWN_PIN) == HIGH) {
            if(down == 0 || down > 50) {
                *note += 1;
                Serial.println(*note);
            }
            down += 1;
        }
        else down = 0;

        // Plays the note for 20 ms
        play(*note, 20);    
    }

    // Waits for the NEXT button to be released
    while(digitalRead(NEXT_PIN) == HIGH)
        delay(50);
}

String englishToLatin(char english) {
    switch (english) {
        case 'C': return "DO";
        case 'D': return "RE";
        case 'E': return "MI";
        case 'F': return "FA";
        case 'G': return "SOL";
        case 'A': return "LA";
        case 'B': return "SI";
        default: return "ERR";
    }
}

void displayResults(int* results) {
    
    int octave = 4;
    char note = 'C';
    
    for(int i = 0; i < 8; i++) {
        Serial.print("#define ");
        Serial.print(note);
        Serial.print(octave);
        Serial.print(" ");
        Serial.print(results[i]);
        Serial.print(" // ");
        Serial.print(englishToLatin(note));
        Serial.println();

        note += 1;
        if(note > 'G') {
            note = 'A';
            octave += 1;
        }
    }
}

void setup() {
    
    pinMode(UP_PIN, INPUT);
    pinMode(DOWN_PIN, INPUT);
    pinMode(NEXT_PIN, INPUT);
    pinMode(STEP_PIN, OUTPUT);
    Serial.begin(9600);

    Serial.println("Ready!");

    int delays[8];
    delays[0] = 1879;

    for(int i = 0; i < 8; i++) {
        getnote(delays+i);
        if(i < 7) delays[i+1] = delays[i] - 30;
    }

    Serial.println("Results: \n");
    displayResults(delays);
}

void loop() {
}
