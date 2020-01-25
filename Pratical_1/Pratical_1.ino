

int x ;
int pinArray[] = {6,7,8,9,10,11,12,13};
int inputnumber ;
int inputInt = 0 ;
int num = 0;
int newval = 0;
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
  
    if((inputInt >= 0) && (inputInt <= 255) ){
      
        if(inputInt % 2){
          digitalWrite(pinArray[x], HIGH);
        }else{
          digitalWrite(pinArray[x], LOW);
        }
        inputInt /= 2;
      }
    }
  }



