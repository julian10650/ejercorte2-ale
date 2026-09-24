#include <iostream>
#include "../corte2_ent2/exercism/queen_attack/queen_attack.h"

using namespace std;
using namespace queen_attack;

int main() {
    chess_board row({0, 0}, {0, 5});

    if (!row.can_attack()) {
        cerr << "Queen Attack: ERROR en fila" << endl;
        return 1;
    }

    chess_board column({0, 0}, {5, 0});

    if (!column.can_attack()) {
        cerr << "Queen Attack: ERROR en columna" << endl;
        return 1;
    }

    chess_board diagonal({0, 0}, {3, 3});

    if (!diagonal.can_attack()) {
        cerr << "Queen Attack: ERROR en diagonal" << endl;
        return 1;
    }

    chess_board no_attack({0, 0}, {2, 3});

    if (no_attack.can_attack()) {
        cerr << "Queen Attack: ERROR en posiciones sin ataque" << endl;
        return 1;
    }

    cout << "Queen Attack: OK" << endl;

    return 0;
}
