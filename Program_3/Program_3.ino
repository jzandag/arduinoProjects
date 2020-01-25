int pin9 = 9;

void setup() {
  pinMode(9, OUTPUT);

}

void loop() {
  digitalWrite(pin9, HIGH);
  delay(750);
  digitalWrite(pin9, LOW);
  delay(750);
}


