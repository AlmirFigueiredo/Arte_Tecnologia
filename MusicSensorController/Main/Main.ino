const int trigPinUS1 = 1;
const int echoPinUS1 = 2;

long duration;
int distance;

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
int calculateDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    return duration * 0.034 / 2;
}
void loop() {
    int distanceUS1 = calculateDistance(trigPinUS1, echoPinUS1);
    

    Serial.println(distance);
    delay(1000);
}
