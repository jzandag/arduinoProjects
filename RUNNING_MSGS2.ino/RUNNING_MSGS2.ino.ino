//int helloArray[5][7] = { {0,1,1,0,1,1,1}, //H
//                         {1,0,0,1,1,1,1}, //E
//                         {0,0,0,1,1,1,0}, //L
//                         {0,0,0,1,1,1,0}, //L
//                         {1,1,1,1,1,1,0}  //O
//                        };
//int byeArray[8][7] = { {1,0,1,1,1,1,1},   //G
//                       {0,0,1,1,1,0,1},   //o
//                       {0,0,1,1,1,0,1},   //o
//                       {0,1,1,1,1,0,1},   //d
//                       {0,0,0,0,0,0,0},   //
//                       {0,0,1,1,1,1,1},   //b
//                       {0,1,1,1,0,1,1},   //y
//                       {1,0,0,1,1,1,1}    //e
//
//  };

#include<Keypad.h>

//Anode conigurations
int helloArray[5][7] = { {1, 0, 0, 1, 0, 0, 0}, //H
  {0, 1, 1, 0, 0, 0, 0}, //E
  {1, 1, 1, 0, 0, 0, 1}, //L
  {1, 1, 1, 0, 0, 0, 1}, //L
  {0, 0, 0, 0, 0, 0, 1} //O
};
int byeArray[8][7] = { {0, 1, 0, 0, 0, 0, 0}, //G
  {1, 1, 0, 0, 0, 1, 0}, //o
  {1, 1, 0, 0, 0, 1, 0}, //o
  {1, 0, 0, 0, 0, 1, 0}, //d
  {1, 1, 1, 1, 1, 1, 1}, //
  {1, 1, 0, 0, 0, 0, 0}, //b
  {1, 0, 0, 0, 1, 0, 0}, //y
  {0, 1, 1, 0, 0, 0, 0} //e

};


int ldr1 = A0;
int ldr2 = A1;
int switchDir = 13;

int segmentPin[] = {6, 7, 8, 9, 10, 11, 12};
int commonPin[] = {2, 3, 4, 5};

void setup() {
  for (int x = 0; x < 7; x++) {
    pinMode(segmentPin[x], OUTPUT);
  }
  for (int x = 0; x < 4; x++) {
    pinMode(commonPin[x], OUTPUT);
  }
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(switchDir, INPUT);

  Serial.begin(9600);
}

void loop() {
  int value = analogRead(ldr1);
  Serial.print("LDR 1:");
  Serial.println(value);
  int value2 = analogRead(ldr2);
  Serial.print("LDR 2:");
  Serial.println(value2);
  Serial.print("SWITCH STATE:");
  Serial.println(digitalRead(switchDir));
  if (digitalRead(switchDir) == HIGH) {
    if (value > 680) {
      /*### THIS IS FOR HELLO MODULE ### */
      for (int w = 0; w < 200; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 1, z = 1, y = 0; z < 5; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 2, z = 2, y = 0; z < 6; z++, x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 3, z = 3, y = 0; z < 7; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 4, z = 4, y = 0; z < 8; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      /*### THIS IS FOR HELLO MODULE ### */
    } else if (value2 > 680) {
      /*### THIS IS FOR GOOD BYE MODULE ### */
      for (int w = 0; w < 200; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 1, z = 1, y = 0; z < 5; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 2, z = 2, y = 0; z < 6; z++, x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 3, z = 3, y = 0; z < 7; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 4, z = 4, y = 0; z < 8; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 5, z = 5, y = 0; z < 9; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 6, z = 6, y = 0; z < 10; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 7, z = 7, y = 0; z < 11; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      /*### THIS IS FOR GOOD BYE MODULE ### */
    }
  } else if (digitalRead(switchDir) == LOW) {
    if (value > 680) {
      for (int w = 0; w < 200; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 4, z = 4, y = 0; z < 8; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 3, z = 3, y = 0; z < 7; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 2, z = 2, y = 0; z < 6; z++, x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 1, z = 1, y = 0; z < 5; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          hello(x);
          if (y == 3) y = -1;
          if (x == 4) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
    } else if (value2 > 680) {
      /* <!-- THID IS FOR GOODBYE MODULE --> */
      for (int w = 0; w < 200; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 7, z = 7, y = 0; z < 11; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 6, z = 6, y = 0; z < 10; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 5, z = 5, y = 0; z < 9; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 4, z = 4, y = 0; z < 8; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 3, z = 3, y = 0; z < 7; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 2, z = 2, y = 0; z < 6; z++, x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 200; w++) {
        for (signed int x = 1, z = 1, y = 0; z < 5; x++, y++, z++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          if (x == 7) x = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      for (int w = 0; w < 50; w++) {
        for (signed int x = 0, y = 0; x < 4; x++, y++) {
          digitalWrite(commonPin[y], HIGH);
          goodbye(x);
          if (y == 3) y = -1;
          delay(1);
          for (int x = 0; x < 4; x++) {
            digitalWrite(commonPin[x], LOW);
          }
          for (int x = 0; x < 7; x++) {
            digitalWrite(segmentPin[x], LOW);
          }
        }
      }
      /* <!-- THID IS FOR GOODBYE MODULE --> */
    }
  }
  //delay(2000);  /*Uncomment if you want to debug the program*/
}

void goodbye(int num) {
  for (int x = 0, y = 0; x < 7; x++) {
    digitalWrite(segmentPin[x], byeArray[num][x]);
  }
}

void hello(int num) {
  for (int x = 0; x < 7; x++) {
    digitalWrite(segmentPin[x], helloArray[num][x]);
  }
}

