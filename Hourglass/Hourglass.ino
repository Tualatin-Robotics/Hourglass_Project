#include <Servo.h> 

Servo servo;
bool toggle = false;
int button = 0;
int pos = 0;

int servoPin = 11;
int ledPin = 12;
int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (toggle == true) {
    pos = servo.read();
    if (pos = 180) {
      servo.write(0);
    } else {
      servo.write(180);
    }
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  for (int i = 0; i < 450; i++) {
    button = digitalRead(buttonPin);
    if (button == HIGH) {
      toggle = !toggle;
      break;
    }
    delay(100);
  }
}
