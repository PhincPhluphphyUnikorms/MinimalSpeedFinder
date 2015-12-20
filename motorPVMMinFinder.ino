/**********************************************************************************************
 * Arduino motor PVM tuning program
 * by Daniel Graungaard <daniel@graungaard.com> graungaard.com.com
 *
 * Very simple program to determine the minimal PVM value to drive a motor with an l293d H-Bridge.
 *
 * Mean to one day implement in a servo controller
 *
 **********************************************************************************************/


#include <Arduino.h>
#include "../PID/Motor.h"

#define motorpin1 3
#define motorpin2 4
#define motorpvmpin 9
#define potipin 0

int potivalue;
int minimalpvm = 0;

Motor motor(motorpin1, motorpin2, motorpvmpin); //Pins for motor

int averageRead(int number);
void end();

void setup() {


    pinMode(potipin, INPUT);

    Serial.begin(9600);

    motor.setSpeed(255); // Max speed so we can move initially
    motor.move(-20, 1); // Moves the motor back so we knbow that we can go forward beware of motorjam here
    //TODO: Setup probably should be implemented otherwise to guard against jams

    delay(100); //Helps ensure that the motor have moved

    Serial.println("READY:");

    motor.setSpeed(minimalpvm); // Restes speed so we are ready to tune
    motor.move(10, 1); // Sets a target so the motor will move

    delay(200);
    potivalue = averageRead(5); //Makes shure we know the value before we compare with the old one

    delay(1000); // We want to make sure that the motor have had time to stop

}


void loop() {

    int oldpotidvalue = potivalue;

    potivalue = averageRead(5);



    int difference = abs(oldpotidvalue - potivalue);

    Serial.print("DIFF: ");
    Serial.println(difference);
    Serial.print("OLDREADING: ");
    Serial.println(oldpotidvalue);
    Serial.print("READING: ");
    Serial.println(potivalue);


    if(difference > 5) {

        Serial.print("Den minimale PVM værdi der skal til for at motoren flytter sig er: ");
        Serial.println(minimalpvm);


        end();

    } else if(minimalpvm >= 255) {

        Serial.println("SOMETHING WENT WRONG: The maxspeed possible is exited. We cannot write anynore tha 255 on a pvm line");
        Serial.println("Ensure that your connections are working and that the motor is working and try again");

        end();


    }

    Serial.print("Just tried with value: ");
    Serial.println(minimalpvm);

    minimalpvm++;

    motor.setSpeed(minimalpvm);

    delay(200);


}

int averageRead(int number) {

    int sum = 0;

    for(int i = 0; i < number; i++) {


      sum += analogRead(potipin);

    }

    return sum/number;
}

void end() {

    motor.stop();

    while(true) {

        // Does nothing here we have either found a value or exited max and want to make sure that the motor is stopped

    }
}