
//Header Files
#include "LittleBots_Board_Pins.h"

// Libraries
#include <Servo.h>  //arduino library
#include <math.h>   //standard c library

// Servos
Servo baseServo;
Servo nodServo;
Servo tiltServo;

// Robot Joint Motion Stuctures
struct headPos {
  int baseServoAngle;
  int nodServoAngle ;
  int tiltServoAngle ;
  int desiredDelay ;
};








void setup() {
Serial.begin(9600); //serial baud rate

  baseServo.attach(2);
  nodServo.attach(3);
  tiltServo.attach(4);

  baseServo.write(90);        //intial positions of servos
  nodServo.write(175);
  tiltServo.write(90);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

 
  noTone(buzzerPin);

  Serial.setTimeout(50);      //ensures the the arduino does not read serial for too long
  Serial.println("started");
  delay (2000);




}

void loop() {
  // put your main code here, to run repeatedly:

}
