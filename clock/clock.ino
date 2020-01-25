void setup() {
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(3, LOW);
  
  delay(2000);
  digitalWrite(3, HIGH);
  analogWrite(3,255);
  delay(2000);
}
