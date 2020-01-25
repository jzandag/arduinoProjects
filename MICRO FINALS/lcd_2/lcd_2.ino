//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int counter = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  
  //  lcd.setCursor(2,1);
  //  lcd.print("Steph :>");
}


void loop() {
restart:
  lcd.setCursor(0, 0);
  lcd.print("1-L2R MENU 2-R2L");

  lcd.setCursor(0, 1);
  lcd.print("3-U2D      4-D2U");
  
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
      if (tempVar == '1') { //left to right
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("dog");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("lazy dog");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("the lazy dog");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("over the lazy");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("jumps over the");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("fox jumps over");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("brown fox jumps");
         delay(1000);
         lcd.clear();
          lcd.setCursor(0,0);
         lcd.print("quick brown fox");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("The quick brown");
         delay(1000);
         lcd.clear();
         lcd.setCursor(7,0);
         lcd.print("The quick");
         delay(1000);
         lcd.clear();
         lcd.setCursor(13,0);
         lcd.print("The");
         delay(1000);
         lcd.clear();
         
      } else if (tempVar == '2') { // right to left
         lcd.clear();
         lcd.setCursor(13,0);
         lcd.print("The");
         delay(1000);
         lcd.clear();
         lcd.setCursor(7,0);
         lcd.print("The quick");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("The quick brown");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("quick brown fox");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("brown fox jumps");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("fox jumps over");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("jumps over the");
         delay(1000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("the lazy dog.");
         delay(1000);
         lcd.clear();
      } else if (tempVar == '3') { // up down
          lcd.clear();
         lcd.setCursor(4,0);
         lcd.print("dog");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("lazy");
         lcd.setCursor(4,1);
         lcd.print("dog");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("the");
         lcd.setCursor(4,1);
         lcd.print("lazy");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("over");
         lcd.setCursor(4,1);
         lcd.print("the");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("jumps");
         lcd.setCursor(4,1);
         lcd.print("over");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("fox");
         lcd.setCursor(4,1);
         lcd.print("jumps");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("brown");
         lcd.setCursor(4,1);
         lcd.print("fox");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("quick");
         lcd.setCursor(4,1);
         lcd.print("brown");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("The");
         lcd.setCursor(4,1);
         lcd.print("quick");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,1);
         lcd.print("The");
         delay(1000);
         lcd.clear();
      } else if (tempVar == '4') { // down up
         lcd.clear();
         lcd.setCursor(4,0);
         lcd.print("The");
         lcd.setCursor(4,1);
         lcd.print("quick");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("quick");
         lcd.setCursor(4,1);
         lcd.print("brown");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("brown");
         lcd.setCursor(4,1);
         lcd.print("fox");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("fox");
         lcd.setCursor(4,1);
         lcd.print("jumps");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("jumps");
         lcd.setCursor(4,1);
         lcd.print("over");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("over");
         lcd.setCursor(4,1);
         lcd.print("the");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("the");
         lcd.setCursor(4,1);
         lcd.print("lazy");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("lazy");
         lcd.setCursor(4,1);
         lcd.print("dog");
         delay(1000);
         lcd.clear();

         lcd.setCursor(4,0);
         lcd.print("dog");
         delay(1000);
         lcd.clear();
      }
    }
  }
}




