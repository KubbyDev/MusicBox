#include <Servo.h>

#define NB_LASERS 12
#define NB_SERVOS 6
#define SERVO_LEFT 120
#define SERVO_RIGHT 60
#define SERVO_MID 90
#define SPEAKER_PIN 51
#define THRESHOLD 955 // Below that threshold the laser is considered to be cut

const int SERVO_PINS[NB_SERVOS] = {2,3,4,5,6,7};
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
const PROGMEM uint16_t notesHarp[] = { 0, 64, 71, 64, 69, 64, 68, 64, 61, 0, 64, 71, 64, 69, 64, 68, 64, 0, 57, 0, 64, 71, 64, 69, 64, 68, 64, 0, 64, 71, 64, 69, 68, 64, 66, 64, 0, 64, 71, 64, 69, 64, 68, 64, 61, 0, 64, 71, 64, 69, 64, 68, 64, 57, 0, 64, 71, 64, 69, 64, 68, 64, 0, 64, 71, 64, 69, 68, 0, 64, 66, 64, 0, 59, 0, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 63, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 59, 0, 59, 0, 64, 0, 64, 0, 59, 64, 0, 64, 0, 59, 64, 0, 64, 63, 61, 63, 0, 64, 0, 64, 0, 64, 69, 68, 66, 64, 0, 64, 59, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 0, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 59, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0, 71, 69, 68, 0, 66, 63, 64, 66, 61, 0, 71, 69, 68, 0, 64, 0, 64, 66, 68, 64, 0, 64, 71, 64, 69, 64, 68, 64, 61, 0, 64, 71, 64, 69, 64, 68, 64, 0, 57, 0, 64, 71, 64, 69, 64, 0, 68, 64, 0, 64, 71, 64, 69, 68, 64, 66, 0, 64 }; 
const PROGMEM uint32_t timesHarp[] = { 0, 216, 442, 670, 898, 1125, 1351, 1579, 1802, 2020, 2033, 2260, 2488, 2716, 2942, 3170, 3398, 3625, 3631, 3841, 3851, 4079, 4306, 4532, 4759, 4987, 5215, 5431, 5669, 5897, 6123, 6350, 6578, 6806, 7032, 7246, 7451, 7474, 7715, 7941, 8169, 8397, 8623, 8850, 9076, 9292, 9306, 9532, 9759, 9987, 10215, 10441, 10669, 10895, 11103, 11123, 11350, 11578, 11806, 12032, 12259, 12487, 12705, 12941, 13169, 13397, 13623, 13850, 14078, 14094, 14306, 14513, 14728, 14774, 14974, 15015, 15206, 15241, 15679, 15708, 15951, 16169, 16179, 16587, 16633, 16861, 17077, 17087, 17542, 17770, 17996, 18405, 18451, 18679, 18895, 18905, 19314, 19361, 19587, 19804, 19814, 20223, 20270, 20496, 20713, 20723, 21179, 21633, 21895, 22054, 22087, 22294, 22314, 22532, 22542, 22951, 22996, 23223, 23441, 23451, 23861, 23905, 24133, 24351, 24361, 24814, 25042, 25270, 25883, 25951, 26169, 26179, 27601, 27770, 27996, 28451, 28905, 29361, 29577, 29587, 30042, 30280, 30496, 30951, 31179, 31587, 31633, 32314, 32542, 32996, 33451, 34133, 34587, 34814, 35223, 35270, 35941, 35951, 36179, 36633, 37087, 37701, 37770, 38223, 38451, 38861, 38905, 39587, 39814, 40270, 40723, 41337, 41405, 41861, 42087, 42496, 42542, 43213, 43223, 43451, 43905, 44361, 44587, 44826, 45042, 45496, 45723, 46133, 46179, 46861, 47087, 47542, 47996, 48679, 49133, 49361, 49770, 49814, 50486, 50496, 50723, 51179, 51633, 52246, 52314, 52770, 52996, 53405, 53451, 54133, 54361, 54814, 55270, 55883, 55951, 56405, 56633, 57042, 57087, 57760, 57770, 57996, 58451, 58905, 60941, 61157, 61384, 61612, 61840, 62066, 62293, 62521, 62748, 62935, 62975, 63203, 63430, 63657, 63884, 64112, 64340, 64566, 64601, 64780, 64793, 65021, 65248, 65475, 65701, 65929, 65930, 66143, 66359, 66619, 66846, 67074, 67300, 67527, 67755, 67983, 68209, 68221 };

int currentOctave = 4;
int octaveUpPressed = 0;
int octaveDownPressed = 0;
int index = 0;

void setup() {
    
    Serial.begin(115200);
    
    // Servos
    for(unsigned int i = 0; i < sizeof(SERVO_PINS)/sizeof(int); i++) {
        int pin = SERVO_PINS[i];
        pinMode(pin, OUTPUT);
        servos[i].attach(pin);
        servos[i].write(SERVO_MID);
    }
    // Photoresistors
    for(unsigned int i = 0; i < sizeof(RESISTOR_PINS)/sizeof(int); i++)
        pinMode(RESISTOR_PINS[i], INPUT);
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
    //controlLoop();
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
    while(res >= 0 && analogRead(RESISTOR_PINS[res]) < THRESHOLD)
        res--;
    //Serial.println(res);
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

    delay(50);
    
    for(int i = 0; i < 12; i++)
        Serial.println(analogRead(RESISTOR_PINS[i]));
    
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
