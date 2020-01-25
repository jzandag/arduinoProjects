// include the library code:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define INTERVAL 150
LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int col = 0;

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


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  // clear the LCD screen:
  lcd.clear();

  lcd.createChar(0, hearts);
  lcd.createChar(1, spades);
  lcd.createChar(2, clubs);
  lcd.createChar(3, diamonds);
}


void loop() {
  openingMessage();
  top(); //top part of the sequence
  top();
}

//set up the welcome part
void openingMessage() {
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Program 5");
  delay(3000);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("MEMBERS: ");
  lcd.setCursor(0, 1);
  lcd.print("Andag, Zidrex M.");
  delay(800);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("MEMBERS: ");
  lcd.setCursor(0, 1);
  lcd.print("Apura, Alyssa N.");
  delay(800);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("MEMBERS: ");
  lcd.setCursor(0, 1);
  lcd.print("Buyco, Jayven P.");
  delay(800);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("MEMBERS: ");
  lcd.setCursor(0, 1);
  lcd.print("Legaspi, Jeilene");
  delay(800);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("MEMBERS: ");
  lcd.setCursor(0, 1);
  lcd.print("Tumanquil, Sam");
  delay(800);
}

//set up the space invader animation and make it move
void top() {
  lcd.clear();
  for(int x = 0; x < 16; x++){
    lcd.clear();
    lcd.setCursor(col++,0);
    lcd.write(0);
    lcd.setCursor(col++,0);
    lcd.write(1);
    lcd.setCursor(col++,0);
    lcd.write(2);
    lcd.setCursor(col++,0);
    lcd.write(3);
    delay(INTERVAL);
    col = col-3;
    
    if(col >= 13){
      bottom(); col =0;
      return;
    }
  }
}


void bottom(){
  col = 18;
  for(int x = 0, y = 13;x <20; x++,y++,col--){
    lcd.clear();
    if(y <= 15){
      lcd.setCursor(y,0);
      lcd.write(0);
      lcd.setCursor(y+1,0);
      lcd.write(1);
      lcd.setCursor(y+2,0);
      lcd.write(2);
    }
    if(col >= 0)lcd.setCursor(col-3,1);
    lcd.write(3);
    lcd.setCursor(col-2,1);
    if(col >= 0)lcd.write(2);
    lcd.setCursor(col-1,1);
    if(col >= 0)lcd.write(1);
    lcd.setCursor(col,1);
    if(col >= 0)lcd.write(0);
    delay(INTERVAL);
  }
}

