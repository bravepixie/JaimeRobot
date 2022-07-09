/*
Program : Jaime Robot - MyFirstArduino
Author  : Jaime
Date    : 7/5/2022
*/

#include <AFMotor.h>

// Initialize Motors
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

//input motions
int val;

//Speed value can be between 0 to 255
int Speeed = 255;


void setup() {
  // Set the baud rate to the bluetooth module
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0)
  {
    val = Serial.read();

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


