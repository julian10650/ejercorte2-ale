#pragma once

#include <utility>

namespace queen_attack {

using position = std::pair<int, int>;

class chess_board {
public:
    chess_board(position white, position black);

    position white() const;
    position black() const;

    bool can_attack() const;

private:
    position white_queen;
    position black_queen;
};

}  // namespace queen_attack
