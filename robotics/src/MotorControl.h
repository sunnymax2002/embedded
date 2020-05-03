/*
 * Generic Motor Control Logic
 */

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} MotorDriveDirection;

void DriveMotor(MotorDriveDirection dir);