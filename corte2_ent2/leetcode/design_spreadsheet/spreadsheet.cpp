#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> hoja;

public:
    Spreadsheet(int rows) {
        hoja = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int columna = cell[0] - 'A';
        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = value;
    }

    void resetCell(string cell) {
        int columna = cell[0] - 'A';
        int fila = stoi(cell.substr(1)) - 1;

        hoja[fila][columna] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1);

        int posicion = formula.find('+');

        string x = formula.substr(0, posicion);
        string y = formula.substr(posicion + 1);

        int valorX;
        int valorY;

        if (x[0] >= 'A' && x[0] <= 'Z') {
            int columna = x[0] - 'A';
            int fila = stoi(x.substr(1)) - 1;

            valorX = hoja[fila][columna];
        } else {
            valorX = stoi(x);
        }

        if (y[0] >= 'A' && y[0] <= 'Z') {
            int columna = y[0] - 'A';
            int fila = stoi(y.substr(1)) - 1;

            valorY = hoja[fila][columna];
        } else {
            valorY = stoi(y);
        }

        return valorX + valorY;
    }
};
