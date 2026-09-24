#include "robot_simulator.h"

namespace robot_simulator {

Robot::Robot() {
    pos = {0, 0};
    bearing = Bearing::NORTH;
}

Robot::Robot(position pos, Bearing bearing) {
    this->pos = pos;
    this->bearing = bearing;
}

position Robot::get_position() const {
    return pos;
}

Bearing Robot::get_bearing() const {
    return bearing;
}

void Robot::turn_right() {
    switch (bearing) {
        case Bearing::NORTH:
            bearing = Bearing::EAST;
            break;

        case Bearing::EAST:
            bearing = Bearing::SOUTH;
            break;

        case Bearing::SOUTH:
            bearing = Bearing::WEST;
            break;

        case Bearing::WEST:
            bearing = Bearing::NORTH;
            break;
    }
}

void Robot::turn_left() {
    switch (bearing) {
        case Bearing::NORTH:
            bearing = Bearing::WEST;
            break;

        case Bearing::WEST:
            bearing = Bearing::SOUTH;
            break;

        case Bearing::SOUTH:
            bearing = Bearing::EAST;
            break;

        case Bearing::EAST:
            bearing = Bearing::NORTH;
            break;
    }
}

void Robot::advance() {
    switch (bearing) {
        case Bearing::NORTH:
            pos.second++;
            break;

        case Bearing::EAST:
            pos.first++;
            break;

        case Bearing::SOUTH:
            pos.second--;
            break;

        case Bearing::WEST:
            pos.first--;
            break;
    }
}

void Robot::execute_sequence(const std::string& instructions) {
    for (char instruction : instructions) {
        if (instruction == 'R') {
            turn_right();
        }
        else if (instruction == 'L') {
            turn_left();
        }
        else if (instruction == 'A') {
            advance();
        }
    }
}

}  // namespace robot_simulator
