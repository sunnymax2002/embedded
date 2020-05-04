/*
 * Example to illustrate usage of Co-operative Multi-tasking
 */

#include "CoOpMultiTasking.h"
#include "MotorControl.h"

// Create Tasks and define their nature
CoOpTask taskLedBlink(0, 100);
CoOpTask taskFBMotorDrive(1, 1000);
CoOpTask taskLRMotorDrive(2, 2000);

// Function for taskLedBlink: These functions should return quickly and must not call any form of delay()
void BlinkLed() {
    // TODO add code
}

void setup() {
    taskLedBlink.Start();
    taskFBMotorDrive.Start();
    taskLRMotorDrive.Start();
}

void loop() {
    if(taskLedBlink.isTimeToRun()) BlinkLed();

    if(taskFBMotorDrive.isTimeToRun()) DriveMotor(FORWARD);

    if(taskLRMotorDrive.isTimeToRun()) DriveMotor(LEFT);
}