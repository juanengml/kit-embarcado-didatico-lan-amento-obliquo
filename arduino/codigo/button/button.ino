const int b1 = 2;     // the number of the pushbutton pin
const int b2 = 3;
const int b3 = 4;

// variables will change:
int status_b1 = 0;         // variable for reading the pushbutton status
int status_b2 = 0;  
int status_b3 = 0;  

int numero;
void setup() {
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
}

void loop() {
  
  status_b1  = digitalRead(b1);
  status_b2  = digitalRead(b2);
  status_b3  = digitalRead(b3);
  
  if (status_b1 == HIGH) {
    numero = '1';
  }
  if (status_b2 == HIGH) {
    numero = '2';
  }
  if (status_b3 == HIGH) {
     numero = '3';
  } else {
    numero = '0';

  }
}
