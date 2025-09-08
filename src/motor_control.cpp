#include "motor_control.hpp"
#include <iostream>
#include <thread>
#include <chrono>

MotorController::MotorController(int steps) : stepsPerUnit(steps) {}

void MotorController::initialize() {
    std::cout << "[Motor] Initialized with " << stepsPerUnit << " steps/unit." << std::endl;
}

void MotorController::setSpeed(int speed) {
    std::cout << "[Motor] Speed set to " << speed << "%" << std::endl;
}

void MotorController::move(int xSteps, int ySteps) {
    std::cout << "[Motor] Moving X: " << xSteps << ", Y: " << ySteps << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds((abs(xSteps)+abs(ySteps))*10));
}

void MotorController::stop() {
    std::cout << "[Motor] Stopped." << std::endl;
}
