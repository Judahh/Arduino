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
    this->run = none;
}

void Motor:: runBackwards(){
    if(this->run != backwardsState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsState;
    }
}

void Motor:: runForward(){
    if(this->run != forwardState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardState;
    }
}

void Motor:: runBackwardsLeft(){
    if(this->run != backwardsLeftState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsLeftState;
    }
}

void Motor:: runBackwardsRight(){
    if(this->run != backwardsRightState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsRightState;
    }
}

void Motor:: runForwardLeft(){
    if(this->run != forwardLeftState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardLeftState;
    }
}

void Motor:: runForwardRight(){
    if(this->run != forwardRightState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardRightState;
    }
}

void Motor:: turnLeft(){
    if(this->run != leftState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = leftState;
    }
}

void Motor:: turnRight(){
    if(this->run != rightState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = rightState;
    }
}

void Motor:: brake(){
    if(this->run != brakeState){
        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = brakeState;
    }
}

void Motor:: neutral(){
    if(this->run != neutralState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorSpeedRightPin, LOW);
        digitalWrite(motorSpeedLeftPin, LOW);
        this->run = neutralState;
    }
}





void Motor:: runBackwards(byte intensity){
    if(this->run != backwardsState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsState;
    }
}

void Motor:: runForward(byte intensity){
    if(this->run != forwardState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardState;
    }
}

void Motor:: runBackwardsLeft(byte intensity){
    if(this->run != backwardsLeftState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsLeftState;
    }
}

void Motor:: runBackwardsRight(byte intensity){
    if(this->run != backwardsRightState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = backwardsRightState;
    }
}

void Motor:: runForwardLeft(byte intensity){
    if(this->run != forwardLeftState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardLeftState;
    }
}

void Motor:: runForwardRight(byte intensity){
    if(this->run != forwardRightState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = forwardRightState;
    }
}

void Motor:: turnLeft(byte intensity){
    if(this->run != leftState){
        digitalWrite(motorPositiveLeftPin, LOW);
        digitalWrite(motorNegativeRightPin, LOW);

        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = leftState;
    }
}

void Motor:: turnRight(byte intensity){
    if(this->run != rightState){
        digitalWrite(motorNegativeLeftPin, LOW);
        digitalWrite(motorPositiveRightPin, LOW);

        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = rightState;
    }
}

void Motor:: brake(byte intensity){
    if(this->run != brakeState){
        digitalWrite(motorNegativeLeftPin, HIGH);
        digitalWrite(motorPositiveLeftPin, HIGH);
        digitalWrite(motorPositiveRightPin, HIGH);
        digitalWrite(motorNegativeRightPin, HIGH);

        analogWrite(motorSpeedRightPin, intensity);
        analogWrite(motorSpeedLeftPin, intensity);
        this->run = brakeState;
    }
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