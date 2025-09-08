#include "grid_scanner.hpp"
#include <iostream>

GridScanner::GridScanner(MotorController &m, float w, float h, float step)
    : motor(m), width(w), height(h), stepSize(step) {}

void GridScanner::scanGrid() {
    bool leftToRight = true;

    int xSteps = static_cast<int>(width / stepSize);
    int ySteps = static_cast<int>(height / stepSize);

    std::cout << "[GridScanner] Starting full bed scan..." << std::endl;

    for (int y = 0; y < ySteps; ++y) {
        if (leftToRight) {
            motor.move(xSteps, 0);
        } else {
            motor.move(-xSteps, 0);
        }
        motor.move(0, 1); // Move to next row
        leftToRight = !leftToRight;
    }
    motor.stop();
    std::cout << "[GridScanner] Full bed scan complete." << std::endl;
}
