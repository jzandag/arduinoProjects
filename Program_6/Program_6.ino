int pin12 = 12;
int brightness = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin12, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin12, brightness);
  brightness += 10;

  if(brightness == 255){
    brightness = 0;
    while(true)
      continue;
  }
  
  
  digitalWrite(pin12, HIGH);
  delay(100);
}

void blink(int counter){
  for(int i = 0; i < counter ; i++){
      digitalWrite(pin12, HIGH);
      delay(750);
      digitalWrite(pin12, LOW);
      delay(750);
  }
    
    
  
}

