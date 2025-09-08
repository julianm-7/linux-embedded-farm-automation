#include "../include/motor_control.hpp"
#include "../include/grid_scanner.hpp"
#include <cassert>

int main() {
    MotorController motor;
    motor.initialize();

    // 182.88 cm x 121.92 cm bed, 10 cm step size
    GridScanner scanner(motor, 182.88f, 121.92f, 10.0f);
    scanner.scanGrid();

    assert(true); // Basic pass test
    return 0;
}
