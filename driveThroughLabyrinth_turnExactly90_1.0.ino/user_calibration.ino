void calibration(){
  prStr("Calibration?");
  
  if (distanceFrontLeft < maxDistanceFromWall && distanceFrontRight < maxDistanceFromWall){
    calibrateFront();
    prStr("Front Calibration?");

    prInt(distanceFrontLeft);
    prInt(distanceFrontRight);
  }

  if (distanceBackLeft < maxDistanceFromWall && distanceBackRight < maxDistanceFromWall){
    calibrateBack();
  }
}

//turnCal(true) => dreht sich zuerst nach rechts;
//turnCal(false) => dreht sich zuerst nach links;
void calibrateFront(){
  if (abs(distanceFrontLeft - distanceFrontRight) > limitOrientationCalibFront){
    newDis();
    prStr("FRONT CALIBRATION!!!");
    
    if(distanceFrontLeft < distanceFrontRight){
      turnCal(true);
    }
    
    else{
      turnCal(false);
    }
  }
}

void calibrateBack(){
    if (abs(distanceBackLeft - distanceBackRight) > limitOrientationCalibBack){
    if(distanceFrontLeft < distanceFrontRight){
      turnCal(true);
    }
    
    else{
      turnCal(false);
    }
  }
}
