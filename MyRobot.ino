/*
Program : Jaime Robot - MyFirstArduino
Author  : Jaime
Date    : 7/5/2022
Added Voice Control Code : 7/12/2022
Added Obstacle Avoidance Code : 7/14/2022
*/

#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A4 
#define ECHO_PIN A3 
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

// Initialize Motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   

//input motions
int val;
String voice;

//Speed value can be between 0 to 255
int Speeed = 255;
boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {
  // Set the baud rate to the bluetooth module
  Serial.begin(9600);
  myservo.attach(10 );  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
}

void loop() {
  //blueToothController();
  //voiceController();
  avoidObstacle();
}

void blueToothController()
{
if(Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
    //Start with all the motors
    Stop();

    if(val == 'F')
    {
      moveForward();
    }
    if(val == 'B')
    {
      moveBackward();
    }
    if(val == 'L')
    {
      moveLeft();
    }
    if(val == 'R')
    {
      moveRight();
    }
    if(val == 'I')
    {
      moveTopRight();
    }
    if(val == 'G')
    {
      moveTopLeft();
    }
    if(val == 'J')
    {
      moveBottomRight();
    }
    if(val == 'H')
    {
      moveBottomLeft();
    }
    if(val == 'S')
    {
      Stop();
    }
    
  }
}

void voiceController()
{
  if(Serial.available()>0) {
  voice="";
  delay(2);
  voice = Serial.readString();
  delay(2);
  Serial.println(voice);

  if (voice == "turn left") {
      moveLeft();
  }else if (voice == "left") {
      moveLeft();
  }else if(voice == "turn right") {
      moveRight();
  }else if(voice == "right") {
      moveRight();
  }else if(voice == "move forward") {
      moveForward();
  }else if(voice == "move backward") {
      moveBackward();
  }else if(voice == "move front"){
      moveForward();
  }else if(voice == "reverse"){
      moveForward();
  }else if(voice == "move back"){
      moveBackward();
  }else if(voice == "stop"){
      Stop();
  }
 }
}

void avoidObstacle()
{
  int distanceR = 0;
  int distanceL =  0;
  delay(40);
 
  if(distance<=15)
  {
    Stop();
    delay(100);
    omoveBackward();
    delay(300);
    Stop();
    delay(200);
    distanceR = lookRight();
    Serial.print("distanceR:");
    Serial.println(distanceR);
    delay(200);
    distanceL = lookLeft();
    Serial.print("distanceL:");
    Serial.println(distanceL);
    delay(200);

    if(distanceR>=distanceL)
    {
      oturnRight();
      Stop();
    }else
    {
    oturnLeft();
    Stop();
    }
 }else
 {
  omoveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveForward()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);

  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);

  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);

  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);
}

void moveBackward()
{
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);

  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);

  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);

  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);  
}

void moveLeft()
{
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);

  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);

  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);

  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);  
}

void moveRight()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);

  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);

  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);

  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);  
}

void moveTopLeft()
{
  motor1.setSpeed(Speeed);
  motor1.run(FORWARD);

  motor2.setSpeed(Speeed);
  motor2.run(FORWARD);

  motor3.setSpeed(Speeed / 3.1);
  motor3.run(FORWARD);

  motor4.setSpeed(Speeed / 3.1);
  motor4.run(FORWARD); 
}

void moveTopRight()
{
  motor1.setSpeed(Speeed / 3.1);
  motor1.run(FORWARD);

  motor2.setSpeed(Speeed / 3.1);
  motor2.run(FORWARD);

  motor3.setSpeed(Speeed);
  motor3.run(FORWARD);

  motor4.setSpeed(Speeed);
  motor4.run(FORWARD);  
}

void moveBottomLeft()
{
  motor1.setSpeed(Speeed);
  motor1.run(BACKWARD);

  motor2.setSpeed(Speeed);
  motor2.run(BACKWARD);

  motor3.setSpeed(Speeed / 3.1);
  motor3.run(BACKWARD);

  motor4.setSpeed(Speeed / 3.1);
  motor4.run(BACKWARD);
}

void moveBottomRight()
{
  motor1.setSpeed(Speeed / 3.1);
  motor1.run(BACKWARD);

  motor2.setSpeed(Speeed / 3.1);
  motor2.run(BACKWARD);

  motor3.setSpeed(Speeed);
  motor3.run(BACKWARD);

  motor4.setSpeed(Speeed);
  motor4.run(BACKWARD);
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void omoveForward() {

 if(!goesForward)
  {
    goesForward=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
   {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
   }
  }
}

void omoveBackward() {
    goesForward=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}  

void oturnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void oturnLeft() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
