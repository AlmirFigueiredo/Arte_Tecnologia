const int triggerPins[4] = {2, 4, 6};
const int echoPins[4] = {3, 5, 7};
float tempDistance;

void setup() {
    Serial.begin(9600);
    for(int i = 0; i < 4; i++) {
        pinMode(triggerPins[i], OUTPUT);
        pinMode(echoPins[i], INPUT);
    }
}

float getDistance(int triggerPin, int echoPin) {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    float duration = pulseIn(echoPin, HIGH);
    return (duration*(0.034/2));
}

void loop() {
    for(int i = 0; i < 3; i++) {
        tempDistance = getDistance(triggerPins[i], echoPins[i]);
        if(i < 2) {
            Serial.print(tempDistance, 2);
            Serial.print(",");
        } else {
            Serial.println(tempDistance, 2);
        }
    }
    delay(500);
}
