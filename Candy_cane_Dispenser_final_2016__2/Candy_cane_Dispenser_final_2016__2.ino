#include <Servo.h>
//#include <SimpleTimer.h>

//SimpleTimer timer;

Servo servoA;
Servo servoB;
Servo servoC;
Servo servo1;
Servo servo2;

//Whether Candy cane has been dispensed and keeps track of whether the servo has candy canes
bool hasCandy = true;
int servoTracker = 1;
bool hasDispensed;


//timer
unsigned long starttime;
unsigned long endtime;
unsigned long previousMillis = 0;
const long interval = 1000;
int ledState = LOW;
int servoState = (90);
int ledPin;

//global variable for default LED blink time
int timeOn = 100;
int timeOff = 400;

//assigns names to pins
const int sensor1 = 22;
const int sensor2 = 23;
const int startButton = 1;
const int startLight = 2;
const int arch1 = 27;
const int arch2 = 29;
const int arch3 = 31;
const int arch4 = 33;
const int arch5 = 35;
const int boxOne1 = 37;
const int boxOne2 = 39;
const int boxOne3 = 41;
const int boxOne4 = 43;
const int drop1 = 45;
const int drop2 = 47;
const int door = 48;
const int error = 49;

///LED PWM
int brightness = 0;
int fadeAmount = 50;

String on = "on";
String off = "off";

//Sequence for BoxOne
void boxOne() {
  int timeOn = 300;
  int timeOff = 400;
  servo1.write(170);
  delay(500);
  ledOn(boxOne1, timeOn, timeOff, 6);
  servo1.write(140);
  delay(500);
  ledOn(boxOne2, timeOn, timeOff, 6);
  servo1.write(110);
  delay(500);
  ledOn(boxOne3, timeOn, timeOff, 6);
}

//Turns LED on and off for time specified in function call. You can also pick how many times it repeats.
void ledOn (int pin, int timeOn, int timeOff, int repeatTimes) {
  for (int i = 0; i < repeatTimes; i++) {
    starttime = millis();
    endtime = starttime;
    digitalWrite(pin, HIGH);
    while ((endtime - starttime) <= timeOn) {
      endtime = millis();
    }
    digitalWrite(pin, LOW);
    starttime = millis();
    endtime = starttime;
    while ((endtime - starttime) <= timeOff) {
      endtime = millis();
    }
  }
}

//fades LED on AND off
void fadeLED () {
  analogWrite(startLight, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }


}

//fades LED's on OR off
void fadeOnOff(int pin, String toDo) {
  int brightnesOn = 0;
  int brightnesOff = 255;
  int fadeAmoutOff = 5;

  if (toDo = on) {
    while (brightnesOn < 255) {
      brightnesOn = brightnesOn + fadeAmoutOff;
      analogWrite(pin, brightnesOn);
      delay(5);
    }
  }
  if (toDo = off) {
    while (brightnesOff > 0) {
      brightnesOff = brightnesOff - fadeAmoutOff;
      analogWrite(pin, brightnesOff);
      delay(5);
    }
  }
}

//runs ARCH LED's
void arch () {
  int timeOn = 300;
  int timeOff = 10;
  ledOn(arch1, timeOn, timeOff, 1);
  ledOn(arch2, timeOn, timeOff, 1);
  ledOn(arch3, timeOn, timeOff, 1);
  ledOn(arch4, timeOn, timeOff, 1);
  ledOn(arch5, timeOn, timeOff, 1);
}


//runs ARCH LED's
void archBackwards() {
  int timeOn = 150;
  int timeOff = 2;
  ledOn(arch5, timeOn / 2, timeOff / 2, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch4, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch3, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch2, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch1, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(startLight, timeOn, timeOn, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(startLight, timeOn, timeOn, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(startLight, timeOn, timeOn, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch2, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch3, timeOn, timeOff, 1);

  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch4, timeOn, timeOff, 1);
  if (digitalRead(startButton) == 0) {
    return;
  }
  ledOn(arch5, timeOn / 2, timeOff / 2, 1);
}

void dropLights () {
  int timeOn = 300;
  int timeOff = 10;
  ledOn(drop1, timeOn, timeOff, 1);
  ledOn(drop2, timeOn, timeOff, 1);
  timeOn = 150;
  timeOff = 100;
  ledOn(door, timeOn, timeOff, 30);
}

//////////////////////   TEST   ///////////////////////////////
byte chaseArray[] = {3, 6, 9, 10, 11}; // Create array for LED pins
int ledDelay(150); // delay between changes
int direction = 1; //starting direction
int currentLED = 0; //the current LED
unsigned long changeTime; //stores a 32-bit variable


void changeLED() {
  for (int x = 0; x < 5; x++) { // turn off all LED's
    digitalWrite(chaseArray[x], LOW);
  }
  digitalWrite(chaseArray[currentLED], HIGH); // turn on the current LED
  currentLED += direction; // increment by the direction value
  // change direction if we reach the end
  if (currentLED == 4) {
    direction = -1; //once the LED reaches the last position it goes back the other way
  }
  if (currentLED == 0) {
    direction = 1; //once it reaches the first position, it goes the other way
  }
}

//moves Servo TIMER
void moveServo (Servo servo, int x) {
  starttime = millis();
  endtime = starttime;
  while ((endtime - starttime) <= 50) {
    servo.write(x);
    endtime = millis();
  }
}


void errorLights () {
  int one = 1;
  while (one = 1) {
    ledOn (boxOne4, 100, 100, 1); //blinks LED's if out of candy canes
    ledOn (error, 100, 100, 1);
  }
}

int incremementServoTracker (int servoTracker) {
  servoTracker += 1;
  if (servoTracker == 4)  {
    servoTracker = 1;
  }
  return servoTracker;
}


//dispenses Candy Canes
void dispenseCandyCane() {
  hasDispensed = false;

  do {
    if (hasCandy == true) {
      spinCandyServo();
    } else {
      errorLights();
    }
  } while (hasDispensed == false);
  servoTracker = incremementServoTracker(servoTracker);
}

//Spins servos to dispense candy cane
bool spinCandyServo () {
  int counter = 1;
  while (hasDispensed == false && counter <= 3 ) {
    starttime = millis();
    endtime = starttime;
    while ((endtime - starttime) <= 5000 &&  hasDispensed == false) {
      endtime = millis();
      switch (servoTracker) {
        case 1:
          Serial.print(endtime);
          Serial.print('\n');
          servoA.write(105);
          servoB.write(105);
          break;
        case 2:
          servoB.write(105);
          servoC.write(105);
          break;
        case 3:
          servoA.write(105);
          servoC.write(105);
          break;
        default:
          break;
      }
      if (digitalRead(sensor1) == 0 || digitalRead(sensor2) == 0) {
        hasDispensed = true;
      }
    }
    //stops servo
    servoA.write(90);
    servoB.write(90);
    servoC.write(90);
    servoTracker = incremementServoTracker(servoTracker);
    counter += 1;
  }

  if (hasDispensed == false) {
    hasCandy = false;
  }
  return hasDispensed;
}

void sensorCheck() {
  while (digitalRead(sensor1) == 0 || digitalRead(sensor2) == 0) {
    ledOn (boxOne4, 100, 100, 1); //blinks LED's if out of candy canes
    ledOn (error, 50, 50, 2);
    digitalWrite(startLight, LOW);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);//output to screen

  servoA.attach(A0);//ServoA
  servoB.attach(A1);//ServoB
  servoC.attach(A2);//ServoC
  servo1.attach(A3);//Servo1
  servo2.attach(A4);//Servo2

  pinMode(1, INPUT);//
  pinMode(2, OUTPUT);//
  pinMode(22, INPUT);//
  pinMode(23, INPUT);//
  pinMode(27, OUTPUT);//
  pinMode(29, OUTPUT);//
  pinMode(31, OUTPUT);//
  pinMode(33, OUTPUT);//
  pinMode(35, OUTPUT);//
  pinMode(37, OUTPUT);//
  pinMode(39, OUTPUT);//
  pinMode(41, OUTPUT);//
  pinMode(43, OUTPUT);//
  pinMode(45, OUTPUT);//
  pinMode(47, OUTPUT);//
  pinMode(48, OUTPUT);//
  pinMode(49, OUTPUT);//

  changeTime = millis();//time changes by milliseconds
}

// the loop function runs over and over again forever
void loop() {

  if (digitalRead(startButton) == 0) {
    digitalWrite(startLight, LOW);
    delay(1000);
    arch();
    boxOne();
    dispenseCandyCane();
    dropLights();
    servo1.write(90);
  }
  else {
    archBackwards();
    //fadeLED();
    sensorCheck();
  }
}

