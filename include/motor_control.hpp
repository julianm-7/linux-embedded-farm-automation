#pragma once

class MotorController {
public:
    MotorController(int stepsPerUnit = 100);

    void initialize();       // Initialize motor pins and hardware
    void setSpeed(int speed); // Set motor speed (0-100%)
    void move(int xSteps, int ySteps); // Move arm in X/Y directions
    void stop();             // Stop all motors

private:
    int stepsPerUnit;
};
