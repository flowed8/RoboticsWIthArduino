//**********Diesen Teil nicht verändern**********//

// Tasterzustand auslesen
// Ports, T1, button2, button3
bool taster(int port)
{
  if (digitalRead(port)) return HIGH;
  else return LOW;
}

// LEDs ein und ausschalten
// led1 = grün
// led2 = rot
// led3 = weiß
void green(int state)
{
  if (state == 1) digitalWrite(led1, HIGH);
  else digitalWrite(led1, LOW); 
}
void red(int state)
{
  if (state == 1) digitalWrite(led2, HIGH);
  else digitalWrite(led2, LOW); 
}
void white(int state)
{
  if (state == 1) digitalWrite(led3, HIGH);
  else digitalWrite(led3, LOW); 
}


// Helligkeitsmessung
// Werte zwischen 0 und 1024
// 0 = hell
// 1024 = schwarz
int readLight(int port)
{
  int light = analogRead(port);
  return light;
}

// Abstandsmessung Sharp GP2Y0A41SK0F 4-30cm
// 8 Sensoren, 2 an allen Seiten
// in cm
int readDistance(int port)
{
  float volts = analogRead(port)*0.0048828125;  // Wert vom sensor * (5/1024)
  int distance = 130 * pow(volts, -1); // mathematische Funktion entsprechend der Datenblatt-Kennlinie
  return distance;
}

// Abstandsmessung Sharp GP2Y0A21YK0F 10-80cm
// 1 Sensor vorne
// in cm
int readDistanceFront(int port)
{
  float volts = analogRead(port);
  int distance = 10 * pow((3027.4 / volts), 1.2134); // mathematische Funktion entsprechend der Datenblatt-Kennlinie
  return distance;
}

// Temperaturmessung in Grad Celsius
// Objekttemperatur
// links
double readTempLeft()
{
  double temp = tempLeft.readObjectTempC();
  return temp;
}
//rechts
double readTempRight()
{
  double temp = tempRight.readObjectTempC();
  return temp;
}
// Lufttemperatur
// links
double readTempLeftAir()
{
  double temp = tempLeft.readAmbientTempC();
  return temp;
}
//rechts
double readTempRightAir()
{
  double temp = tempRight.readAmbientTempC();
  return temp;
}

// Motorspeed: Werte/Speed -400 bis 400
// Motorspeed rechts
void setMotorSpeedRight(int spd)
{
  motors.setM2Speed(-spd);
}
// Motorspeed links
void setMotorSpeedLeft(int spd)
{
  motors.setM1Speed(spd);
}
// Motorspeed links und rechts
void setMotorsSpeed(int spd)
{
  motors.setM2Speed(-spd);  
  motors.setM1Speed(spd);
}

//**********Diesen Teil nicht verändern**********//
