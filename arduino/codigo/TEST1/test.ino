


#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);
int angle;
// the previous reading from the analog input
int previous = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

void setup() {
  // set the speed of the motor to 30 RPMs
  Serial.begin(9600);  // attaches the servo on pin 9 to the servo object 

  stepper.setSpeed(70);
  lcd.begin(16, 2);
  lcd.print("AAAAAAAAAAAAAAAAAAA");
  pinMode(potpin,INPUT);


}

void loop() {
  // get the sensor value
  float val = analogRead(A0);
  angle = map(val, 0, 1023, -179, 179);     // scale it to use it with the servo (value between 0 and 180) 
  float passos; 
  passos = angle/1.8;
  lcd.clear();
  lcd.print("Angulo: ");
  lcd.print(angle);
  Serial.println(angle);
  Serial.println(passos);
  
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(passos);
  delay(100);
  // remember the previous value of the sensor
}