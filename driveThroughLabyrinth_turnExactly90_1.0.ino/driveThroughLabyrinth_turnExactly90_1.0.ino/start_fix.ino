//**********Diesen Teil nicht verändern**********//
void waitForPushButton() // Warten bis der Taster gedrückt wird
{
  green(0);
  red(1);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Zum Starten");
  lcd.setCursor(0,1);
  lcd.print("Die gr\365ne");
  lcd.setCursor(0,2);
  lcd.print("Taste dr\365cken!");
  while(!taster(button1)){}//wait and do nothing}
  lcd.clear();
  lcd.noBacklight();
  green(1);
  red(0);
  delay(500);
}

void motorsTest() //Test der 4 Motoren
{
  setMotorSpeedRight(100);
  setMotorSpeedLeft(-100);
  delay(500);
  setMotorSpeedRight(-100);
  setMotorSpeedLeft(100);
  delay(1000);  
  setMotorSpeedRight(100);
  setMotorSpeedLeft(-100);
  delay(500);
  setMotorsSpeed(0);  
}

void tasterLedTest() //Test der Taser und LEDs
{
  green(0);
  red(0);
  white(0);
 
  //Tastentest
  green(1);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Dr\365cke gr\365n!");
  while(!taster(button1)){}//wait and do nothing}
  lcd.clear();
  lcd.noBacklight();
  green(0);

  red(1);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Dr\365cke gelb!");
  while(!taster(button2)){}//wait and do nothing}
  lcd.clear();
  lcd.noBacklight();
  red(0); 

  white(1);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Dr\365cke weiss!");
  while(!taster(button3)){}//wait and do nothing}
  lcd.clear();
  lcd.noBacklight();
  white(0);

  delay(500);

  //Lauflicht
  for(int i = 0; i < 10; i++)
  {
    green(1);
    delay(80);
    red(1);
    delay(80);
    white(1);
    delay(80);
    green(0);
    delay(80);
    red(0);
    delay(80);
    white(0);
    delay(80);
  }
}

void buzzerTest() // Buzzer testen
{
  // Buzzer-Startsequenz
  TimerFreeTone(buzzer, 264, 100, 5); //Frequenz, Dauer in ms, Lautstärke
  TimerFreeTone(buzzer, 297, 100, 5);
  TimerFreeTone(buzzer, 330, 100, 5);
  TimerFreeTone(buzzer, 352, 100, 5);
  TimerFreeTone(buzzer, 396, 100, 5);
  TimerFreeTone(buzzer, 440, 100, 5);
  TimerFreeTone(buzzer, 495, 100, 5);
  TimerFreeTone(buzzer, 528, 200, 5);
  delay(100);
}

void showSensorValues() // alle Sensorwerte anzeigen
{
  // Lichtsensoren
  int lr = readLight(lightRight);
  int ll = readLight(lightLeft);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Lichtsensor links:");
  lcd.setCursor(0,1);
  lcd.print(ll);
  lcd.setCursor(0,2);
  lcd.print("Lichtsensor rechts:");
  lcd.setCursor(0,3);
  lcd.print(lr);
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  lcd.noBacklight();

  // Entfernungssensoren
  lcd.backlight();
  int dfm = readDistanceFront(sensorFrontMiddle);
  lcd.setCursor(0, 0);
  lcd.print("Vorne Mitte:");
  lcd.setCursor(0,1);
  lcd.print(dfm);
  lcd.print(" cm");
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  int dfr = readDistance(sensorFrontRight);
  int dfl = readDistance(sensorFrontLeft);
  lcd.setCursor(0, 0);
  lcd.print("Vorne Links:");
  lcd.setCursor(0,1);
  lcd.print(dfl);
  lcd.print(" cm");
  lcd.setCursor(0, 2);
  lcd.print("Vorne Rechts:");
  lcd.setCursor(0,3);
  lcd.print(dfr);
  lcd.print(" cm");  
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  int dlf = readDistance(sensorLeftFront);
  int dlb = readDistance(sensorLeftBack);
  lcd.setCursor(0, 0);
  lcd.print("Links Vorne:");
  lcd.setCursor(0,1);
  lcd.print(dlf);
  lcd.print(" cm");
  lcd.setCursor(0, 2);
  lcd.print("Links Hinten:");
  lcd.setCursor(0,3);
  lcd.print(dlb);
  lcd.print(" cm");  
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  int drb = readDistance(sensorRightBack);
  int drf = readDistance(sensorRightFront);
  lcd.setCursor(0, 0);
  lcd.print("Rechts Vorne:");
  lcd.setCursor(0,1);
  lcd.print(drf);
  lcd.print(" cm");
  lcd.setCursor(0, 2);
  lcd.print("Rechts Hinten:");
  lcd.setCursor(0,3);
  lcd.print(drb);
  lcd.print(" cm");  
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  int dbl = readDistance(sensorBackLeft);
  int dbr = readDistance(sensorBackRight);
  lcd.setCursor(0, 0);
  lcd.print("Hinten Links:");
  lcd.setCursor(0,1);
  lcd.print(dbl);
  lcd.print(" cm");
  lcd.setCursor(0, 2);
  lcd.print("Hinten Rechts:");
  lcd.setCursor(0,3);
  lcd.print(dbr);
  lcd.print(" cm");  
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();  
  lcd.noBacklight();  

  // Temperatursensor
  lcd.backlight();
  double temp1 = readTempLeft(); // Oberflächentemperatur
  double temp11 = readTempLeftAir(); // Umgebungstemperatur
  lcd.setCursor(0, 0);
  lcd.print("Temp Links Objekt:");
  lcd.setCursor(0,1);
  lcd.print(temp1);
  lcd.setCursor(0, 2);
  lcd.print("Temp Links Luft:");
  lcd.setCursor(0,3);
  lcd.print(temp11);
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();
  double temp2 = readTempRight(); // Oberflächentemperatur
  double temp21 = readTempRightAir(); // Umgebungstemperatur
  lcd.setCursor(0, 0);
  lcd.print("Temp Rechts Objekt:");
  lcd.setCursor(0,1);
  lcd.print(temp2);
  lcd.setCursor(0, 2);
  lcd.print("Temp Rechts Luft:");
  lcd.setCursor(0,3);
  lcd.print(temp21);
  while(!taster(button1)){}//wait and do nothing}
  delay(200);
  lcd.clear();    
  lcd.noBacklight();
}

void showSensorValuesSerialMonitor()
{
  // Lichtsensorwerte links und rechts
  int lr = readLight(lightRight);
  int ll = readLight(lightLeft);
  Serial.print("Licht rechts: ");
  Serial.println(lr);
  Serial.print("Licht links: ");
  Serial.println(ll);
  int dfm = readDistanceFront(sensorFrontMiddle);
  int dlf = readDistance(sensorLeftFront);
  int dlb = readDistance(sensorLeftBack);
  int dbl = readDistance(sensorBackLeft);
  int dbr = readDistance(sensorBackRight);
  int drb = readDistance(sensorRightBack);
  int drf = readDistance(sensorRightFront);
  int dfr = readDistance(sensorFrontRight);
  int dfl = readDistance(sensorFrontLeft);
  Serial.print("Abstand vorne Mitte: ");
  Serial.println(dfm);
  Serial.print("Abstand links vorne: ");
  Serial.println(dlf);
  Serial.print("Abstand links hinten: ");
  Serial.println(dlb);
  Serial.print("Abstand hinten links: ");
  Serial.println(dbl);
  Serial.print("Abstand hinten rechts: ");
  Serial.println(dbr);
  Serial.print("Abstand rechts hinten: ");
  Serial.println(drb);
  Serial.print("Abstand rechts vorne: ");
  Serial.println(drf);
  Serial.print("Abstand vorne rechts: ");
  Serial.println(dfr);
  Serial.print("Abstand vorne links: ");
  Serial.println(dfl);
}
//**********Diesen Teil nicht verändern**********//
