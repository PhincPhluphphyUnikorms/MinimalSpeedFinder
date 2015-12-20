//
// Created by daniel on 12/11/15.
//

#include "Motor.h"
#include "Arduino.h"

#define motorlimit 170 //The smallest pwm signal it takes to make the motor move


int _motor1Pin1;
int _motor1Pin2;
int _enablePin;


Motor::Motor(int pin1, int pin2, int enablepin) {

    _motor1Pin1 = pin1;
    _motor1Pin2 = pin2;
    //analogWrite(enablepin, motorlimit);
    _enablePin = enablepin;


    pinMode(_motor1Pin1, OUTPUT);
    pinMode(_motor1Pin2, OUTPUT);
    pinMode(_enablePin, OUTPUT);

    tuning = true; // Set to true of motor is runnign in tunign program

    setSpeed(motorlimit);



}

void Motor::clockwise() {

    digitalWrite(_motor1Pin1, LOW);
    digitalWrite(_motor1Pin2, HIGH);


}


void Motor::counterClockwise() {

    digitalWrite(_motor1Pin1, HIGH);
    digitalWrite(_motor1Pin2, LOW);

}

void Motor::stop() {
    digitalWrite(_motor1Pin1, LOW);
    digitalWrite(_motor1Pin2, LOW);

}

//Degree the relative degrees that we want to move aka the error value in the servo
void Motor::move(float degrees, float threshold) {


    if(abs(degrees) <= threshold) { //if error is smaller than threshold we stop

        stop();

    } else if(degrees > 0) {

        counterClockwise();

    } else {

        clockwise();


    }


}

void Motor::setSpeed(int speed) {

    if(!tuning) {
        if (speed > 255) speed = 255;
        else if (speed < motorlimit) speed = motorlimit;

    }
    analogWrite(_enablePin, speed);

}
