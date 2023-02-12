void checkMap() {



  //Define the Map Locations
  //Upper Row
  worldMap[0].base = 10;
  worldMap[0].nod = 90;

  worldMap[1].base = 90;
  worldMap[1].nod = 90;

  worldMap[2].base = 170;
  worldMap[2].nod = 90;

  //CEnter Row
  worldMap[3].base = 10;
  worldMap[3].nod = 135;

  worldMap[4].base = 90;
  worldMap[4].nod = 135;

  worldMap[5].base = 170;
  worldMap[5].nod = 135;

  //Lower Row
  worldMap[6].base = 10;
  worldMap[6].nod = 170;

  worldMap[7].base = 90;
  worldMap[7].nod = 170;

  worldMap[8].base = 170;
  worldMap[8].nod = 170;

  //Check Behind

  worldMap[9].base = 90;
  worldMap[9].nod = 10;

  //Choose a random part of the map to inspect
  int randomMapLocation = random(0, 10);  //10 is exluded in the random selection
  Serial.print("Checking Map: ");
  Serial.println(randomMapLocation);

  //Input the Joint Angles
  faceMotion.baseServoAngle = worldMap[randomMapLocation].base ;
  faceMotion.nodServoAngle = worldMap[randomMapLocation].nod ;
  faceMotion.tiltServoAngle = random (20, 150);
  faceMotion.desiredDelay = random(3, 5);
  
  moveTo(faceMotion);

  //Move Coordinates to Old Map before updating map
  oldMap[randomMapLocation] = currentMap[randomMapLocation];
  
  //check ultrasonic Sensor
  readDistance = checkUltra(echoPin, trigPin);
  
    //Update the Map
  currentMap[randomMapLocation] = readDistance;
  
  //Make decision about change from last time Inspect or Ignore
  //if (abs(oldMap[randomMapLocation - currentMap[randomMapLocation])> 4){
        //do something
        // Explore and interact with it
  
  //   }



} // function end
