const int triggerPins[6] = {2, 3, 4, 5, 6, 7};
const int echoPins[6] = {8, 9, 10, 11, 12, 13};
float distances[6];

void setup() {
    Serial.begin(9600);
    for(int i = 0; i < 6; i++) {
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
    return (duration(*0.034/2));
}


