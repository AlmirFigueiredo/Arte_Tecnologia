#define echoPin1 11
#define trigPin1 10
#define echoPin2 6
#define trigPin2 5

long duration;
int distance;

int led1 = 3;
int led2 = 2;
int led3 = 4;

void ultraSonicSensor1Setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin1, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor 1 HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}

void ultraSonicSensor2Setup() {
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor 2 HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void setup() {
  ultraSonicSensor1Setup();
  ultraSonicSensor2Setup();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if(distFromUSS1() <= 5) {
    delay(1000);
    if(distFromUSS2() <= 5) {
      digitalWrite(led1, HIGH);
      delay(2000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(2000);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(2000);
      digitalWrite(led3, LOW);
    }
  }

  if(distFromUSS2() <= 5) {
    delay(1000);
    if(distFromUSS1() <= 5) {
      digitalWrite(led3, HIGH);
      delay(2000);
      digitalWrite(led3, LOW);
      digitalWrite(led2, HIGH);
      delay(2000);
      digitalWrite(led2, LOW);
      digitalWrite(led1, HIGH);
      delay(2000);
      digitalWrite(led1, LOW);
    }
  }

}

int distFromUSS1() {
  // Clears the trigPin condition
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

int distFromUSS2() {
  // Clears the trigPin condition
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}