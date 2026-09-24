#include <iostream>
#include <vector>
#include "../corte2_ent2/leetcode/design_spreadsheet/spreadsheet.cpp"

using namespace std;

int main() {
    Spreadsheet spreadsheet(3);

    if (spreadsheet.getValue("=5+7") != 12) {
        cerr << "Spreadsheet: ERROR en suma de numeros" << endl;
        return 1;
    }

    spreadsheet.setCell("A1", 10);

    if (spreadsheet.getValue("=A1+6") != 16) {
        cerr << "Spreadsheet: ERROR en celda + numero" << endl;
        return 1;
    }

    spreadsheet.setCell("B2", 15);

    if (spreadsheet.getValue("=A1+B2") != 25) {
        cerr << "Spreadsheet: ERROR en celda + celda" << endl;
        return 1;
    }

    spreadsheet.resetCell("A1");

    if (spreadsheet.getValue("=A1+B2") != 15) {
        cerr << "Spreadsheet: ERROR en resetCell" << endl;
        return 1;
    }

    cout << "Spreadsheet: OK" << endl;

    return 0;
}
