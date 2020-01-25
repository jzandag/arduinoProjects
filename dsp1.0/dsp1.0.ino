#include <SoftwareSerial.h>

String value;           //variable for the recorded voice
int transmitter = 11;   //for Tx pin
int receiver = 10;      //for Rx pin  
SoftwareSerial lamp(transmitter, receiver);     //SoftwareSerial instance

void setup() {        
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);       //asigning pin 3,5,6,9 as OUTPUT
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);       // start serial communication at 9600bps
  lamp.begin(9600);
}

void loop(){
  Serial.println(value);
  if (lamp.available()) {
    value = lamp.readString();

    if(value == "dim"){
      analogWrite(3, 30);
      analogWrite(5, 30);
      analogWrite(6, 30);
      analogWrite(9, 30);
    } 

    else if(value == "bright"){
      analogWrite(3, 255); 
      analogWrite(5, 255); 
      analogWrite(6, 255); 
      analogWrite(9, 255); 
    }
 
    else if (value == "turn on") {
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
    }

    else if (value == "turn off") {
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
    }
  }
  
  Serial.print("The recorded message is ");
  Serial.print(value); // display the value of the recorded 

  delay(10);
}
