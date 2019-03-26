void packShot()
{ 
  servo.write(180);
  servo.write(90);
  delay(500);
  servo.write(180);
  }

void opferFinden()
{
  int tempL = tempLeft.readObjectTempC();
  int tempR = tempRight.readObjectTempC();
  
if(tempL > 28 || tempR > 28)
{
  
  white(1);
  stopFor(5);
  turnByDegree();
  packShot();
}
  }
  
