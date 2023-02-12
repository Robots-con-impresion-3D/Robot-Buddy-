// Buddy Social Robot
// Created at Slant Concepts as part of the LittleBots Project
// www.arduinorobotkit.com

// This code provides Buddy with basic interaction and emotiveness based on
//proxmity sensor feedback

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

struct headPos faceMotion;  // Joint Positions of Head


//Structure for holding the Map Location Joint Angles
struct mapLoc {
  int base;
  int nod;
};
struct mapLoc worldMap[10];

//The Distances Measured at Each Location on the Map Held in Global Arrays
// From upper right, upper center, upper left, center right, ... lower left, look behind
int currentMap[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int oldMap[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Global Variables
int ready = 0;

// Startup Settings
// These modes defined to change from bluetooth, education, autonmous etc
int  robotMode = 700;
int buzzerTone = 500;

//+++++++++++++++ULTRASONIC VARIABLES+++++++++++++++++++++++++++

long readDistance;          // the output distance from the sensor

//+++++++++++++++Primary Functions+++++++++++++++++++++++++++

void moveTo( struct headPos faceMotion);      //Function for simultaneous servo motion
#include "generateAction.h"
#include "checkUltrasonic.h"
#include "storedAction.h"
#include "storedAction2.h"
#include "droidSpeak.h"
#include "servoParallelControl.h"
#include "checkMap.h"
#include "inspect.h"


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup()
{
  Serial.begin(9600); //serial baud rate

  baseServo.attach(2);
  nodServo.attach(3);
  tiltServo.attach(4);

  baseServo.write(90);        //intial positions of servos
  nodServo.write(90);
  tiltServo.write(90);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  ready = 0;
  noTone(buzzerPin);

  Serial.setTimeout(50);      //ensures the the arduino does not read serial for too long
  Serial.println("started");
  delay (2000);
  storedAction2 (1, 3);


}

void loop()
{




  // Main Operations
  // read a usb command if available
  if (Serial.available()) {

    // read what type of a command will be sent
    robotMode = Serial.parseInt();

    if (robotMode == 200) {
      faceMotion.baseServoAngle = Serial.parseInt();
      faceMotion.nodServoAngle = Serial.parseInt();
      faceMotion.tiltServoAngle = Serial.parseInt();
      //buzzerTone = Serial.parseInt();

      if (Serial.read() == '\n') {            // if the last byte is 'd' then stop reading and execute command 'd' stands for 'done'
        Serial.flush();                     //clear all other commands piled in the buffer
        Serial.print('d');                  //send completion of the command
      }
    }
  } // End of Serial Check

  //++++++++++++++++Normal Social Interaction+++++++++++++++++++++++++++

  if (robotMode == 700) {

    //Normal Interaction Mode
    Serial.println('d');                  //send syte (D for done) for readiness if connected to app or serial monitor
    Serial.flush();                     //clear all other commands piled in the buffer

    //read the distance read by the sensor
    readDistance = checkUltra(echoPin, trigPin);
    Serial.print("read distance:"); 
    Serial.println(readDistance);

    if (readDistance > 30) {
      Serial.println("Going About My Business");
      droidSpeak(buzzerPin, random(10, 25));
      //run through s set of random actions
      int randomNumOfActions = random (1, 5);
      int i;

      for (i = 1; i < randomNumOfActions; i++) {
        delay (random(100, 1000));
        generateAction(5);
        //check ultrasonic sensor
      } //end of for

      //Check a Random Map Location
      checkMap();


    }

    else if (readDistance <= 6) {
      // do something when this close
      //fast response in surprise
      Serial.println("Too Close");
      tone(buzzerPin, 1500);
      delay(200);
      tone(buzzerPin, 2500);
      delay(400);
      noTone(buzzerPin);
      droidSpeak(buzzerPin, random(1, 5));


    }

    else {
      //Inspect the Item
      Serial.println("Something to Inspect");
      droidSpeak(buzzerPin, random(1, 5));
      inspect();

      //Then Move on to a new location.
      int randomNumOfActions = random (1, 5);
      int i;

      for (i = 1; i < randomNumOfActions; i++) {
        delay (random(100, 1000));
        generateAction(6);
        //check ultrasonic sensor
      } //end of for
    } //end of the middle distance else
  } // end of 700 if mode
} // end of primary loop

//++++++++++++++++++++++++++++++FUNCTION DEFINITIONS++++++++++++++++++++++++++++++++++++++++++

void moveTo( struct headPos faceMotion) {

  int status1 = 0;
  int status2 = 0;
  int status3 = 0;
  int done = 0 ;

  while ( done == 0) {
    //move all servos to the desired position
    //this loop will cycle through the servos sending each the desired position.
    //Each call will cause the servo to iterate about 1-5 degrees
    //the rapid cycle of the loop makes the servos appear to move simultaneously
    status1 = servoParallelControl(faceMotion.baseServoAngle, baseServo, faceMotion.desiredDelay);
    status2 = servoParallelControl(faceMotion.nodServoAngle, nodServo, faceMotion.desiredDelay);
    status3 = servoParallelControl(faceMotion.tiltServoAngle, tiltServo, faceMotion.desiredDelay);

    //continue until all have reached the desired position
    if (status1 == 1 & status2 == 1 & status3 == 1 ) {
      done = 1;
    }
  }// end of while
} //function end

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
