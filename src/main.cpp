#include <Arduino.h>
#include <Servo.h>

Servo ESC;
char readChar = '\n';
String readString = "";
int potValue = 0;

void setup() {
    Serial.begin(9600);
    ESC.attach(9, 1000, 2000); // 0, 2500
}

void loop() {
    if(Serial.available() > 0) {
        readChar = Serial.read();

        if(readChar == '\r') {
        } else if(readChar == '\n') {
            potValue = readString.toInt();
            readString = "";

            if (potValue < 0) {
                potValue = 0;
            } else if (potValue > 180) {
                potValue = 180;
            }

            Serial.println(potValue);
        } else {
            readString += readChar;
        }

    }

    ESC.write(potValue);
}
