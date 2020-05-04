
#include "MotorControl.h"
#include "BoardSpecific.h"

MotorControl::MotorControl(uint8_t pinPlus, uint8_t pinMinus) {
    _pinPlus = pinPlus;
    _pinMinus = pinMinus;
    _pwmOn = false;
    ConfigPin(_pinPlus, OUTPUT);
    ConfigPin(_pinMinus, OUTPUT);
}

void MotorControl::ConfigMotorPwm(uint64_t pwmMaxValue, uint32_t pwmStepSize) {
    // Value correctness check
    if(pwmMaxValue > pwmStepSize) {
        _pwmOn = true;
        _pwmMaxValue = pwmMaxValue;
        _pwmStepSize = pwmStepSize;
    }
}

void MotorControl::DriveForward() {
    SetPin(_pinPlus, H);
    SetPin(_pinMinus, L);
}
void MotorControl::DriveBackward() {
    SetPin(_pinPlus, L);
    SetPin(_pinMinus, H);
}
void MotorControl::DriveReverse() {
    // TODO store motor state, or read Pin and reverse?
}

void MotorControl::PwmDriveForward(uint64_t pwmLevel) {
    SetPin(_pinMinus, L);
    SetPinPwm(_pinPlus, pwmLevel);
}
void MotorControl::PwmDriveBackward(uint64_t pwmLevel) {
    SetPin(_pinPlus, L);
    SetPinPwm(_pinMinus, pwmLevel);
}
void MotorControl::ChangePwmDrive(int64_t pwmChange) {
    // TODO store motor state, or read Pin and reverse?
}