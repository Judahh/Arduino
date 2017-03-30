#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int motorNegativeLeftPin, int motorPositiveLeftPin, int motorPositiveRightPin, int motorNegativeRightPin, int motorSpeedRightPin, int motorSpeedLeftPin, byte intensity){
    pinMode(motorNegativeLeftPin, OUTPUT);
    pinMode(motorPositiveLeftPin, OUTPUT);
    pinMode(motorPositiveRightPin, OUTPUT);
    pinMode(motorNegativeRightPin, OUTPUT);
    pinMode(motorSpeedRightPin, OUTPUT);
    pinMode(motorSpeedLeftPin, OUTPUT);

    this->intensity = intensity;
    this->motorNegativeLeftPin = motorNegativeLeftPin;
    this->motorPositiveLeftPin = motorPositiveLeftPin;
    this->motorPositiveRightPin = motorPositiveRightPin;
    this->motorNegativeRightPin = motorNegativeRightPin;
    this->motorSpeedRightPin = motorSpeedRightPin;
    this->motorSpeedLeftPin = motorSpeedLeftPin; 
}

void Motor:: runBackwards(){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForward(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runBackwardsLeft(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runBackwardsRight(){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForwardLeft(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForwardRight(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: turnLeft(){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: turnRight(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: brake(){
    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: neutral(){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorSpeedRightPin, LOW);
    digitalWrite(motorSpeedLeftPin, LOW);
}





void Motor:: runBackwards(byte intensity){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForward(byte intensity){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runBackwardsLeft(byte intensity){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runBackwardsRight(byte intensity){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForwardLeft(byte intensity){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: runForwardRight(byte intensity){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: turnLeft(byte intensity){
    digitalWrite(motorPositiveLeftPin, LOW);
    digitalWrite(motorNegativeRightPin, LOW);

    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: turnRight(byte intensity){
    digitalWrite(motorNegativeLeftPin, LOW);
    digitalWrite(motorPositiveRightPin, LOW);

    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}

void Motor:: brake(byte intensity){
    digitalWrite(motorNegativeLeftPin, HIGH);
    digitalWrite(motorPositiveLeftPin, HIGH);
    digitalWrite(motorPositiveRightPin, HIGH);
    digitalWrite(motorNegativeRightPin, HIGH);

    analogWrite(motorSpeedRightPin, intensity);
    analogWrite(motorSpeedLeftPin, intensity);
}



byte Motor:: getIntensity(float intensityPercentage){
    int percentageMax = 100;
    int intensityMax = 255;
    float intensityP = intensityPercentage / percentageMax;

    return intensityP * intensityMax;
}

void Motor:: setIntensity(byte intensity){
    this->intensity = intensity;
}