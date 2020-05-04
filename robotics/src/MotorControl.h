/*
 * Generic Motor Control Logic
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} MotorDriveDirection;

void DriveMotor(MotorDriveDirection dir);

#endif  // MOTORCONTROL_H_