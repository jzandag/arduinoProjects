#define time_delay 500

int pinArray[]= {1,2,3,4,5,6,7,8,9,10,11,12};
int opcode[] = {A0,A1,A2,A3};
int timePin4 = 13;
int timePin2 = A4;
int timePin1 = A5;

int output[][13] ={{ 0,1,0,1, 1,1,1,0, 0,0,1,1},
                {1,0,1,1, 1,1,1,0, 0,0,1,1},
                {0,0,1,0, 0,1,1,0, 0,0,1,1},
                
                {0,0,0,1, 1,0,1,0, 0,0,1,1},
                {0,0,1,0, 1,1,0,0, 0,0,1,1},
                {0,0,1,1, 1,1,1,0, 0,0,1,1},
                
                {0,0,0,1, 1,0,1,0, 0,0,1,1},
                {0,0,1,0, 1,1,1,0, 0,0,0,1},
                {0,0,1,1, 1,1,0,0, 0,1,1,1},

                {0,0,0,1, 1,0,1,0, 0,0,1,1},
                {0,0,1,0, 1,1,1,0, 0,0,0,1},
                {0,0,1,0, 1,1,0,0, 1,1,1,1},

                {0,0,1,1, 1,1,1,1, 0,0,1,0},
                {0,0,1,1, 1,1,1,1, 0,0,1,1},
                {0,0,1,1, 1,1,1,1, 0,0,1,1},

                {0,0,1,0, 0,1,1,0, 0,0,1,1}};

                
                

void setup(){
  // put your setup code here, to run once:

  for(int x =0; x < 12; x++){
    pinMode(pinArray[x], OUTPUT);
  }
  for(int x = 0; x< 4 ; x++){
    pinMode(opcode[x], INPUT);
  }
  pinMode(timePin4, INPUT);
  pinMode(timePin2, INPUT);
  pinMode(timePin1, INPUT);
  Serial.begin(9600);

}

void loop() {

  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[0][x]);
    }
  }
  else if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == HIGH){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[1][x]);
    }
  }
  //010
  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[2][x]);
    }
  }
  //011 2
  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == LOW ){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[3][x]);
    }
  }
  //100
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == LOW && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == LOW ){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[4][x]);
    }
  }
  //101 2
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == LOW ){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[5][x]);
    }
  }
  //011 3
  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == HIGH ){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[6][x]);
    }
  }
  //100 3
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == LOW && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == HIGH){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[7][x]);
    }
  }
  //101 3
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == LOW && digitalRead(opcode[3]) == HIGH){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[8][x]);
    }
  }
  //011 4
  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[9][x]);
    }
  }
  //100 4
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == LOW && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[10][x]);
    }
  }
  //101 4
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == LOW && digitalRead(opcode[1]) == LOW && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[11][x]);
    }
  }
  //011 5
  if(digitalRead(timePin4) == LOW && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == HIGH && digitalRead(opcode[1]) == HIGH && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[12][x]);
    }
  }
  //100 5
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == LOW && digitalRead(opcode[0]) == HIGH && digitalRead(opcode[1]) == HIGH && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[13][x]);
    }
  }
  //101 5
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == LOW && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == HIGH && digitalRead(opcode[1]) == HIGH && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == LOW){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[14][x]);
    }
  }
  //111
  if(digitalRead(timePin4) == HIGH && digitalRead(timePin2) == HIGH && 
  digitalRead(timePin1) == HIGH && digitalRead(opcode[0]) == HIGH && digitalRead(opcode[1]) == HIGH && digitalRead(opcode[2]) == HIGH && digitalRead(opcode[3]) == HIGH){
    for(int x= 0;x < 12; x++){
      digitalWrite(pinArray[x],output[16][x]);
    }
  }
  

}
