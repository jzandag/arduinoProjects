
#define DELAY_TIME 500

int pinArray[] = {3,4,5,6,7,8,9,10,11,12,13};
char inp_char;
String inputValue = "";

void setup() {
  for(int x = 0; x < 8; x++){
    pinMode(pinArray[x], OUTPUT);
  }
  
  Serial.begin(9600);
  
  Serial.println("Enter a number from 0 to 255: ");

}

void loop() {
  
  if(Serial.available() > 0){
    
    inp_char = Serial.read();
    Serial.println(inp_char);

    if((inp_char >= '0') && (inp_char <= '9') ){
      inputValue += inp_char;
    }

    Serial.println(inputValue);
    inputValue = "";
  }
}



