// https://www.arduino.cc/en/tutorial/AnalogInput

#define R_PIN A0

void setup() {
    pinMode(R_PIN, INPUT);
    Serial.begin(115200);
}

void loop() {
    int val = analogRead(R_PIN);
    Serial.println(val);
    delay(100);
}

// Goes approximately from 100 to 800 when the laser is focused on the photoresistor
