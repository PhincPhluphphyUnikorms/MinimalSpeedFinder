//
// Created by daniel on 12/11/15.
//

#ifndef PID_MOTOR_H
#define PID_MOTOR_H


class Motor {

    int _motor1Pin1;
    int _motor1Pin2;
    int _enablePin;

public:
    Motor(int pin1, int pin2, int enablepin);

    void stop();

    void move(float degrees, float threshold);

    void setSpeed(int speed);

private:
    void clockwise();

    void counterClockwise();

    bool tuning;
};


#endif //PID_MOTOR_H
