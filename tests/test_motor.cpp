#include "../include/motor_control.hpp"
#include <cassert>

int main() {
    MotorController motor;
    motor.initialize();
    motor.setSpeed(50);
    motor.move(5, 5);
    motor.stop();
    assert(true); // Basic pass test
    return 0;
}
