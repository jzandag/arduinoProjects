
#define DELAY_TIME 500
#define DELAY_TIME2 100

int pinArray[] = {6,7,8,9,10,11,12,13};
int val = 0;


void setup() {
  // put your setup code here, to run once:
  for(int x = 0; x < 8; x++){
    pinMode(pinArray[x], OUTPUT);
  }
//  pinMode(switch1, INPUT);
//  pinMode(switch2, INPUT);
//  pinMode(switch3, INPUT);
//  pinMode(switch4, INPUT);

  Serial.begin(9600);
  Serial.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
  Serial.println("@@           MENU            @@");
  Serial.println("@@                           @@");
  Serial.println("@@ <1>Pattern1   <2>Pattern2 @@");
  Serial.println("@@ <3>Pattern3   <4>Pattern4 @@");
  Serial.println("@@                           @@");
  Serial.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

  
  
}

void loop() {
  if(Serial.available() > 0){
    val = Serial.read() - 48;
    Serial.println((char)val);
    
    if(val >= 1 || val <= 4){
      if(val == 1){
        pattern1(DELAY_TIME);
      }else if(val == 2){
        pattern2(DELAY_TIME);
      }else if(val == 3){
        pattern3(DELAY_TIME);
      }else if(val == 4){
        pattern4();
      }else{
      Serial.print("");
      Serial.print("Invalid input! Please put a valid choice!!! Input: ");
      Serial.print(val);
      }
      val = 0;
    }
  }
  

}

//this is for pattern 1
void pattern1(int timer){
  for(int x = 0; x < 8; x++){
    digitalWrite(pinArray[x], HIGH);
    delay(timer);
    digitalWrite(pinArray[x],LOW);
    if(x == 7){
      for(int j = 6; j>= 0;j--){
        digitalWrite(pinArray[j], HIGH);
        delay(timer);
        digitalWrite(pinArray[j],LOW);
      }
    }
  }
}

//this is for pattern 2
void pattern2(int timer){

  for(int cycleRed=0,cycleGreen=7; cycleRed<4, cycleGreen>3; cycleRed++, cycleGreen--)
  {
    digitalWrite(pinArray[cycleRed],HIGH);
    digitalWrite(pinArray[cycleGreen],HIGH);
    delay(timer);
    digitalWrite(pinArray[cycleRed],LOW);
    digitalWrite(pinArray[cycleGreen],LOW);

  }
  
  for(int cycleRed=2,cycleGreen=5; cycleRed>1, cycleGreen<7; cycleRed--, cycleGreen++)
  {
    digitalWrite(pinArray[cycleRed],HIGH);
    digitalWrite(pinArray[cycleGreen],HIGH);
    delay(timer);
    digitalWrite(pinArray[cycleRed],LOW);
    digitalWrite(pinArray[cycleGreen],LOW);

  }
    
}

//this is for pattern 3
void pattern3(int timer){
  for (int i = 0; i < 4; i++ ){
    //make the pin n and pin n+4 high
    digitalWrite(pinArray[i], HIGH);
    digitalWrite(pinArray[i+4], HIGH);
    delay(timer);
    digitalWrite(pinArray[i], LOW);
    digitalWrite(pinArray[i+4], LOW);
  }
  for(int x=2, y=6; x>1, y>4; x--, y--){
    digitalWrite(pinArray[x],HIGH);
    digitalWrite(pinArray[y],HIGH);
    delay(timer);
    digitalWrite(pinArray[x],LOW);
    digitalWrite(pinArray[y],LOW);
  }
}

//this is for pattern 4
void pattern4(){
  pattern1(DELAY_TIME2);
  pattern2(DELAY_TIME2);
  pattern3(DELAY_TIME2);
}


