/*
 *  Motor.h
 *
 */

// header defining the interface of the source.
#ifndef MOTOR_H
#define Motor_H

// include Arduino basic header.
#include <Arduino.h>

class Motor{
  public:
    Motor(int motorNegativeLeftPin, int motorPositiveLeftPin, int motorPositiveRightPin, int motorNegativeRightPin, int motorSpeedRightPin, int motorSpeedLeftPin, byte intensity);
    byte getIntensity(float intensityPercentage);
    void setIntensity(byte intensity);
    void runBackwards();
    void runForward();
    void runBackwardsLeft();
    void runBackwardsRight();
    void runForwardLeft();
    void runForwardRight();
    void turnLeft();
    void turnRight();
    void runBackwards(byte intensity);
    void runForward(byte intensity);
    void runBackwardsLeft(byte intensity);
    void runBackwardsRight(byte intensity);
    void runForwardLeft(byte intensity);
    void runForwardRight(byte intensity);
    void turnLeft(byte intensity);
    void turnRight(byte intensity);
    void brake(byte intensity);
    void brake();
    void neutral();
  private:
    byte intensity;
    int motorNegativeLeftPin, motorPositiveLeftPin, motorPositiveRightPin, motorNegativeRightPin, motorSpeedRightPin, motorSpeedLeftPin;
    
}; 

#endif // MOTOR_H
