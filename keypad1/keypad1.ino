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
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

int plus = 9;
int minus= 10;
int times= 11;
int divide=12;

double output = 0;
char optrKey; //this is the variable for the operator

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKey = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);

  pinMode(plus, INPUT);
  pinMode(minus, INPUT);
  pinMode(times, INPUT);
  pinMode(divide, INPUT);
}

void loop() {
  Serial.print("Enter first number: ");
  double firstKey = getNumber();
  Serial.println(firstKey);
  Serial.println("Enter second number: ");
  double secondKey = getNumber();
  Serial.println(secondKey);
boom:
  Serial.print("Enter operation (+,-,*,/)");
  char optrKey;

//  if (Serial.available() > 0) {
//    optrKey = Serial.read();
//        while (!Serial.available()){
//            //Do Absolutely Nothing until something is received over the serial port
//        }
//    Serial.println(optrKey);
//
//  }
  
//  if (!Serial.available()) {
//    optrKey = Serial.read();
//        while (!Serial.available()){
//            //Do Absolutely Nothing until something is received over the serial port
//        }
//    Serial.println(optrKey);
//
//  }

//  if (optrKey == '+') {
//    output = firstKey + secondKey;
  
//  } else if (optrKey == '-') {
//    output = firstKey - secondKey;
//  } else if (optrKey == '*') {
//    output = firstKey * secondKey;
//  } else if (optrKey == '/') {
//    output = firstKey / secondKey;
//  } else {
//    Serial.println("Putang ina di pwede yan!");
//    Serial.println("Enter an operator once again!");
//    Serial.println(optrKey);
//    optrKey = "";
//    delay(1000);
//    goto boom;
//  }

  if(digitalRead(plus) == LOW){
    output = firstKey + secondKey;
    optrKey = '+';
  }else if(digitalRead(minus) == LOW){
    optrKey = '-';
    output = firstKey - secondKey;
  }else if(digitalRead(times) == LOW){
    output = firstKey * secondKey;
    optrKey = '*';
  }else if(digitalRead(divide) == LOW){
    output = firstKey / secondKey;
    optrKey = '/';
  }
  Serial.print("cp1");

  Serial.print("Expression is: ");
  Serial.print(firstKey);
  Serial.print(optrKey);
  Serial.println(secondKey);
  Serial.print("The output is ");
  Serial.println(output);

}


int getNumber() {
  double num = 0;
  char key = myKey.getKey();
  while (key != '#')
  {
    switch (key)
    {
      case NO_KEY:
        break;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        num = num * 10 + (key - '0');
        break;

      case '*':
        num = 0;
        break;
    }

    key = myKey.getKey();
  }

  return num;
}
