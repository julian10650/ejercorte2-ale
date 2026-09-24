#pragma once

#include <string>
#include <utility>

namespace robot_simulator {

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

using position = std::pair<int, int>;

class Robot {
public:
    Robot();
    Robot(position pos, Bearing bearing);

    position get_position() const;
    Bearing get_bearing() const;

    void turn_right();
    void turn_left();
    void advance();

    void execute_sequence(const std::string& instructions);

private:
    position pos;
    Bearing bearing;
};

}  // namespace robot_simulator
