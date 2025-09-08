#pragma once
#include "motor_control.hpp"

class GridScanner {
public:
    GridScanner(MotorController &motor, float widthCm, float heightCm, float stepSizeCm);

    void scanGrid(); // Run full scan

private:
    MotorController &motor;
    float width;
    float height;
    float stepSize;
};
