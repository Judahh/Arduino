#include <Motor.h>
#include <QueueArray.h>
#include <math.h>

//Definicoes pinos Arduino ligados a entrada da Ponte H
int const motorNegativeLeftPin = 2;
int const motorPositiveLeftPin = 3;
int const motorPositiveRightPin = 5;
int const motorNegativeRightPin = 4;
int const motorSpeedRightPin = 10;
int const motorSpeedLeftPin = 9;

float intensityPercentage = 50;
int percentageMax = 100;
int intensityMax = 255;

float intensityP = intensityPercentage / percentageMax;
byte intensity = intensityP * intensityMax;

Motor motor(motorNegativeLeftPin, motorPositiveLeftPin, motorPositiveRightPin, motorNegativeRightPin, motorSpeedRightPin, motorSpeedLeftPin, intensity);


void setup()
{
  // set all the motor control pins to outputs
//  pinMode(motorSpeedRightPin, OUTPUT);
//  pinMode(motorSpeedLeftPin, OUTPUT);
//  pinMode(motorNegativeLeftPin, OUTPUT);
//  pinMode(motorPositiveLeftPin, OUTPUT);
//  pinMode(motorPositiveRightPin, OUTPUT);
//  pinMode(motorNegativeRightPin, OUTPUT);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
//  digitalWrite(motorPositiveLeftPin, 0);
//  digitalWrite(motorNegativeLeftPin, 1);
//  analogWrite(motorSpeedLeftPin, 200);
//  delay(2000);

  motor.runForward();
}

void loop() {
  demoOne();;
}
