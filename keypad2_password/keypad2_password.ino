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

int password = 1412;

double output = 0;
char optrKey; //this is the variable for the operator

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad myKey = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Please enter your password: ");
  int inputPassword = getPassword();

  if(password == inputPassword){
    Serial.println("Access granted");
  }else{
    Serial.println("Access Denied  ");
  }

}


int getPassword() {
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
        Serial.print("*");
        break;

      case '*':
        num = 0;
        break;
    }

    key = myKey.getKey();
  }
  
  return num;
}
