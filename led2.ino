#define echoPin1 2
#define trigPin1 3
#define echoPin2 4
#define trigPin2 5

int led6 = 6;
int led7 = 7;

unsigned long currentTime = 0;
unsigned long oldTimeSensorOne = 0;
unsigned long oldTimeSensorTwo = 0;

void ultraSonicSensorSetup(int trigPin, int echoPin, const char* sensorName) {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  
  Serial.print("Ultrasonic Sensor ");
  Serial.print(sensorName);
  Serial.println(" HC-SR04 Test with Arduino UNO R3");
}

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baudrate
  
  ultraSonicSensorSetup(trigPin1, echoPin1, "1");
  ultraSonicSensorSetup(trigPin2, echoPin2, "2");
  
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop() {
  currentTime = millis();
  
  if(distFromUSS(trigPin1, echoPin1) <= 150) {
    digitalWrite(led6, HIGH);
    Serial.println("LED6 Ligado");
    oldTimeSensorOne = millis();
  } else if((currentTime - oldTimeSensorOne) > 2000){
    digitalWrite(led6, LOW);
    Serial.println("Led6 desligado");
  }

  if(distFromUSS(trigPin2, echoPin2) <= 150) {
    digitalWrite(led7, HIGH);
    Serial.println("LED7 Ligado");
    oldTimeSensorTwo = millis();
  } else if((currentTime - oldTimeSensorTwo) > 2000){
    digitalWrite(led7, LOW);
    Serial.println("Led7 desligado");
  }
}

int distFromUSS(int trigPin, int echoPin) {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}
