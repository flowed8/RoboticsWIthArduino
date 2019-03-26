void driveAhead () {
    
  setMotorSpeedRight(motorSpeedRight);
  setMotorSpeedLeft(motorSpeedLeft);

  drivenTime = 0;
  
  while(drivenTime <= timeDrive30cm){
      timer.update();
  }
  
  setMotorSpeedRight(1);
  setMotorSpeedLeft(1);

  setMotorSpeedRight(0);
  setMotorSpeedLeft(0);
  
}

void turn180(){

    setMotorSpeedRight(-100);
    setMotorSpeedLeft(100);

    //dreht immer nach Rechts!
    
    if(wallLeft){
    measureDistance();


      while(distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallRight){
        measureDistance();

      while(distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallFront){
        measureDistance();

      while(distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall){
        measureDistance();
      }
      

      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if(wallBack){
        measureDistance();
      
      while(distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    } 
}

void turn90(bool dir){
  measureDistance();

  findWall();
  
  //dir = true => Rechtsdrehung
  //dir = false => Linksdrehung
  
  if (dir){
    turnDirection = 1;    
  }

  else{
    turnDirection = -1;
  }

setMotorSpeedRight(-1 * turnDirection *100);
setMotorSpeedLeft(turnDirection * 100);

newDis();

  if (dir){
    //bei Rechtsdrehung schaut er in dieser Reihenfolge auf die Wände
    
    if(wallLeft){
    measureDistance();
      prStr("1wallLeft");
      
      while(distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallRight){
        measureDistance();
      prStr("2wallRight");
      
      while(distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallFront){
        measureDistance();
      prStr("3wallFront");
      
      while(distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if(wallBack){
        measureDistance();
      prStr("4wallBack");
      
      while(distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    } 

    else{
      newDis();
      prStr("ERROR: turn90 dir=true");
      prStr("stopped for stopTime*10");
      stopFor(stopTime*10);
      
    }
  }
  
  else if(!dir){
    //bei Linksdrehung schaut er in dieser Reihenfolge auf die Wände

        if(wallLeft){
    measureDistance();
      
      while(distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallRight){
        measureDistance();
      
      while(distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
    else if(wallFront){
        measureDistance();
      
      while(distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if(wallBack){
        measureDistance();
      
      while(distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall){
        measureDistance();
      }
      
      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);
    
      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
    
  }
  else{
      newDis();
      prStr("ERROR: turn90 dir=false");
      prStr("stopped for stopTime*10");
      stopFor(stopTime*10);
      
  }

  prStr("FIN");

}

void findWall(){

wallRight = false;
wallLeft = false;
wallFront = false;
wallBack = false;

  if(distanceFrontLeft < distanceWall && distanceFrontRight < distanceWall){
    wallFront = true;
  }

  if( distanceLeftFront < distanceWall && distanceLeftBack < distanceWall){
    wallLeft = true;
  }
  
  if(distanceBackLeft < distanceWall && distanceBackRight < distanceWall){
    wallBack = true;
  }

  if( distanceRightBack < distanceWall && distanceRightFront < distanceWall){
    wallRight = true;
  }
  
}

void findHoleRightFirst(){
  
  //MEMORYCHANGE

//  for(int i, i < 4, i++){
//    memory [i], 
//  }
//  
  if (!wallRight){
    prStr("Right");
    turn90(true); //Rechtsdrehung
    
  }

  else if (!wallFront){
    //do nothing
    prStr("Front");
  }

  else if (!wallLeft){
    prStr("Left");
    turn90(false); //Linksdrehung

  }

  else {
    prStr("Back");
    turn180();  
  }
}

void turnCal(bool turnDir){
  
  int calTurnDirRight = 1;
  int calTurnDirLeft = 1;

  //True = Rechts
  //False = Links
  
  if (turnDir) calTurnDirRight = -1;
  else  calTurnDirLeft = -1;
  
  setMotorSpeedRight(calTurnDirRight * 100);
  setMotorSpeedLeft(calTurnDirLeft * 100);

  drivenTime = 0;
  
  while(distanceFrontLeft/10 != distanceFrontRight/10){
    measureDistance();
    
    timer.update();
  }
  
  setMotorSpeedRight(1);
  setMotorSpeedLeft(1);

  setMotorSpeedRight(0);
  setMotorSpeedLeft(0);  
}

void turnByDegree() 
{
  //misst den Winkel und speichert ihn in xaxis
  sensors_event_t event; 
  bno.getEvent(&event);
  
  int currentX = event.orientation.x;

  int newRotation = currentX + 89.00;

  if (newRotation > 360) newRotation = newRotation - 360;
  //linksdrehung 

  prInt(currentX);
  prInt(newRotation);

  stopFor(stopTime);
  
  setMotorSpeedRight(-100);
  setMotorSpeedLeft(100);

  while (currentX != newRotation){
    //do nothing

      sensors_event_t event; 
      bno.getEvent(&event);
  
    currentX = event.orientation.x;

    //prStr("rotating");
    prInt(currentX);
  }
  
  setMotorSpeedRight(0);
  setMotorSpeedLeft(0);
      
  newDis();
  prStr("rotating finished");
    
  /* Display the floating point data */


  
}
