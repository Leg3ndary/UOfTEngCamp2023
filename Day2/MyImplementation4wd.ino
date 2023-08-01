#include <HCSR04.h>


UltraSonicDistanceSensor ultrasonic(A0, A1);
float distance;

// Left Front Motor
int lmFrontSpeedPin = 5;
int lmFrontForwardPin = 6;
int lmFrontBackwardPin = 7;
// Left Back Motor
int lmBackSpeedPin = 3;
int lmBackForwardPin = 4;
int lmBackBackwardPin = A5;


// Right Front Motor
int rmFrontSpeedPin = 11;
int rmFrontForwardPin = 12;
int rmFrontBackwardPin = 13;
// Right Backward Motor
int rmBackSpeedPin = 8;
int rmBackForwardPin = 9;
int rmBackBackwardPin = 10;


void setup() {
  pinMode(lmFrontSpeedPin, OUTPUT);
  pinMode(lmFrontForwardPin, OUTPUT);
  pinMode(lmFrontBackwardPin, OUTPUT);
  pinMode(lmBackSpeedPin, OUTPUT);
  pinMode(lmBackForwardPin, OUTPUT);
  pinMode(lmBackBackwardPin, OUTPUT);
  pinMode(rmFrontSpeedPin, OUTPUT);
  pinMode(rmFrontForwardPin, OUTPUT);
  pinMode(rmFrontBackwardPin, OUTPUT);
  pinMode(rmBackSpeedPin, OUTPUT);
  pinMode(rmBackForwardPin, OUTPUT);
  pinMode(rmBackBackwardPin, OUTPUT);

  randomSeed(analogRead(19));
}

void loop() {
  distance = ultrasonic.measureDistanceCm();

  if (distance < 0 || distance < 25) {
    stop();
    delay(50);
    goBackward();
    stop();
    delay(50);
    if (random(0, 2)) {
      goLeft();
    } else {
      goRight();
    }
    stop();
    delay(50);
  } else {
    goForward();
  }
}

void goForward() {
  digitalWrite(lmFrontForwardPin, HIGH);
  digitalWrite(lmFrontBackwardPin, LOW);
  digitalWrite(rmFrontForwardPin, HIGH);
  digitalWrite(rmFrontBackwardPin, LOW);
  digitalWrite(lmBackForwardPin, HIGH);
  digitalWrite(lmBackBackwardPin, LOW);
  digitalWrite(rmBackForwardPin, HIGH);
  digitalWrite(rmBackBackwardPin, LOW);
}

void goBackward() {
  digitalWrite(lmFrontForwardPin, LOW);
  digitalWrite(lmFrontBackwardPin, HIGH);
  digitalWrite(rmFrontForwardPin, LOW);
  digitalWrite(rmFrontBackwardPin, HIGH);
  digitalWrite(lmBackForwardPin, LOW);
  digitalWrite(lmBackBackwardPin, HIGH);
  digitalWrite(rmBackForwardPin, LOW);
  digitalWrite(rmBackBackwardPin, HIGH);
}

void stop() {
  digitalWrite(lmFrontForwardPin, LOW);
  digitalWrite(lmFrontBackwardPin, LOW);
  digitalWrite(rmFrontForwardPin, LOW);
  digitalWrite(rmFrontBackwardPin, LOW);
  digitalWrite(lmBackForwardPin, LOW);
  digitalWrite(lmBackBackwardPin, LOW);
  digitalWrite(rmBackForwardPin, LOW);
  digitalWrite(rmBackBackwardPin, LOW);
}

void goRight() {
  digitalWrite(lmFrontForwardPin, HIGH);
  digitalWrite(lmFrontBackwardPin, LOW);
  digitalWrite(rmFrontForwardPin, LOW);
  digitalWrite(rmFrontBackwardPin, LOW);
  digitalWrite(lmBackForwardPin, HIGH);
  digitalWrite(lmBackBackwardPin, LOW);
  digitalWrite(rmBackForwardPin, LOW);
  digitalWrite(rmBackBackwardPin, LOW);
}

void goLeft() {
  digitalWrite(lmFrontForwardPin, LOW);
  digitalWrite(lmFrontBackwardPin, LOW);
  digitalWrite(rmFrontForwardPin, HIGH);
  digitalWrite(rmFrontBackwardPin, LOW);
  digitalWrite(lmBackForwardPin, LOW);
  digitalWrite(lmBackBackwardPin, LOW);
  digitalWrite(rmBackForwardPin, HIGH);
  digitalWrite(rmBackBackwardPin, LOW);
}
