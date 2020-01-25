
#define DELAY_TIME 500

int pinArray[] = {6,7,8,9,10,11,12,13};
char inp_char;
String inputValue = "";
int inputInt = 0;
int num = 0;

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
      for(int x; x< 8; x++){
        
        if(inputInt = 0 ){
          digitalWrite(pinArray[x], HIGH);
        }else{
          digitalWrite(pinArray[x], LOW);
        }
         if(inputInt = 1 ){
          digitalWrite(pinArray[6], HIGH);
        }else{
          digitalWrite(pinArray[x], LOW);
        }
         if(inputInt = 2 ){
          digitalWrite(pinArray[6,7], HIGH);
        }else{
          digitalWrite(pinArray[x], LOW);
        }


       
      }
    
  }
  }
  }



