//Function that creates a single random position and speed (based on a seed speed)
// Then drive the servos to that position
void generateAction(int aSpeed) {
  int waypoint = 0;
  int theJoint = 0;     // one of the joints in a trajectory array
  int trajSize = 0;
  int baseSpeed = aSpeed;   //this is the baseline speed
  int usedSpeed = aSpeed;
  struct headPos newPosition;

  newPosition.tiltServoAngle = random (20, 150); //actually nod) 
  newPosition.baseServoAngle = random (10, 170);
  newPosition.nodServoAngle = random (80, 150); //50 min j(bottom, top)

  int minSpeed = baseSpeed - 3;
  if (minSpeed < 2){
    minSpeed = 2;
  }

  usedSpeed = random (minSpeed, baseSpeed+3);
  //Serial.println("usedSpeed");
  //Serial.println ( usedSpeed)
  newPosition.desiredDelay = usedSpeed;
  moveTo (newPosition);

} // function end
