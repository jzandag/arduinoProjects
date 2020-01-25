
#define RED 6
#define YELLOW 7
#define GREEN 8

int pin6 = RED;
int pin7 = YELLOW;
int pin8 = GREEN;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, LOW);
  digitalWrite(pin8, LOW);
  delay(10000);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, LOW);
  delay(1000);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin8, HIGH);
  delay(8000);
}

void blink(int pin, int counter){
  for(int i = 0; i < counter; i++){
    
  }
}

