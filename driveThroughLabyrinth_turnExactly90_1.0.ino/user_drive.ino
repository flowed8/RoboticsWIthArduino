void driveAhead()
{

  setMotorSpeedRight(motorSpeedRight);
  setMotorSpeedLeft(motorSpeedLeft);

  drivenTime = 0;

  while (drivenTime <= timeDrive30cm)
  {
    timer.update();
  }

  setMotorSpeedRight(1);
  setMotorSpeedLeft(1);

  setMotorSpeedRight(0);
  setMotorSpeedLeft(0);
}

void turn180()
{

  setMotorSpeedRight(-100);
  setMotorSpeedLeft(100);

  //dreht immer nach Rechts!

  if (wallLeft)
  {
    measureDistance();

    while (distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall)
    {
      measureDistance();
    }

    setMotorSpeedRight(1);
    setMotorSpeedLeft(1);

    setMotorSpeedRight(0);
    setMotorSpeedLeft(0);
  }

  else if (wallRight)
  {
    measureDistance();

    while (distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall)
    {
      measureDistance();
    }

    setMotorSpeedRight(1);
    setMotorSpeedLeft(1);

    setMotorSpeedRight(0);
    setMotorSpeedLeft(0);
  }

  else if (wallFront)
  {
    measureDistance();

    while (distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall)
    {
      measureDistance();
    }

    setMotorSpeedRight(1);
    setMotorSpeedLeft(1);

    setMotorSpeedRight(0);
    setMotorSpeedLeft(0);
  }

  else if (wallBack)
  {
    measureDistance();

    while (distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall)
    {
      measureDistance();
    }

    setMotorSpeedRight(1);
    setMotorSpeedLeft(1);

    setMotorSpeedRight(0);
    setMotorSpeedLeft(0);
  }
}

void turn90(bool dir)
{
  measureDistance();

  findWall();

  //dir = true => Rechtsdrehung
  //dir = false => Linksdrehung

  if (dir)
  {
    turnDirection = 1;
  }

  else
  {
    turnDirection = -1;
  }

  setMotorSpeedRight(-1 * turnDirection * 100);
  setMotorSpeedLeft(turnDirection * 100);

  newDis();

  if (dir)
  {
    //bei Rechtsdrehung schaut er in dieser Reihenfolge auf die Wände

    if (wallLeft)
    {
      measureDistance();
      prStr("1wallLeft");

      while (distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallRight)
    {
      measureDistance();
      prStr("2wallRight");

      while (distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallFront)
    {
      measureDistance();
      prStr("3wallFront");

      while (distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallBack)
    {
      measureDistance();
      prStr("4wallBack");

      while (distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else
    {
      newDis();
      prStr("ERROR: turn90 dir=true");
      prStr("stopped for stopTime*10");
      stopFor(stopTime * 10);
    }
  }

  else if (!dir)
  {
    //bei Linksdrehung schaut er in dieser Reihenfolge auf die Wände

    if (wallLeft)
    {
      measureDistance();

      while (distanceBackLeft != distanceBackRight or distanceBackLeft > standardDistanceFromWall or distanceBackRight > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallRight)
    {
      measureDistance();

      while (distanceFrontLeft != distanceFrontRight or distanceFrontLeft > standardDistanceFromWall or distanceFrontRight > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallFront)
    {
      measureDistance();

      while (distanceLeftBack != distanceLeftFront or distanceLeftFront > standardDistanceFromWall or distanceLeftBack > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }

    else if (wallBack)
    {
      measureDistance();

      while (distanceRightBack != distanceRightFront or distanceRightFront > standardDistanceFromWall or distanceRightBack > standardDistanceFromWall)
      {
        measureDistance();
      }

      setMotorSpeedRight(1);
      setMotorSpeedLeft(1);

      setMotorSpeedRight(0);
      setMotorSpeedLeft(0);
    }
  }
  else
  {
    newDis();
    prStr("ERROR: turn90 dir=false");
    prStr("stopped for stopTime*10");
    stopFor(stopTime * 10);
  }

  prStr("FIN");
}

void findWall()
{

  wallRight = false;
  wallLeft = false;
  wallFront = false;
  wallBack = false;

  if (distanceFrontLeft < distanceWall && distanceFrontRight < distanceWall)
  {
    wallFront = true;
  }

  if (distanceLeftFront < distanceWall && distanceLeftBack < distanceWall)
  {
    wallLeft = true;
  }

  if (distanceBackLeft < distanceWall && distanceBackRight < distanceWall)
  {
    wallBack = true;
  }

  if (distanceRightBack < distanceWall && distanceRightFront < distanceWall)
  {
    wallRight = true;
  }
}

void findHoleRightFirst()
{

  //MEMORYCHANGE

  //  for(int i, i < 4, i++){
  //    memory [i],
  //  }
  //
  if (!wallRight)
  {
    prStr("Right");
    turn90(true); //Rechtsdrehung
  }

  else if (!wallFront)
  {
    //do nothing
    prStr("Front");
  }

  else if (!wallLeft)
  {
    prStr("Left");
    turn90(false); //Linksdrehung
  }

  else
  {
    prStr("Back");
    turn180();
  }
}

void turnCal(bool turnDir)
{

  int calTurnDirRight = 1;
  int calTurnDirLeft = 1;

  //True = Rechts
  //False = Links

  if (turnDir)
    calTurnDirRight = -1;
  else
    calTurnDirLeft = -1;

  setMotorSpeedRight(calTurnDirRight * 100);
  setMotorSpeedLeft(calTurnDirLeft * 100);

  drivenTime = 0;

  while (distanceFrontLeft / 10 != distanceFrontRight / 10)
  {
    measureDistance();

    timer.update();
  }

  setMotorSpeedRight(1);
  setMotorSpeedLeft(1);

  setMotorSpeedRight(0);
  setMotorSpeedLeft(0);
}

//amirs code

void komischDreh()
{
  /*
  X is left and Right
  Y is front and back going up and down
  Z is left and right going up and down
  */

  // setup the sensor as event
  sensors_event_t event;

  // set up get event function
  bno.getEvent(&event);

  // save the current X value inside curX
  double curX = event.orientation.x;

  // save the current Y value inside curY
  double curY = event.orientation.y;

  // save the current Z value inside curZ
  double curZ = event.orientation.z;

  // print out all the stuff
  print('X = ' + curX);
  print('Y = ' + curY);
  print('Z = ' + curZ);

  //check if something is wrong
  //lets say robot in a straight line has 0/0/0

  // this part checks for a bumper
  if (curY > 10)
  {
    prStr('Bumper front');
    print(curY);
  }
  if (curY < 10)
  {
    prStr('Bumper back');
    pint(curY);
    prStr('Bumper is done');
    isBumper(1);
  }
}

// how can it be done the right way?
bool isBumper(Int val)
{
  if (Val == 1)
  {
    isBumper = true;
  }
  else
  {
    isBumper = false;
  }
}

//also amirs code but who cares, in the end we all have worked for the code
void backToPosition()
{
  /*
  X is left and Right
  Y is front and back going up and down
  Z is left and right going up and down
  */

  // setup the sensor as event
  sensors_event_t event;

  // set up get event function
  bno.getEvent(&event);

  // save the current X value inside curX
  double curX = event.orientation.x;

  // lets again say that robot in straight line has 0/0/0, CALIBIRATION IS REQUIRED FOR THE CODE TO WORK
  if (isBumper == true)
  {
    prStr('Bumper is over');
    prStr('going back to straight position');

    // check which direction we need to turn robot
    // lets say everything below 0 is left and upwoards 0 is right

    // case for turning right, because bumper made robot see in the left direction
    if (curX < 0)
    {
      prStr('Need to turn right');
      while (curX != 0)
      {
        // (i think, but not sure) lower motor speed helps the robot be more accurate
        setMotorSpeedLeft(75);
        setMotorSpeedRight(-75);
      }
    }
    // case for turning left, because bumper made robot see in the robot direction
    else if (curX > 0)
    {
      prStr('Need to turn left')
      while (curX != 0)
      {
        setMotorSpeedLeft(-75);
        setMotorSpeedRight(75);
      }
    }
  }
  else
  {
    prStr('nothing to do');
  }
  
}

void turnByDegree()
{
  //misst den Winkel und speichert ihn in xaxis
  sensors_event_t event;
  bno.getEvent(&event);

  int currentX = event.orientation.x;

  int newRotation = currentX + 90.00;
  //linksdrehung

  prInt(currentX);
  prInt(newRotation);

  stopFor(stopTime);

  setMotorSpeedRight(-100);
  setMotorSpeedLeft(100);

  while (currentX != newRotation)
  {
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