#define STEP_PIN 3 
 
void setup() {
    pinMode(STEP_PIN,OUTPUT); 
}

void loop() {
    for(int i = 100000; i < 20000; i -= 10) {
        for(int j = 0; j < 500000/(2*i); j++) {
            digitalWrite(STEP_PIN, HIGH); 
            delayMicroseconds(i); 
            digitalWrite(STEP_PIN, LOW); 
            delayMicroseconds(i); 
        }
    }
    delay(1000);
}
