/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include<Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

double output = 0;
char optrKey; //this is the variable for the operator

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKey = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Serial.print("Enter first number:");
  double firstKey = getNumber();
  delay(1000);
  Serial.print("Enter second number:");
  delay(1000);
  double secondKey = getNumber();
  boom:
  Serial.print("Enter operation (+,-,*,/,%)");
  if(Serial.available() > 0)
    optrKey = Serial.read();
  if(optrKey == "+"){
    output = firstKey + secondKey;
  }else if(optrKey == "-"){
    output = firstKey - secondKey;
  }else if(optrKey == "*"){
    output = firstKey * secondKey;
  }else if(optrKey == "/"){
    output = firstKey / secondKey;
  }else{
    Serial.print("Putang ina di pwede yan!");
    Serial.print("Enter an operator once again!");
    goto boom;
  }

  Serial.print("Expression is: ");
  Serial.print(firstKey);
  Serial.print(optrKey);
  Serial.println(secondKey);
  Serial.print("The output is");
  Serial.println(output); 
}
  
void loop(){

 
}


double getNumber(){
   int num = 0;
   char key1 = myKey.getKey();
     switch (key1){
       case NO_KEY:
        break;
  
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        num = num * 10 + (key1 - '0');
        break;
  
      case '#':
          return num;
          break;
  
      case '*':
          num = 0;
     }
}
