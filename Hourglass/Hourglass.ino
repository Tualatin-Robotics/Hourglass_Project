#include <Servo.h> 

Servo servo;
bool toggle = false;
int currentButton;
int previousButton;
int pos;

int servoPin = 11;
int ledPin = 12;
int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  servo.attach(servoPin);
  delay(500);
  servo.detach() ;
  currentButton = digitalRead(buttonPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (toggle == true) {
    digitalWrite(ledPin, HIGH);
    servo.attach(servoPin);
    pos = servo.read();
    if (pos == 180) {
      servo.write(0);
    } else {
      servo.write(180);
    }
    delay(500);
    servo.detach();
  } else {
    digitalWrite(ledPin, LOW);
  }

  for (int i = 0; i < 450; i++) {
    previousButton = currentButton;
    currentButton = digitalRead(buttonPin);
    if (previousButton == HIGH && currentButton == LOW) {
      toggle = !toggle;
      break;
    }
    delay(100);
  }
}