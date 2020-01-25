//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

//const int password = 1412;


char tempVar;
char jejeje[20];
int counter = 0;


void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 0);
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

      tempVar = convertToJejemon( Serial.read() );

      Serial.println(" tempvar =" );
      Serial.println(tempVar);

      //display each character to the LCD
      if (tempVar == '#') {
        lcd.clear();

        lcd.setCursor(2, 1);
        for (int x = 0; x < 20; x++) jejeje[x] = ' ';
        counter = 0;
      } else {
        jejeje[counter++] = tempVar; 
//        lcd.print(jejeje);
      }

      Serial.println("JEJEmon message :");
      for (int x = 0; x < 20; x++) {

        Serial.print(jejeje[x]);
      }

      Serial.println("");
      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print(jejeje);
     // counter = 0;
                //      for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
                //        // scroll one position left:
                //        lcd.scrollDisplayLeft();
                //        // wait a bit:
                //        delay(150);
                //      }
    }
  }
}

char convertToJejemon(char var) {
  switch (var) {
    case 'h': case 'H':
      return 'j';
      break;
    case 'a': case 'A':
      return '@';
      break;
    case 'e': case 'E':
      return '3';
      break;
    case 'o': case 'O':
      return '0';
      break;
    case 'l': case 'L':
      return '7';
      break;
    case 'i': case 'I':
      return '1';
      break;
    case 's': case 'S':
      return '$';
      break;
    case 'g': case 'G':
      return '6';
      break;
    case 'u':
      return 'U';
      break;
    default:
      return var;
      break;
  }
}

