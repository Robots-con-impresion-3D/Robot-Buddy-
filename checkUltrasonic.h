//This function pings the Ultrasonic Sensor and returns a distance in CM

int checkUltra(int theEchoPin, int theTrigPin) {
  //this fucntion caluclates and returns the distance in cm

  long duration, distance; // Duration used to calculate distance
  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(theTrigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(theTrigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(theTrigPin, LOW);
  duration = pulseIn(theEchoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;
  return distance;    

}
