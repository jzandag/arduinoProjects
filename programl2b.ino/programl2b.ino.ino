
int pin11 = 10;
int pin12 = 11;
int pin13 = 12;

void setup() {

  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);

  blinkThirty(10);
  
  digitalWrite(pin13, LOW);
}


/* Program L2B*/
void loop() {
  // put your main code here, to run repeatedly:
  
}


void blinkThirty(int counter){
  for(int i =0; i <counter ; i++){
    digitalWrite(pin11, HIGH);
    digitalWrite(pin12, LOW);
    digitalWrite(pin13, LOW);
    delay(1000);
    digitalWrite(pin11, LOW );
    digitalWrite(pin12, HIGH);
    digitalWrite(pin13, LOW);
    delay(1000);
    digitalWrite(pin11, LOW );
    digitalWrite(pin12, LOW);
    digitalWrite(pin13, HIGH);
    delay(1000);
  }
}

