const int ledpin1 = 13;
const int ledpin2 = 12;
const int ledpin3 = 11;
const int ledpin5 = 10;
const int ledpin4 = 9;
const int soundpin = A0;
const int buttonPin = 2;
const int threshold = 10;

int soundSens = 0;

void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
  pinMode(ledpin5, OUTPUT);
  pinMode(soundpin, INPUT);
  pinMode(buttonPin, INPUT);
}

void detectSound() {
  if (soundSens >= threshold + 40) {
    digitalWrite(ledpin1, HIGH); //turns led on
    delay(100);
  }
  else {
    digitalWrite(ledpin1, LOW);
  }
  if (soundSens >= threshold + 45) {
    digitalWrite(ledpin2, HIGH); //turns led on
    delay(100);
  }
  else {
    digitalWrite(ledpin2, LOW);
  }
  if (soundSens >= threshold + 50) {
    digitalWrite(ledpin3, HIGH); //turns led on
    delay(100);
  }
  else {
    digitalWrite(ledpin3, LOW);

  }
  if (soundSens >= threshold + 53) {
    digitalWrite(ledpin4, HIGH); //turns led on
    delay(100);
  }
  else {
    digitalWrite(ledpin4, LOW);
  }
  if (soundSens >= threshold + 55) {
    digitalWrite(ledpin5, HIGH); //turns led on
    delay(100);
  }
  else {
    digitalWrite(ledpin5, LOW);
  }
}

void loop() {
  soundSens = analogRead(soundpin); // reads analog data from sound sensor

  if (digitalRead(buttonPin) == HIGH) {
    detectSound();
  }
}
