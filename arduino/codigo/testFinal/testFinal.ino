#include <AccelStepper.h>
#include <LiquidCrystal.h> // Adiciona a biblioteca "LiquidCrystal" ao projeto
// MENU BUTTONS 
const int b1 = 2;
const int b2 = 7;
const int b3 = 8;
// STATUS BUTTONS 
int status_b1 = 0;         // variable for reading the pushbutton status
int status_b2 = 0;  
int status_b3 = 0;  
// LCD CRISTAL 16X2 
LiquidCrystal lcd(12, 13, 7, 6, 5, 4); // Pinagem do LCD
// STEPPER MOTOR NEMA 17 CONTROLE  
int velocidade_motor = 100; 
int aceleracao_motor = 100;
int sentido_horario = 0;
int sentido_antihorario = 0;
int numero = 0; 
// Definicao pino ENABLE
int pino_enable = 10;
// Definicao pinos STEP e DIR
AccelStepper motor1(1,3,4);
void setup() {
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  Serial.begin(9600);
  pinMode(pino_enable, OUTPUT);
  motor1.setMaxSpeed(velocidade_motor);
  motor1.setSpeed(velocidade_motor);
  motor1.setAcceleration(aceleracao_motor);
  lcd.begin(16, 2); // Inicia o lcd de 16x2
  lcd.clear();              // Limpa o display
  lcd.setCursor(2, 0);      // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print("<=1 ;2 =>;0 STOP"); // RIGHT LEFT
  Serial.println("Digite 1, 2 ou 3 e clique em ENVIAR...");
}

void loop() {
  status_b1  = digitalRead(b1);
  status_b2  = digitalRead(b2);
  status_b3  = digitalRead(b3);  
  if (status_b1 == HIGH) {
    numero = '1';
    Serial.println("Numero 1 recebido - Girando motor sentido horario.");
    digitalWrite(pino_enable, LOW);
    sentido_horario = 1;
    sentido_antihorario = 0;
    lcd.clear();              
    lcd.setCursor(2, 0);      
    lcd.print("sentido horario");}
  if (status_b2 == HIGH) {
    numero = '2';
    Serial.println("Numero 2 recebido - Girando motor sentido anti-horario.");
    digitalWrite(pino_enable, LOW);
    sentido_horario = 0;
    sentido_antihorario = 1;
    lcd.clear();              
    lcd.setCursor(2, 0);      
    lcd.print("Anti-horario");}
  if (status_b3 == HIGH) {
     numero = '3';
     Serial.println("Numero 3 recebido - Parando motor...");
     sentido_horario = 0;
     sentido_antihorario = 0;
     motor1.moveTo(0);
     digitalWrite(pino_enable, HIGH);
     lcd.clear();        
     lcd.setCursor(2, 0);
     lcd.print("STOP"); }
  else {numero = '0';}
   // Move o motor no sentido horario
  if (sentido_horario == 1)  {motor1.moveTo(10000);}
  // Move o motor no sentido anti-horario
  if (sentido_antihorario == 1){motor1.moveTo(-10000);}
  // Comando para acionar o motor no sentido especificado
  motor1.run();
}
