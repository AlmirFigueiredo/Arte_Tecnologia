// Define the pins for the ultrasonic sensors
#define TRIG_PIN1 2
#define ECHO_PIN1 3
#define TRIG_PIN2 4
#define ECHO_PIN2 5
#define TRIG_PIN3 6
#define ECHO_PIN3 7

void setup() {
  Serial.begin(9600);  
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
}

void loop() {
  float distanceA = getDistance(TRIG_PIN1, ECHO_PIN1);
  float distanceB = getDistance(TRIG_PIN2, ECHO_PIN2);
  float distanceC = getDistance(TRIG_PIN3, ECHO_PIN3);
  
  String output = "";

  if (distanceA < 45) {
    output += "A";
  }

  if (distanceB < 45) {
    output += "B";
  }

  if (distanceC < 45) {
    output += "C";
  }
  
  if (output != "") {
    Serial.println(output);
  } else {
    Serial.println("No sensors within 45cm");
  }
  
  delay(1000); 
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  
  return distance;
}
