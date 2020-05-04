/*
 * Example to illustrate usage of Co-operative Multi-tasking
 */

#include "CoOpMultiTasking.h"
#include "MotorControl.h"

CoOpTask taskLedBlink;
CoOpTask taskFBMotorDrive;
CoOpTask taskLRMotorDrive;

void BlinkLed() {

}

void setup() {
    taskLedBlink = CoOpTask(PERIODIC, 100);
}

void loop() {
    if(taskLedBlink.isTimeToRun()) BlinkLed();

    if(taskFBMotorDrive.isTimeToRun()) DriveMotor(FORWARD);

    if(taskLRMotorDrive.isTimeToRun()) DriveMotor(LEFT);
}