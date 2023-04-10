const int trigPinUS1 = 1;
const int echoPinUS1 = 2;

const int trigPinUS2 = 3;
const int echoPinUS2 = 4;

const int trigPinUS3 = 5;
const int trigPinUS3 = 6;

const int trigPinUS4 = 7;
const int trigPinUS4 = 8;

long duration;
int distanceUS1, distanceUS2, distanceUS3, distanceUS4;

void setup() {
    Serial.begin(9600);
    pinMode(trigPinUS1, OUTPUT);
    pinMode(echoPinUS1, INPUT);
    pinMode(trigPinUS2, OUTPUT);
    pinMode(echoPinUS2, INPUT);
    pinMode(trigPinUS3, OUTPUT);
    pinMode(echoPinUS3, INPUT);
    pinMode(trigPinUS4, OUTPUT);
    pinMode(echoPinUS4, INPUT);
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
    int distanceUS2 = calculateDistance(trigPinUS2, echoPinUS2);
    int distanceUS3 = calculateDistance(trigPinUS3, echoPinUS3);
    int distanceUS4 = calculateDistance(trigPinUS4, echoPinUS4);

    
    Serial.println(distanceUS1);
    delay(1000);
}
