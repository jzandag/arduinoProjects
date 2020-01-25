

int pinArray[] = {6,7,8,9,10,11,12,13};

String inputValue = "";
int inputInt = 0;
int num = 0;
int x ;

void setup() {
  for(int x = 0; x < 8; x++){
    pinMode(pinArray[x], OUTPUT);
  }
  
  Serial.begin(9600);
  
  Serial.println("Enter a number: ");

}

void loop() {
  
  if(Serial.available() > 0){
    inputInt= Serial.parseInt();
    Serial.println(inputInt);

   if(inputInt = 0 ){
          digitalWrite(pinArray[x], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
     if(inputInt = 1 ){
          digitalWrite(pinArray[6], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
     
      if(inputInt = 2 ){
          digitalWrite(pinArray[7], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
      if(inputInt = 3 ){
          digitalWrite(pinArray[7,8], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
       if(inputInt = 4 ){
          digitalWrite(pinArray[10,9], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
       if(inputInt = 5 ){
          digitalWrite(pinArray[13], HIGH);
        } 
        else{
          digitalWrite(pinArray[x], LOW);
            }
  }
  }

