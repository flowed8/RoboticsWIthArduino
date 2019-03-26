
void printDistance(){
  measureDistance();

  newDis();
  prInt(distanceFrontLeft);
  prInt(distanceFrontRight);
  prInt(distanceBackLeft);
  prInt(distanceBackRight);

  stopFor(stopTime);

//  newDis();
//  prInt(distanceLeftFront);
//  prInt(distanceLeftBack);
//  prInt(distanceRightFront);
//  prInt(distanceRightBack); 

  stopFor(stopTime);
}

void measureDistance(){
  distanceFrontMiddle = readDistanceFront(sensorFrontMiddle);
  
  distanceFrontLeft = readDistance(sensorFrontLeft);
  distanceFrontRight = readDistance(sensorFrontRight);

  distanceLeftFront = readDistance(sensorLeftFront);
  distanceLeftBack = readDistance(sensorLeftBack);

  distanceBackLeft = readDistance(sensorBackLeft);
  distanceBackRight = readDistance(sensorBackRight);

  distanceRightBack = readDistance(sensorRightBack);
  distanceRightFront = readDistance(sensorRightFront);
}
