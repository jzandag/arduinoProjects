int teamNumber = 7;

void setup(){
  teamNumber += 10;
  Serial.begin(9600);
  
  Serial.print("Team number is ");
  Serial.print(teamNumber);
  Serial.println();

  for(int x = teamNumber; x >= 0; x--){
     Serial.println(x);
     delay(500);
  }
  Serial.println("End of program");
}

void loop(){
  
}

