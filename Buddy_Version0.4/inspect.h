// This function looks in four direction to get the extent of an object

void inspect() {
  struct headPos newPosition;
  delay (1000);
  //Beep/ inspect
  Serial.println("inside Inspect");
  //tilt head
  storedAction2 (1, 3);
  //delay (1000);

  int standardDistance = 30;


  newPosition.desiredDelay = 20;
  bool somethingPresent = true;
  newPosition.baseServoAngle = baseServo.read();
  newPosition.nodServoAngle = nodServo.read();
  newPosition.tiltServoAngle = tiltServo.read();

  //Intial Positions
  int startingAngle = baseServo.read();
  int startingNodAngle = nodServo.read();
  int newAngle = baseServo.read();

  //Look to the Left
  int direction2look = -1;
  while (somethingPresent) {
    Serial.println("left");

    newAngle = newAngle - ( 1);
    newPosition.baseServoAngle = newAngle;
    Serial.println(newPosition.baseServoAngle);
    // limit extents
    if (newPosition.baseServoAngle < 10) {
      newPosition.baseServoAngle = 10;
      somethingPresent = false;
    }

    moveTo(newPosition);

    Serial.print("ultra Distance: ");
    int ultraDistance =checkUltra(echoPin, trigPin);
    Serial.println (ultraDistance);
    if (  ultraDistance > standardDistance) {
      somethingPresent = false;
      Serial.println("looked left");
      //Check in the other direction
    }

  }


  //Look to the left
  somethingPresent = true;
  newAngle = startingAngle;
  direction2look = 1;
  while (somethingPresent) {

    Serial.println("right");
    newAngle = newAngle + ( (1));
    newPosition.baseServoAngle = newAngle;

    // limit extents
    if (newPosition.baseServoAngle > 170) {
      newPosition.baseServoAngle = 170;
      somethingPresent = false;
    }

    moveTo(newPosition);
    //delay(200);

    if (checkUltra(echoPin, trigPin) > standardDistance) {
      somethingPresent = false;
      Serial.println("looked right");
      //Check in the other direction
    }

  } //end of while

  // return to start
  faceMotion.baseServoAngle = startingAngle;
  moveTo(faceMotion);

}//end of function
