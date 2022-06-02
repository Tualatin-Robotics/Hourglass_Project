#include <Servo.h> 

Servo hourglass_servo;
bool toggle = false;
int button = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  hourglass_servo.attach(13);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (toggle = true) {
    hourglass_servo.write(180);
    digitalWrite(13, HIGH);
  }
  if (toggle = false) {
    digitalWrite(13, HIGH);
  }
  for (int i = 0; i < 450; i++) {
    button = digitalRead(3);
    if (button = HIGH) {
      toggle = !toggle;
    }
    delay(100);
  }
}
