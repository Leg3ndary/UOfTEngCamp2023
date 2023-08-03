#include <HCSR04.h>


UltraSonicDistanceSensor ultrasonic(A0, A1);

// Left Front Motor
const int lmfSpeed = A5;
const int lmfForward = 3;
const int lmfBackward = 4;
// Left Back Motor
const int lmbSpeed = 5;
const int lmbForward = 6;
const int lmbBackward = 7;
// Right Front Motor
const int rmfSpeed = 8;
const int rmfForward = 9;
const int rmfBackward = 10;
// Right Backward Motor
const int rmbSpeed = 11;
const int rmbForward = 12;
const int rmbBackward = 13;
// Misc
const int LEDs = A2;
const int IRSensor = A3;
const int piezo = A4;

float USDistance;
float IRDistance

void setup() {
  pinMode(lmfSpeed, OUTPUT);
  pinMode(lmfForward, OUTPUT);
  pinMode(lmfBackward, OUTPUT);
  pinMode(lmbSpeed, OUTPUT);
  pinMode(lmbForward, OUTPUT);
  pinMode(lmbBackward, OUTPUT);
  pinMode(rmfSpeed, OUTPUT);
  pinMode(rmfForward, OUTPUT);
  pinMode(rmfBackward, OUTPUT);
  pinMode(rmbSpeed, OUTPUT);
  pinMode(rmbForward, OUTPUT);
  pinMode(rmbBackward, OUTPUT);
  pinMode(LEDs, OUTPUT);
  pinMode(IRSensor, INPUT);
  pinMode(piezo, OUTPUT);

  digitalWrite(lmfSpeed, HIGH);
  digitalWrite(rmfSpeed, HIGH);
  digitalWrite(lmbSpeed, HIGH);
  digitalWrite(rmbSpeed, HIGH);
}

void loop() {
  USDistance = ultrasonic.measureDistanceCm();
  IRDistance = analogRead(IRSensor) * 10;

  if (distance < 0 || distance < 25) {
    stop();
    goBackward();
    stop();
    if (random(0, 2)) {
      goLeft();
    } else {
      goRight();
    }
    stop();
  } else {
    goForward();
  }
}

void goForward() {
  digitalWrite(lmfForward, HIGH);
  digitalWrite(lmfBackward, LOW);
  digitalWrite(rmfForward, HIGH);
  digitalWrite(rmfBackward, LOW);
  digitalWrite(lmbForward, HIGH);
  digitalWrite(lmbBackward, LOW);
  digitalWrite(rmbForward, HIGH);
  digitalWrite(rmbBackward, LOW);
}

void goBackward() {
  digitalWrite(lmfForward, LOW);
  digitalWrite(lmfBackward, HIGH);
  digitalWrite(rmfForward, LOW);
  digitalWrite(rmfBackward, HIGH);
  digitalWrite(lmbForward, LOW);
  digitalWrite(lmbBackward, HIGH);
  digitalWrite(rmbForward, LOW);
  digitalWrite(rmbBackward, HIGH);
}

void stop() {
  digitalWrite(lmfForward, LOW);
  digitalWrite(lmfBackward, LOW);
  digitalWrite(rmfForward, LOW);
  digitalWrite(rmfBackward, LOW);
  digitalWrite(lmbForward, LOW);
  digitalWrite(lmbBackward, LOW);
  digitalWrite(rmbForward, LOW);
  digitalWrite(rmbBackward, LOW);
}

void goRight() {
  digitalWrite(lmfForward, HIGH);
  digitalWrite(lmfBackward, LOW);
  digitalWrite(rmfForward, LOW);
  digitalWrite(rmfBackward, LOW);
  digitalWrite(lmbForward, HIGH);
  digitalWrite(lmbBackward, LOW);
  digitalWrite(rmbForward, LOW);
  digitalWrite(rmbBackward, LOW);
}

void goLeft() {
  digitalWrite(lmfForward, LOW);
  digitalWrite(lmfBackward, LOW);
  digitalWrite(rmfForward, HIGH);
  digitalWrite(rmfBackward, LOW);
  digitalWrite(lmbForward, LOW);
  digitalWrite(lmbBackward, LOW);
  digitalWrite(rmbForward, HIGH);
  digitalWrite(rmbBackward, LOW);
}
