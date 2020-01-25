
int pinArray[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  for(int i =0; i<13 ; i++){
    pinMode(pinArray[i], OUTPUT);
  }

    blink(7, 4);
    blink(8, 6);
    blink(9, 3);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void blink(int pin, int counter){
  for(int i = 0; i < counter; i++){
    digitalWrite(pinArray[pin], HIGH);
    delay(1000);
    digitalWrite(pinArray[pin], LOW);
    delay(1000);
  }
}

