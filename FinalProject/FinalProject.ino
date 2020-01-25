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

#define CHOICE_OFF      0 //Used to control LEDs
#define CHOICE_NONE     0 //Used to check buttons
#define CHOICE_RED  (1 << 0)
#define CHOICE_GREEN    (1 << 1)
#define CHOICE_BLUE (1 << 2)
#define CHOICE_YELLOW   (1 << 3)


//Number of rounds to succesfully remember before you win. 13 is do-able.
#define ROUNDS_TO_WIN      13 
//Amount of time to press a button before game times out. 3000ms = 3 sec
#define ENTRY_TIME_LIMIT   3000

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display



int switches[] = {3,4,5,6,7,8};
int led[] = {9,10,11,12};
int buzzer = 13;
//9-RED    -5
//10-GREEN  -6
//11-BLUE   -7 
//12-YELLOW  -8


//variables for simon says
byte gameMode = 0; //By default, let's play the memory game
//Contains the combination of buttons as we advance
byte gameBoard[32]; 
//Counts the number of succesful rounds the player has made it through
byte gameRound = 0; 

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

  play_winner(); // After setup is complete, say hello to the world
}

void loop() {
  attractMode(); 
  // Prompt the user to choose betwwen two gamemodes
  lcd.setCursor(0, 0);
  lcd.print("Please choose your");
  lcd.setCursor(0, 1);
  lcd.print("       game!");
    
    // If the user chooses the first gamemode
    if(digitalRead(switches[0] == HIGH)  ){
      //call first game mode function
      memoryGame();
    }

    
    // If the user chooses the second gamemode
    else if(digitalRead(switches[1] == HIGH) ){
      //call second game mode function
      quizBee();
    }
  
}


//Function for first gamemode
void simonSays(){

  // Turn all LEDs on
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE | CHOICE_YELLOW); 
  delay(1000);
  setLEDs(CHOICE_OFF); // Turn off LEDs
  delay(250);

  // Play memory game and handle result
  if (play_memory() == true) 
    play_winner(); // Player won, play winner tones
  else 
    //play_loser(); // Player lost, play loser tones
}


//function for second gamemode
void quizBee(){
  lcd.clear();
  lcd.setCursor(0,0);

  //NANI DAFAQ
  //DI KAKAYANIN
  
}

void attractMode(){
  while(1){

    setLEDs(CHOICE_RED);

    delay(100);

    if (checkButton() != CHOICE_NONE) return;
    setLEDs(CHOICE_BLUE);

    delay(100);

    if (checkButton() != CHOICE_NONE) return;
    setLEDs(CHOICE_GREEN);

    delay(100);

    if (checkButton() != CHOICE_NONE) return;
    setLEDs(CHOICE_YELLOW);

    delay(100);

    if (checkButton() != CHOICE_NONE) return;

  }
}

void setLEDs(byte leds){

  if ((leds & CHOICE_RED) != 0)
    digitalWrite(led[0], HIGH);
  else
    digitalWrite(led[0], LOW);

  if ((leds & CHOICE_GREEN) != 0)
    digitalWrite(led[1], HIGH);
  else
    digitalWrite(led[1], LOW);

  if ((leds & CHOICE_BLUE) != 0)
    digitalWrite(led[2], HIGH);
  else
    digitalWrite(led[2], LOW);

  if ((leds & CHOICE_YELLOW) != 0)
    digitalWrite(led[3], HIGH);
  else
    digitalWrite(led[3], LOW);
}

byte checkButton(void){
  if (digitalRead(switches[0]) == 0) return(CHOICE_RED); 
  else if (digitalRead(switches[1]) == 0) return(CHOICE_GREEN); 
  else if (digitalRead(switches[2]) == 0) return(CHOICE_BLUE); 
  else if (digitalRead(switches[3]) == 0) return(CHOICE_YELLOW);
  return(CHOICE_NONE); // If no button is pressed, return none

}

boolean play_memory(void){
  randomSeed(millis()); // Seed the random generator with random amount of millis()

  gameRound = 0; // Reset the game to the beginning

  while (gameRound < ROUNDS_TO_WIN) 
  {

    add_to_moves(); // Add a button to the current moves, then play them back
    playMoves(); // Play back the current game board
    // Then require the player to repeat the sequence.

    for (byte currentMove = 0 ; currentMove < gameRound ; currentMove++){
      byte choice = wait_for_button(); // See what button the user presses

      if (choice == 0) return false; // If wait timed out, player loses
      if (choice != gameBoard[currentMove]) return false; // If the choice is incorect, player loses

    }
    delay(1000); // Player was correct, delay before playing moves
  }

  return true; // Player made it through all the rounds to win!
}

void playMoves(void)
{
  for (byte currentMove = 0 ; currentMove < gameRound ; currentMove++){

    toner(gameBoard[currentMove], 150);
    // Wait some amount of time between button playback
    // Shorten this to make game harder
    delay(150); // 150 works well. 75 gets fast.

  }

}

void add_to_moves(void){
  byte newButton = random(0, 4); //min (included), max (exluded)
  // We have to convert this number, 0 to 3, to CHOICEs

  if(newButton == 0) newButton = CHOICE_RED;
  else if(newButton == 1) newButton = CHOICE_GREEN;
  else if(newButton == 2) newButton = CHOICE_BLUE;
  else if(newButton == 3) newButton = CHOICE_YELLOW;
  gameBoard[gameRound++] = newButton; // Add this new button to the game array

}

byte wait_for_button(void){
  long startTime = millis(); // Remember the time we started the this loop

  while ( (millis() - startTime) < ENTRY_TIME_LIMIT) // Loop until too much time has passed
  {
    byte button = checkButton();

    if (button != CHOICE_NONE)
    { 
      //toner(button, 150); // Play the button the user just pressed
      while(checkButton() != CHOICE_NONE) ;  // Now let's wait for user to release button
      delay(10); // This helps with debouncing and accidental double taps
      return button;

    }
  }
  return CHOICE_NONE; // If we get here, we've timed out!
}

void play_winner(void){

  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();

}

void winner_sound(void){

  // Toggle the buzzer at various speeds
  for (byte x = 250 ; x > 70 ; x--)
  {
    for (byte y = 0 ; y < 3 ; y++)
    {
      digitalWrite(buzzer, HIGH);
      //digitalWrite(BUZZER1, LOW);
      delayMicroseconds(x);
      digitalWrite(buzzer, LOW);
      //digitalWrite(BUZZER1, HIGH);
      delayMicroseconds(x);
    }
  }
}
