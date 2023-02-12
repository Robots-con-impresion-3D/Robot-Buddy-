void storedAction2(int positionSelected, int theSpeed) {


  struct headPos newPosition;
  //Beep/ inspect
  Serial.println("inside stored action++++++++++++++++");
  newPosition.desiredDelay = theSpeed;
  bool somethingPresent = true;
  newPosition.baseServoAngle = baseServo.read();
  newPosition.nodServoAngle = nodServo.read();
  newPosition.tiltServoAngle = 90;
  Serial.println("Stoed Action");

  if (positionSelected == 1) {
    Serial.println("tilting");
    int randomNumOfActions = random (2, 6);
    int i;

    for (i = 1; i < randomNumOfActions; i++) {

      newPosition.tiltServoAngle = 90 + 50;
      moveTo(newPosition);
      newPosition.tiltServoAngle = 90 - 50;
      moveTo(newPosition);
      //check ultrasonic sensor
    } //end of for

  }






}

/*


  int waypoint = 0;
  int theJoint = 0;     // one of the joints in a trajectory array
  int trajSize = 0;


  struct headPos newPosition;
  newPosition.desiredDelay = theSpeed;

  if (positionSelected == 1) {

    // up
    int trajSize = 1;
    int trajectory[trajSize][5] = {{101, 65, 153, 75, 5}   };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo (newPosition);
      waypoint++;


    }

  }

  else if (positionSelected == 2) {

    //shake
    int trajSize = 9;
    int trajectory[trajSize][5] = {{97, 65, 130, 75, 5}, {97, 101, 130, 75, 5}, {97, 71, 130, 75, 5}, {97, 114, 130, 75, 5}, {97, 70, 130, 75, 5}, {97, 107, 130, 75, 5}, {101, 79, 146, 75, 8}, {101, 56, 146, 75, 8}, {101, 81, 146, 75, 8}   };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo (newPosition);
      waypoint++;


    }

  }


  else if (positionSelected == 6) {

    //nod head
    int trajSize = 9;
    int trajectory[trajSize][5] = {{97, 70, 130, 75, 5}, {97, 70, 117, 75, 5} , {97, 70, 141, 75, 5}, {97, 70, 112, 75, 5}, {97, 70, 143, 75, 5}, {97, 70, 115, 75, 5}, {97, 70, 146, 75, 5}, {97, 70, 115, 75, 5}, {97, 70, 144, 75, 5}  };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo (newPosition);
      waypoint++;


    }

  }


  else if (positionSelected == 7) {

    //hang and shake
    int trajSize = 5;
    int trajectory[trajSize][5] = {{101, 65, 111, 75, 12}, {101, 99, 111, 75, 8} , {101, 43, 111, 75, 8}, {101, 101, 111, 75, 8}, {101, 48, 111, 75, 8}  };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo (newPosition);
      waypoint++;


    }

  }



  else if (positionSelected == 9) {

    //excited
    int trajSize = 11;
    int trajectory[trajSize][5] = {{89, 76, 143, 5, 5}, {114, 76, 143, 5, 5} , {87, 76, 143, 5, 5}, {114, 76, 143, 5, 5}, {88, 76, 143, 5, 5}, {121, 76, 143, 5, 5}, {91, 76, 143, 5, 5}, {115, 76, 143, 5, 5}, {88, 76, 143, 5, 5}, {117, 76, 143, 5, 5}, {96, 76, 143, 5, 5}  };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo (newPosition);
      waypoint++;


    }

  }

      else if (positionSelected == 10) {

  //Jump
    int trajSize = 3;
    int trajectory[trajSize][5] = {{97, 70, 160, 75, 10}, {97, 70, 65, 75, 1} , {97, 70, 130, 75, 5}  };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
           newPosition.desiredDelay = trajectory[waypoint][theJoint + 4];
      moveTo (newPosition);
      waypoint++;


    }
      }



  else {
    //nod head
    int trajSize = 9;
    int trajectory[trajSize][5] = {{97, 70, 130, 75, 5}, {97, 70, 117, 75, 5} , {97, 70, 141, 75, 5}, {97, 70, 112, 75, 5}, {97, 70, 143, 75, 5}, {97, 70, 115, 75, 5}, {97, 70, 146, 75, 5}, {97, 70, 115, 75, 5}, {97, 70, 144, 75, 5}  };
    while (waypoint < trajSize) {
      newPosition.tiltServoAngle = trajectory[waypoint][theJoint];
      newPosition.baseServoAngle = trajectory[waypoint][theJoint + 1];
      newPosition.nodServoAngle = trajectory[waypoint][theJoint + 2];
      moveTo(newPosition);
      waypoint++;


    }
  }







  }

*/
