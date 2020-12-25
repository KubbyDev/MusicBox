#include <Servo.h>

#define NB_LASERS 12
#define NB_SERVOS 6
#define SERVO_LEFT 140
#define SERVO_RIGHT 40
#define SERVO_MID 90
#define SPEAKER_PIN 51

// For a laser to be cut, its tension value must be greater than
// its base value + THRESHOLD_PROP*(1024 - base_value)
#define THRESHOLD_PROP 0.25

const int SERVO_PINS[NB_SERVOS] = {30,32,34,36,38,40};
const int RESISTOR_PINS[NB_LASERS] = {A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12};
const int LED_PINS[8] = {24,25,26,27,28,29,30,31};
Servo servos[NB_SERVOS];
#define OCTAVE_UP 32
#define OCTAVE_DOWN 33

unsigned int frequencies[8][12] = {
    { /*C1*/33,/*C#1*/35,/*D1*/37,/*D#1*/39,/*E1*/41,/*F1*/44,/*F#1*/46,/*G1*/49,/*G#1*/52,/*A1*/55,/*A#1*/58,/*B1*/62 },
    { /*C2*/65,/*C#2*/69,/*D2*/73,/*D#2*/78,/*E2*/82,/*F2*/87,/*F#2*/92,/*G2*/98,/*G#2*/104,/*A2*/110,/*A#2*/117,/*B2*/123 },
    { /*C3*/131,/*C#3*/139,/*D3*/147,/*D#3*/156,/*E3*/165,/*F3*/175,/*F#3*/185,/*G3*/196,/*G#3*/208,/*A3*/220,/*A#3*/233,/*B3*/247 },
    { /*C4*/262,/*C#4*/277,/*D4*/294,/*D#4*/311,/*E4*/330,/*F4*/349,/*F#4*/370,/*G4*/392,/*G#4*/415,/*A4*/440,/*A#4*/466,/*B4*/494 },
    { /*C5*/523,/*C#5*/554,/*D5*/587,/*D#5*/622,/*E5*/659,/*F5*/698,/*F#5*/740,/*G5*/784,/*G#5*/831,/*A5*/880,/*A#5*/932,/*B5*/988 },
    { /*C6*/1046,/*C#6*/1109,/*D6*/1175,/*D#6*/1244,/*E6*/1318,/*F6*/1397,/*F#6*/1480,/*G6*/1568,/*G#6*/1661,/*A6*/1760,/*A#6*/1865,/*B6*/1976 },
    { /*C7*/2093,/*C#7*/2218,/*D7*/2349,/*D#7*/2489,/*E7*/2637,/*F7*/2794,/*F#7*/2960,/*G7*/3136,/*G#7*/3322,/*A7*/3520,/*A#7*/3729,/*B7*/3951 },
    { /*C8*/4186,/*C#8*/4435,/*D8*/4699,/*D#8*/4978,/*E8*/5274,/*F8*/5587,/*F#8*/5920,/*G8*/6272,/*G#8*/6644,/*A8*/7040,/*A#8*/7459,/*B8*/7903 }
};

// The notes are encoded as midi pitches
const PROGMEM uint16_t notesHarp[] = { 0, 64, 0, 64, 71, 64, 69, 64, 68, 64, 0, 59, 0, 64, 71, 64, 69, 64, 68, 64, 0, 61, 64, 71, 64, 69, 64, 68, 64, 0, 57, 0, 64, 71, 64, 69, 68, 64, 66, 64, 0, 64, 71, 64, 69, 64, 68, 64, 0, 59, 64, 71, 64, 69, 64, 68, 64, 0, 61, 64, 71, 64, 69, 64, 68, 64, 0, 57, 64, 71, 64, 69, 68, 0, 64, 66, 64, 0, 59, 0, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 63, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 59, 0, 59, 0, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 63, 0, 64, 0, 64, 0, 64, 69, 68, 66, 64, 0, 64, 59, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 0, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 59, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 0, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0 };
const PROGMEM uint32_t timesHarp[] = { 0, 398, 615, 638, 866, 1093, 1320, 1547, 1775, 2002, 2229, 2231, 2449, 2456, 2684, 2911, 3138, 3366, 3593, 3820, 4047, 4068, 4275, 4502, 4728, 4955, 5183, 5409, 5637, 5865, 5870, 6086, 6092, 6319, 6546, 6774, 7001, 7228, 7455, 7669, 7874, 7898, 8137, 8365, 8592, 8819, 9046, 9274, 9501, 9523, 9728, 9955, 10183, 10409, 10637, 10865, 11092, 11319, 11343, 11546, 11774, 12001, 12228, 12455, 12683, 12909, 13137, 13168, 13365, 13592, 13819, 14046, 14274, 14501, 14516, 14728, 14937, 15152, 15197, 15398, 15438, 15628, 15665, 16101, 16132, 16373, 16591, 16601, 17010, 17056, 17283, 17500, 17510, 17965, 18192, 18419, 18829, 18873, 19101, 19319, 19329, 19738, 19783, 20010, 20228, 20238, 20647, 20692, 20919, 21137, 21147, 21601, 22056, 22317, 22478, 22510, 22718, 22738, 22955, 22965, 23373, 23419, 23647, 23863, 23873, 24283, 24329, 24556, 24773, 24783, 25238, 25465, 25692, 26306, 26373, 26591, 26601, 28023, 28192, 28419, 28873, 29329, 29783, 30000, 30010, 30465, 30704, 30919, 31373, 31601, 32010, 32056, 32738, 32965, 33419, 33873, 34556, 35010, 35238, 35647, 35692, 36363, 36373, 36601, 37056, 37510, 38123, 38192, 38647, 38873, 39283, 39329, 40010, 40238, 40692, 41147, 41760, 41829, 42283, 42510, 42919, 42965, 43637, 43647, 43873, 44329, 44783, 45010, 45248, 45465, 45919, 46147, 46556, 46601, 47283, 47510, 47965, 48419, 49101, 49556, 49783, 50192, 50238, 50909, 50919, 51147, 51601, 52056, 52669, 52738, 53192, 53419, 53829, 53873, 54556, 54783, 55238, 55692, 56306, 56373, 56829, 57056, 57465, 57510, 58182, 58192, 58419, 58873, 59329, 59500 };

int currentOctave = 4;
int octaveUpPressed = 0;
int octaveDownPressed = 0;
int index = 0;

int thresholds[NB_LASERS];

void setup() {

    delay(2000);
    
    Serial.begin(115200);
    
    // Servos
    for(unsigned int i = 0; i < sizeof(SERVO_PINS)/sizeof(int); i++) {
        int pin = SERVO_PINS[i];
        pinMode(pin, OUTPUT);
        servos[i].attach(pin);
        servos[i].write(SERVO_MID);
    }
    delay(50);
    // Photoresistors
    for(unsigned int i = 0; i < sizeof(RESISTOR_PINS)/sizeof(int); i++) {
        pinMode(RESISTOR_PINS[i], INPUT);
        int base_value = 0;
        for(int j = 0; j < 3; j++) {
          base_value += analogRead(RESISTOR_PINS[i]);
          delay(10);
        }
        base_value /= 3;
        thresholds[i] = THRESHOLD_PROP * (1024 - base_value) + base_value;
        Serial.print("Threshold ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(thresholds[i]);
    }
    // Leds
    for(unsigned int i = 0; i < sizeof(LED_PINS)/sizeof(int); i++)
        pinMode(LED_PINS[i], OUTPUT);
    // Others
    pinMode(SPEAKER_PIN, OUTPUT);
    pinMode(OCTAVE_UP, INPUT);
    pinMode(OCTAVE_DOWN, INPUT);

    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

    long m = millis();

    while(millis() - m < 50)
      controlLoop();
    
    harpLoop();
}

// Changes the currently selected octave. Can be called
// by the control loop or by the harp loop (buttons)
void changeOctave(int octave) {
    for(int i = 1; i <= 8; i++)
        digitalWrite(LED_PINS[i-1], i == octave);
    currentOctave = octave;
}

// Harp section -----------------------------------------------------------------------

// Finds the laser that is being cut if there is one 
// Returns the index of the laser, -1 if no laser is cut
int findCutLaser() {
  
    int res = NB_LASERS-1;
    while(res >= 0 && analogRead(RESISTOR_PINS[res]) < thresholds[res])
        res--;
    return res;
}

// Plays the given note for 75 ms
void playNote(int note) {
    int oct = note/12 -1;
    int nte = note%12;
    int freq = frequencies[oct-1][nte];
    tone(SPEAKER_PIN,freq,75);
}

// Checks the octave control buttons and changes the current octave if necessary
void changeOctaveButtons() {
    
    if(!octaveUpPressed && digitalRead(OCTAVE_UP)) {
        changeOctave(currentOctave+1);
        octaveUpPressed = 1;
    }
    else octaveUpPressed = 0;
    
    if(!octaveDownPressed && digitalRead(OCTAVE_DOWN)) {
        changeOctave(currentOctave-1);
        octaveDownPressed = 1;
    }
    else octaveDownPressed = 0;
}

// Part of the loop function that handles the harp 
// (finding what laser is being cut and playing the appropriate sound)
void harpLoop() {
    
    for(int i = 0; i < 12; i++) {
        Serial.print(thresholds[i]);
        Serial.print(": ");
        Serial.println(analogRead(RESISTOR_PINS[i]));
    }
    
    int cutLaser = findCutLaser();
    if(cutLaser >= 0) {
        digitalWrite(LED_BUILTIN, HIGH);
        int note = 12*(currentOctave+1) + cutLaser;
        playNote(note);
    }
    else
        digitalWrite(LED_BUILTIN, LOW);

    Serial.println("-------------------------");
}

// Control section --------------------------------------------------------------------

void changeNote(int note) {

    int toUse = -1; // Index of the servo that will cut a laser
    
    if(note != 0) {
        changeOctave(note/12); // Changes the octave if there is a note to play
        toUse = (note%12)/2;
    }

    for(int i = 0; i < NB_SERVOS; i++) {
        if(i != toUse) {
            servos[i].write(SERVO_MID);
            continue;
        }
        servos[i].write(note%2 == 0 ? SERVO_RIGHT : SERVO_LEFT);
    }
}

void controlLoop() {
    
    unsigned long now = millis();
    
    if(now > pgm_read_dword(timesHarp + index)) {
        changeNote(pgm_read_word(notesHarp + index));
        index++;
    }
}
