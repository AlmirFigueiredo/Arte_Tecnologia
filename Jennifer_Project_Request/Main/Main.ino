#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//Define pins for the components:
const int trigPins[] = {2, 3, 4, 5};
const int echoPins[] = {6, 7, 8, 9};
const int numSensors = 4;
const int ledPins[] = {10, 11, 12, 13};

const int txPins[] = {A0, A1, 14, 15};
const int rxPins[] = {A2, A3, A4, A5};

//Criar objetos das bibliotecas do som:
DFRobotDFPlayerMini dPlayers[numSensors];
SoftwareSerial mySofwareSerial[numSensors];

void setup() {
    Serial.begin(9600);
    for(int i = 0; i < numSensors; i++) {
        pinMode(trigPins[i], OUTPUT);
        pinMode(echoPins[i], INPUT);
        pinMode(ledPins[i], OUTPUT);

        digitalWrite(trigPins[i], LOW);
        digitalWrite(ledPins[i], LOW);

        mySofwareSerial[i] = SoftwareSerial(rxPins[i], txPins[i]);
        mySofwareSerial[i].begin(9600);
        dPlayers[i].begin(mySofwareSerial[i]);

        //Volume (Vou considerar que 20 e um bom numero):
        dPlayers[i].volume(20);
    }
}


