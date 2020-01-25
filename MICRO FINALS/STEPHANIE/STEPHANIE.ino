//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int password = 1412;

void setup()
{
  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Henlo");
  lcd.setCursor(2,1);
  lcd.print("Steph :>");
}


void loop(){
}
