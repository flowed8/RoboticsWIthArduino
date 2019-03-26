//**********Diesen Teil nicht verändern**********//
// Bibliotheken
#include <Wire.h> //I2C-Basis
#include <Timer.h> //Timer
#include <LiquidCrystal_I2C.h> //I2C-LCD-Display
#include <TimerFreeTone.h> //Töne für Buzzer
#include <Servo.h> //Servosteuerung
#include <Adafruit_MLX90614.h> //MLX 90614 Temperatursensor
#include <DualVNH5019MotorShield.h> // Pololu Dual-Motordriver
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
//
// Objekte
Timer timer;//Timer-Objekt
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //lcd = LCD-Display-Objekt, 0x27 = I2C-Adresse
Servo servo; //Servo-Objekt
DualVNH5019MotorShield motors; // Pololu Dual-Motordriver Objekt
Adafruit_MLX90614 tempLeft = Adafruit_MLX90614(); //Temperatursensor 1 - Standardadresse 0x5a
Adafruit_MLX90614 tempRight = Adafruit_MLX90614(0x55); //Temperatursensor 2 - Adresse 0x55
Adafruit_BNO055 bno = Adafruit_BNO055(55); //Drehsensor 
//Skizze Distanzsensoren(A) und Motoren(m)

//        vorn
//
//   /\    /\    /\  
//   A3====A2====A10  
//  <A4          A9> 
//   |  m11  m21  |
//   |            |
//   |            |
//   |  m12  m22  |
//  <A5          A8> 
//   A6==========A7  
//   \/          \/  
//       hinten
// 
// sensor[OrtamRoboter & auch Ausrichtung!][Ort am Roboter]
//
/*Moegliche Fehlerquellen:
measureDistance() wird in findWall, findHoleRightFirst nicht aufgerufen
measureDistance() muss also im loop stehen

Unlike BASIC or JAVA, the C compiler does no checking to see if array access is within legal bounds of the array size that you have declared.
*/

// Globale Variablen und Konstanten

// Konstanten
//Time
const int timeUnit = 20;
// Lichtsensoren
const int lightRight = A14; //QRD1114 IR-Senor analoger Input-Pin rechts
const int lightLeft = A15; //QRD1114 IR-Senor analoger Input-Pin links
const int blackValue = 900;
// Distanzsensoren
const int sensorFrontMiddle = A2; //front middle GP2Y0A21YK0F Sharp-Distanz-Sensor 10-80 
const int sensorFrontLeft = A3; //right front GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorLeftFront = A4; //right back GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorLeftBack = A5; //back right GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorBackLeft = A6; //back left GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorBackRight = A7; //left back GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorRightBack = A8; //left front GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorRightFront = A9; //front left GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30
const int sensorFrontRight = A10; //front right GP2Y0A41SK0F Sharp-Distanz-Sensor 4-30

int distanceFrontMiddle = 0;
int distanceFrontLeft = 0;
int distanceLeftFront = 0;
int distanceLeftBack = 0;
int distanceBackLeft = 0;
int distanceBackRight = 0;
int distanceRightBack = 0;
int distanceRightFront = 0;
int distanceFrontRight = 0;

const int limitOrientationCalibFront = 5; //Ab welcher Distanzdifferenz zwischen den Frontsensoren die AUSRICHTUNG kalibriert wird 
const int limitOrientationCalibBack = 5; //Ab welcher Distanzdifferenz zwischen den Backsensoren die AUSRICHTUNG kalibriert wird

const int standardDistanceFromWall = 200;
const int maxDistanceFromWall = 200; //Wenn Distanz unter diesem Wert, dann wird kalibriert
const int distanceWall = 120; /*distanz kleiner als dieser Wert == Wand;
sollte größer als standardDistanceFromWall sein,
um Fehlerquelle durch ungerade Ausrichtung etc. zu vermeiden */
// Buzzer
int const buzzer = 11; //Pin-Nr. Buzzer
int const SERVO = 13; //Pin-Nr. Servo
// Taster
int const touchFrontLeft = 23; //Berührungssensor/taster vorne links
int const touchFrontRight = 25; //Berührungssensor/taster vorne rechts
int const button1 = 27; //Taster 1 grün
int const button2 = 29; //Taster 2 gelb
int const button3 = 31; //Taster 3 weiß
// Leds
int const led1 = 33; //LED 1
int const led2 = 35; //LED 2
int const led3 = 37; //LED 3

//Fahrt
int const timeDrive30cm = 1950;
int const timeTurnLeft = 2300;
int const timeTurnRight = 2300;

int const exactly90degreeTime = 200;

int const motorSpeedRight = 100;
int const motorSpeedLeft = 100;

int const stopTime = 2000;

// Variablen
int line = 0;
bool isBlack = false;
int drivenTime = 0;
int stoppedTime = 0;
int turnDirection = 1;



//Wand finden

bool wallRight = false;
bool wallLeft = false;
bool wallFront = false;
bool wallBack = false;

//Memory 
//byte memory[4];

//**********Diesen Teil nicht verändern**********//



void setup() 
{
  
  setupSystem(); // System-SETUP (obligatorisch)
  waitForPushButton(); //Warten auf Taster (obligatorisch)
  
  //tasterLedTest(); // Test der Tasten (grün, gelb, weiß) und der LEDs (grün, rot, weiß) (optional)
  //buzzerTest(); // Melodie mit dem Buzzer abspielen (optional)
  //showSensorValues(); // Anzeigen der Sensorwerte am LCD-Display (optional)
  //showSensorValuesSerialMonitor(); // Anzeigen der Sensorwerte im SerialMonitor mit 9600 Baud (optional)
  //motorsTest(); // Test der vier Motoren (optional)
  
  
  // Eigener Code
  // Dieser Code wird nur einmal ausgeführt


}

void loop() 
{
  //Timer
 // timer.update();

  //turn90(true);

 // stopFor(stopTime);

  packShot();

  turnByDegree();

  //stopFor(99000);
}
