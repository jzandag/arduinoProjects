//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

//const int password = 1412;
int counter = 0;
const char password[] = {'a', 'd', 'v', 'a', 'n', 'c', 'e', 't', 'h', 'i', 'n', 'k', 'i', 'n', 'g'};
char inputPassword[15];
int currentAttempts = 0;

char tempVar;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Input password: ");
  //  lcd.setCursor(2,1);
  //  lcd.print("Steph :>");
}


void loop() {
restart:
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    // read all the available characters
    while (Serial.available() > 0) {

      tempVar = Serial.read();
      Serial.println(" tempvar =" );
      Serial.println(tempVar);

      // display each character to the LCD
      if (tempVar == '#') {
        lcd.clear();
        if (strncmp(password, inputPassword,sizeof(password)) == 0) {
          while(1){
          lcd.setCursor(1, 1);
          
          lcd.print("ACCESS GRANTED");
          lcd.blink();
          }
        } else {
          currentAttempts++;
          lcd.setCursor(1, 0);
          lcd.print("ACCESS  DENIED");
          lcd.setCursor(1, 1);
          lcd.print(currentAttempts);
          lcd.setCursor(3, 1);
          lcd.print(" of 3 left");
          delay(4000);

          if (currentAttempts == 3) {
            while (1) {
              lcd.clear();
              lcd.setCursor(0, 1);
              lcd.print("LCD is locked!!");
              lcd.blink();
              delay(1000);
            }
          }

          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("Input password: ");
          counter = 0;
          for (int x = 0; x < 15; x++) inputPassword[x] = "";
          goto restart;
        }
      } else {
        inputPassword[counter] = tempVar;
      }


      Serial.println("Password :");
      for (int x = 0; x < 15; x++) {

        Serial.print(password[x]);
      }
      Serial.println("Inputted password :");
      for (int x = 0; x < 15; x++) {

        Serial.print(inputPassword[x]);
      }
      Serial.println("");
      lcd.setCursor(counter++, 1);
      lcd.print("*");
    }
  }
}

/*
  LiquidCrystal Library - Serial Input

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch displays text sent over the serial port
  (e.g. from the Serial Monitor) on an attached LCD.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe
  modified 7 Nov 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerialDisplay

*/

//// include the library code:
//#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
//// initialize the library by associating any needed LCD interface pin
//// with the arduino pin number it is connected to
//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//
//const char password[] = "advancethinking";
//char inputPassword[] = "";
//int currentAttempts = 0;
//
//char tempVar;
//void setup() {
//  // set up the LCD's number of columns and rows:
//  lcd.begin(16, 2);
//  // initialize the serial communications:
//  Serial.begin(9600);
//  lcd.clear();
//}
//
//void loop() {
//  // when characters arrive over the serial port...
//  if (Serial.available()) {
//    // wait a bit for the entire message to arrive
//    delay(100);
//    // clear the screen
//    lcd.clear();
//    // read all the available characters
//    while (Serial.available() > 0) {
//
//      tempVar = Serial.read();
//      // display each character to the LCD
//      if(tempVar == "#"){
//        if(password == inputPassword){
//          lcd.setCursor(2,1);
//          lcd.print("ACCESS GRANTED");
//          lcd.blink();
//        }else{
//          currentAttempts++;
//          lcd.setCursor(1,1);
//          lcd.print("ACCESS  DENIED");
//          lcd.setCursor(1,2);
//          lcd.print(currentAttempts);
//          lcd.setCursor(3,2);
//          lcd.print(" of 3 left");
//          delay(3000);
//          if(currentAttempts == 3){
//            while(1){
//              lcd.clear();
//              lcd.setCursor(3,1);
//              lcd.print("LCD is locked");
//              lcd.blink();
//              delay(1000);
//            }
//          }
//
//        }
//      }else{
//        strcat(inputPassword,tempVar);
//      }
//
//      lcd.write("*");
//    }
//  }
//}

