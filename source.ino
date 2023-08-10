

#define ECHO_A 2
#define ECHO_B 3
#define ECHO_C 4

#define TRIG_A 5
#define TRIG_B 6
#define TRIG_C 7

#define LED_A 8
#define LED_B 9
#define LED_C 10

void setup() {
    pinMode(ECHO_A, INPUT);
    pinMode(ECHO_B, INPUT);
    pinMode(ECHO_C, INPUT);

    pinMode(TRIG_A, OUTPUT);
    pinMode(TRIG_B, OUTPUT);
    pinMode(TRIG_C, OUTPUT);

    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);

    Serial.begin(9600);
}
