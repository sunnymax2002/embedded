/*
 * Generic Motor Control Logic
 */

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

class MotorControl {
public:
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
    } Direction;

    MotorControl(Type type);
    void SetFBMotor(uint8_t pinPlus, uint8_t pinMinus);
    void SetFBMotorPwm(uint64_t pwmMaxValue, uint32_t pwmStepSize);
    void DriveMotor(Direction dir);
    ~MotorControl();
private:
    Type _type;     // Type of motor
    bool _pwmForFB;  // Whether H/W supports PWM for FB motor or not
    bool _pwmForLR;  // Whether H/W supports PWM for FB motor or not
    uint64_t _FB_pwmMaxValue;   // Max value for PWM, e.g. 255 for 8-bit control
    uint32_t _FB_pwmStepSize;   // Step size for PWM control, e.g. 1 for normal 8-bit PWM on Arduino
    uint64_t _LR_pwmMaxValue;   // Max value for PWM, e.g. 255 for 8-bit control
    uint32_t _LR_pwmStepSize;   // Step size for PWM control, e.g. 1 for normal 8-bit PWM on Arduino
    uint8_t pinPlusLR;      // Plus pin for LR motor
    uint8_t pinPlusFB;      // Plus pin for FB motor
    uint8_t pinMinusLR;      // Plus pin for LR motor
    uint8_t pinMinusFB;      // Plus pin for FB motor
};

#endif  // MOTORCONTROL_H_