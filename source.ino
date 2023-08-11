#define ECHO_A 2
#define ECHO_B 3
#define ECHO_C 4

#define TRIG_A 5
#define TRIG_B 6
#define TRIG_C 7

void setup() {
    pinMode(ECHO_A, INPUT);
    pinMode(ECHO_B, INPUT);
    pinMode(ECHO_C, INPUT);

    pinMode(TRIG_A, OUTPUT);
    pinMode(TRIG_B, OUTPUT);
    pinMode(TRIG_C, OUTPUT);

    Serial.begin(9600);
}

float measureDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    
    float distance = (duration * 0.0343) / 2;
    
    return distance;
}

void loop() {
    float distanceA = measureDistance(TRIG_A, ECHO_A);
    float distanceB = measureDistance(TRIG_B, ECHO_B);
    float distanceC = measureDistance(TRIG_C, ECHO_C);

    // Envia as distâncias separadas por vírgulas e termina com uma nova linha
    Serial.print(distanceA);
    Serial.print(",");
    Serial.print(distanceB);
    Serial.print(",");
    Serial.println(distanceC);

    delay(1000); 
}
