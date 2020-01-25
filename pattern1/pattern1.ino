
int pinArray[] = {6,7,8,9,10,11,12,13}; 

void setup() {
  // put your setup code here, to run once:
  for(int x = 0; x <8; x++){
    pinMode(pinArray[x], OUTPUT);
  }
}

void loop() {
  pattern1();
}

void pattern1(){
  for(int x = 0; x < 8; x++){
    digitalWrite(pinArray[x], HIGH);
    delay(500);
    digitalWrite(pinArray[x],LOW);
    if(x == 7){
      for(int j = 6; j> 0;j--){
        digitalWrite(pinArray[j], HIGH);
        delay(500);
        digitalWrite(pinArray[j],LOW);
      }
    }
  }

  
}

