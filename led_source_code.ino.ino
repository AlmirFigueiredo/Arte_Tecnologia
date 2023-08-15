#define echoPin1 2
#define trigPin1 3
#define echoPin2 4
#define trigPin2 5

long duration;
int distance;

int led6 = 6;
int led7 = 7;


int currentTime = 0;
int oldTimeSensorOne = 0;
int oldTimeSensorTwo = 0;


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
  Serial.println("Ultrasonic Sensor 2 HC-SR04 Test");
  Serial.println("with Arduino UNO R3");
}



void setup() {
  // put your setup code here, to run once:
  ultraSonicSensor1Setup();
  ultraSonicSensor2Setup();
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop() {
  currentTime = millis();
  
  // put your main code here, to run repeatedly:
  if(distFromUSS1() <= 150) {
    digitalWrite(led6, HIGH);
    Serial.println("LED6 Ligado");
    oldTimeSensorOne = millis();
  }else if((currentTime - oldTimeSensorOne) > 2){
    digitalWrite(led6, LOW);
    Serial.println("Led6 desligado");
  }

  if(distFromUSS2() <= 150) {
    digitalWrite(led7, HIGH);
    Serial.println("Led7 ligado");   
    oldTimeSensorTwo = millis();
  }else if((currentTime - oldTimeSensorTwo) > 2){
    digitalWrite(led7, LOW);
    Serial.println("Led7 desligado"); 
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
