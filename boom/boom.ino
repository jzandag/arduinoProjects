
int pin10 = 10;
int pin3 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin10, OUTPUT);
  pinMode(pin3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pin3) == HIGH){
    digitalWrite(pin10, HIGH);
  }else{
    digitalWrite(pin10, LOW);
  }
}
