#include <iostream>
#include "../corte2_ent2/exercism/robot_simulator/robot_simulator.h"

using namespace std;
using namespace robot_simulator;

int main() {
    // Posición y dirección inicial
    Robot robot;

    if (robot.get_position() != position{0, 0}) {
        cerr << "Robot Simulator: ERROR en posicion inicial" << endl;
        return 1;
    }

    if (robot.get_bearing() != Bearing::NORTH) {
        cerr << "Robot Simulator: ERROR en direccion inicial" << endl;
        return 1;
    }

    // Girar a la derecha
    robot.turn_right();

    if (robot.get_bearing() != Bearing::EAST) {
        cerr << "Robot Simulator: ERROR en turn_right" << endl;
        return 1;
    }

    // Avanzar hacia el este
    robot.advance();

    if (robot.get_position() != position{1, 0}) {
        cerr << "Robot Simulator: ERROR en advance" << endl;
        return 1;
    }

    // Secuencia de instrucciones
    Robot robot2(position{7, 3}, Bearing::NORTH);
    robot2.execute_sequence("RAALAL");

    if (robot2.get_position() != position{9, 4}) {
        cerr << "Robot Simulator: ERROR en execute_sequence" << endl;
        return 1;
    }

    if (robot2.get_bearing() != Bearing::WEST) {
        cerr << "Robot Simulator: ERROR en direccion final" << endl;
        return 1;
    }

    cout << "Robot Simulator: OK" << endl;

    return 0;
}
