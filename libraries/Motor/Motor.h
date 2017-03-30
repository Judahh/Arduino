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

    enum Run{
        none=0,
        backwardsState=1,
        forwardState=2,
        backwardsLeftState=3,
        backwardsRightState=4,
        forwardLeftState=5,
        forwardRightState=6,
        leftState=7,
        rightState=8,
        brakeState=9,
        neutralState=10
    };


  private:
    byte intensity;
    int motorNegativeLeftPin, motorPositiveLeftPin, motorPositiveRightPin, motorNegativeRightPin, motorSpeedRightPin, motorSpeedLeftPin;
    Run run;
}; 

#endif // MOTOR_H
