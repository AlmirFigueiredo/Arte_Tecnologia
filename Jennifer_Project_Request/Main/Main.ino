#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//Define pins for the components:
const int trigPins[] = {2, 3, 4, 5};
const int echoPins[] = {6, 7, 8, 9};
const int numSensors = 4;
const int ledPins[] = {10, 11, 12, 13};

//Criar objetos das bibliotecas do som:
DFRobotDFPlayerMini dPlayers[numSensors];
SoftwareSerial mySofwareSerial[numSensors];


