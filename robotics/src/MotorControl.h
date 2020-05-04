/*
 * Generic Motor Control Logic (for a single motor)
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include <stdint.h>

class MotorControl {
public:
/* TODO these enums might be needed for a higher level class but not here
    typedef enum {
        FORWARD_ONLY,
        BACKWARD_ONLY,
        LEFT_ONLY,
        RIGHT_ONLY,
        FB_ONLY,    // Forward + Backward only
        LR_ONLY,    // Left + Right only
        ALL_DIR     // Supports all directions
    } Type;
    typedef enum {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    } Direction; */

    MotorControl(uint8_t _pinPlus, uint8_t _pinMinus);
    void ConfigMotorPwm(uint64_t pwmMaxValue, uint32_t pwmStepSize);

    // Not PWM Motor Drive functions
    void DriveForward();
    void DriveBackward();
    void DriveReverse();

    // PWM Motor Drive Functions
    void PwmDriveForward(uint64_t pwmLevel);
    void PwmDriveBackward(uint64_t pwmLevel);
    void ChangePwmDrive(int64_t pwmChange);

    ~MotorControl();
private:
    bool _pwmOn;  // Whether H/W supports PWM for motor or not
    uint64_t _pwmMaxValue;   // Max value for PWM, e.g. 255 for 8-bit control
    uint32_t _pwmStepSize;   // Step size for PWM control, e.g. 1 for normal 8-bit PWM on Arduino
    uint64_t _pwmLevel;     // Current PWM level for motor pins
    uint8_t _pinPlus;      // Plus pin for LR motor
    uint8_t _pinMinus;      // Plus pin for LR motor
};

#endif  // MOTORCONTROL_H_