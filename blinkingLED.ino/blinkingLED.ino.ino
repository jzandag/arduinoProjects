
#define RED 10


void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, HIGH);
  delay(100);
  digitalWrite(RED, LOW);
  delay(100);
}
