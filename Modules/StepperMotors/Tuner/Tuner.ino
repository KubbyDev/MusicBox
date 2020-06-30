// This script can be used to find the values of the delay 
// for each note for the stepper motors
// This site is pretty good to find the right value for each note: https://www.flutetunes.com/tuner/

#define STEP_PIN 3

#define UP_PIN 6
#define DOWN_PIN 7
#define NEXT_PIN 5

#define START 1886
#define OCTAVE 6 // The number of the octave (used for the final display)

void setup() {
    
    pinMode(UP_PIN, INPUT);
    pinMode(DOWN_PIN, INPUT);
    pinMode(NEXT_PIN, INPUT);
    pinMode(STEP_PIN, OUTPUT);
    Serial.begin(115200);

    Serial.println("Ready!");

    int delays[13];
    delays[0] = START;

    int index = 0; // The next array spot to write
    for(int note = 0; note < 7; note++) {
        // Gets the note
        getnote(delays+index);
        // Prepares the next note
        delays[index+1] = delays[index] - 30;
        index++;
        // Gets the # of this note if it exists
        if(note != 2 && note != 6) { // All except MI and SI (E and B)
            getnote(delays+index);
            // Prepares the next note
            delays[index+1] = delays[index] - 30;
            index++;
        }
    }

    // Gets the final DO
    getnote(delays+index);

    Serial.println("Results: \n");
    displayResults(delays);
}

void loop() {
}

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
            // Or if there has already been more than 20 updates (one second)
            if(up == 0 || up > 20)  {
                *note -= 1;
                Serial.println(*note);
            }
            up += 1;
        }
        else up = 0;
        
        if(digitalRead(DOWN_PIN) == HIGH) {
            if(down == 0 || down > 20) {
                *note += 1;
                Serial.println(*note);
            }
            down += 1;
        }
        else down = 0;

        // Plays the note for 50 ms
        play(*note, 50);    
    }

    // Waits for the NEXT button to be released
    while(digitalRead(NEXT_PIN) == HIGH)
        delay(50);
}

String englishToLatin(char english, bool sharp) {
    String note;
    switch (english) {
        case 'C': note = "DO"; break;
        case 'D': note = "RE"; break;
        case 'E': note = "MI"; break;
        case 'F': note = "FA"; break;
        case 'G': note = "SOL"; break;
        case 'A': note = "LA"; break;
        case 'B': note = "SI"; break;
        default: return "ERR"; break;
    }
    if(sharp)
        note += "#";
    return note;
}

void displayResults(int* results) {
    
    char* notes[] = { "C_", "C_d", "D_", "D_d", "E_", "F_", "F_d", "G_", "G_d", "A_", "A_d", "B_", "XX" };

    // The last note was the same string as the first one so the compiler optimized it :(
    notes[12][0] = 'C';
    notes[12][1] = '_';

    // Puts the octave number in the middle of each string
    for(int i = 0; i < 13; i++)
        notes[i][1] = OCTAVE + '0' + (i > 8 ? 1 : 0);
                
    for(int i = 0; i < 13; i++) {
        Serial.print("#define ");
        Serial.print(notes[i]);
        Serial.print(" ");
        Serial.print(results[i]);
        Serial.print(" // ");
        Serial.print(englishToLatin(notes[i][0], notes[i][2] == '#'));
        Serial.println();
    }
}
