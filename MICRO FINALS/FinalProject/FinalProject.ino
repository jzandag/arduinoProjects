/* Final project in Nicroprocessors
 * 
 * Members:
 * Andag, John Zidrex M.
 * Apura, Alyssa Karla N.
 * Buyco Jayven P.
 * Legaspi, Jeilene
 * Tumanquil, Sam
 * 
 * Submitted to: 
 * Engr. Julius Cansino
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int switches[] = {3,4,5,6,7,8};
int led[] = {9,10,11,12};
int buzzer = 13;

//variable for quiz bee
int score = 0;

void setup() {
  Serial.begin(9600);              // initialize the serial monitor
  
  lcd.init();                      // initialize the lcd
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  
  for(int x = 0; x < 6;x++){       // initialize the I/O pins
    pinMode(switches[x], INPUT);
  }
  for(int x = 0; x < 4;x++){
    pinMode(led[x], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);

//  play_winner(); // After setup is complete, say hello to the world
}

void loop() {
//  attractMode(); 
  // Prompt the user to choose betwwen two gamemodes
  lcd.setCursor(0, 0);
  lcd.print("Please choose your");
  lcd.setCursor(0, 1);
  lcd.print(" game mode!!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("a)add   b)subtract");
  lcd.setCursor(0,1);
  lcd.print("c)multiply d)divide");
  delay(400);
  quizBee();

  
}


//function for second gamemode
void quizBee(){
  while(digitalRead(switches[0]) == LOW || digitalRead(switches[1]) == LOW || digitalRead(switches[2]) == LOW || digitalRead(switches[3]) == LOW){
    if(digitalRead(switches[0]) == HIGH){
      add();
    }else if(digitalRead(switches[1]) == HIGH){
      subtract();
    }else if(digitalRead(switches[2]) == HIGH){
      multiply();
    }else if(digitalRead(switches[3]) == HIGH){
      divide();
    }
  }
  
}

void add(){
  //first question
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(""); 
  lcd.setCursor(0,1);
  lcd.print("");
  delay(400);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("a)     b)");
  lcd.setCursor(0,1);
  lcd.print("c)     d)");
  delay(200);
  while(digitalRead(switches[0]) == LOW || digitalRead(switches[1]) == LOW || digitalRead(switches[2]) == LOW || digitalRead(switches[3]) == LOW){
    if(digitalRead(switches[0]) == HIGH)
      score++;
    else
      break;
  }
}

void subtract(){
  
}

void multiply(){
  
}

void divide(){
  
}

