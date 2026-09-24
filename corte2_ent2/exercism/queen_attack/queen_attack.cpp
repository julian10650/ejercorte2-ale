#include "queen_attack.h"

#include <cstdlib>
#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(position white, position black) {

    // Verificar que las dos posiciones estén dentro del tablero
    if (white.first < 0 || white.first > 7 ||
        white.second < 0 || white.second > 7 ||
        black.first < 0 || black.first > 7 ||
        black.second < 0 || black.second > 7) {
        throw std::domain_error("Position is outside the board");
    }

    // Las dos reinas no pueden estar en la misma posición
    if (white == black) {
        throw std::domain_error("Queens cannot occupy the same position");
    }

    white_queen = white;
    black_queen = black;
}

position chess_board::white() const {
    return white_queen;
}

position chess_board::black() const {
    return black_queen;
}

bool chess_board::can_attack() const {

    // Misma fila
    if (white_queen.first == black_queen.first) {
        return true;
    }

    // Misma columna
    if (white_queen.second == black_queen.second) {
        return true;
    }

    // Misma diagonal
    if (std::abs(white_queen.first - black_queen.first) ==
        std::abs(white_queen.second - black_queen.second)) {
        return true;
    }

    return false;
}

}  // namespace queen_attack
