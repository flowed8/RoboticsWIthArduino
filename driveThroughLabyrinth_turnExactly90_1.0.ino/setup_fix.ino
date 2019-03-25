//**********Diesen Teil nicht verändern**********//
void setupSystem()
{
  Serial.begin(9600); //Serielle Kommunikation mit 9600 Baud initialisieren (z.B. für seriellen Monitor)

  // Taster
  pinMode(touchFrontLeft, INPUT);  //Berührungssensor/Taster vorne links
  pinMode(touchFrontRight, INPUT);  //Berührungssensor/Taster vorne rechts
  pinMode(button1, INPUT);  //Taster 1
  pinMode(button2, INPUT);  //Taster 2
  pinMode(button3, INPUT);  //Taster 3
  // LEDs
  pinMode(led1, OUTPUT);  //LED 1
  pinMode(led2, OUTPUT);  //LED 2
  pinMode(led3, OUTPUT);  //LED3
  // Servo
  servo.attach(SERVO); //Servo Anschluss
  // Buzzer
  pinMode(buzzer, OUTPUT);  //Buzzer-Pin als Ausgang
  // LCD-Display
  lcd.begin(20, 4); //LCD Display initialisieren 20 zeichen 4 Zeilen
  // Melexis Temperatursensoren
  tempLeft.begin(); //Temperatursensor 1 initialisieren
  tempRight.begin(); //Temperatursensor 2 initialisieren
  bno.begin();
  delay(1000);
  bno.setExtCrystalUse(true);
 
  // Timer-Event alle 1000ms
  timer.every(timeUnit, everyTimeUnit);

  // Begrüßungstext
  lcd.setCursor(0, 0);
  lcd.print("Leobot 3.0");
  delay(300);
  lcd.setCursor(0,1);
  lcd.print("Altes Gymi Leoben");
  delay(300);
  lcd.setCursor(0,2);
  lcd.print("www.gym-leoben.net");
  delay(300);
  lcd.setCursor(0,3);
  lcd.print("2018");
  delay(2000);
  lcd.clear();
  lcd.noBacklight();
}
//**********Diesen Teil nicht verändern**********//
