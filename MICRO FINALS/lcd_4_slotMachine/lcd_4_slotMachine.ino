//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

char tempVar;
int firstSlot;
int secondSlot;
int thirdSlot;

int counter = 0;

byte clubs[] = {
  B00100,
  B10101,
  B11111,
  B11111,
  B01110,
  B00100,
  B01110,
  B00000
};
byte hearts[] = {
  B01010,
  B11011,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};
byte diamonds[] = {
  B00000,
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000
};
byte spades[] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B01110,
  B00000
};



void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 0);
  //  lcd.setCursor(1,1);
  lcd.print("*Slot Machine*");
  lcd.createChar(0, hearts);
  lcd.createChar(1, spades);
  lcd.createChar(2, clubs);
  lcd.createChar(3, diamonds);
}


void loop() {
  lcd.setCursor(1, 0);
  //  lcd.setCursor(1,1);
  lcd.print("*Slot Machine*");
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

      //display each character to the LCD
      if (tempVar == '#') {
        int firstSlot = rand() % (3 + 1);
        int secondSlot = rand() % (3 + 1);
        int thirdSlot = rand() % (3 + 1);
        //tester
//        int firstSlot = 7;
//        int secondSlot = 7;
//        int thirdSlot = 7;
        lcd.setCursor(7, 1);
        lcd.blink();delay(1000);
          if(firstSlot == 0) lcd.write(0);
          else if(firstSlot == 1) lcd.write(1);
          else if(firstSlot == 2) lcd.write(2);
          else if(firstSlot == 3) lcd.write(3);
          else lcd.print(firstSlot);
        lcd.setCursor(8, 1);
        lcd.blink();delay(1000);
          if(secondSlot == 0) lcd.write(0);
          else if(secondSlot == 1) lcd.write(1);
          else if(secondSlot == 2) lcd.write(2);
          else if(secondSlot == 3) lcd.write(3);
          else lcd.print(secondSlot);
        lcd.setCursor(9, 1);
        lcd.blink();delay(1000);
          if(thirdSlot == 0) lcd.write(0);
          else if(thirdSlot == 1) lcd.write(1);
          else if(thirdSlot == 2) lcd.write(2);
          else if(thirdSlot == 3) lcd.write(3);
          else lcd.print(thirdSlot);
          lcd.noBlink();
        delay(2000);
        if ((firstSlot == secondSlot) && (thirdSlot == firstSlot) && (secondSlot == thirdSlot)) {
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("YOU WIN!!!");
          delay(1000);
        } else {
          lcd.clear();
          lcd.setCursor(2, 0);
          lcd.print("TRY AGAIN!!!");
          delay(1000);
        }
      }



    }
  }
}

