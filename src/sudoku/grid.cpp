#include "grid.h"

#include <ostream>
#include <iostream>
#include <string>

using namespace std;

Grid::Grid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = ' ';
        }
    }
}

bool Grid::place(char c, int row, int col) {
    int rowBox = row / 3;
    int colBox = row / 3;
    
    for (int r = rowBox; r < rowBox + 3; r++) {
        for (int co = colBox; co < colBox + 3; co++) {
            if (grid[r][co] == c) {
                return false;
            }
        }
    }

    for (int r = 0; r < 9; r++) {
        if (grid[r][col] == c) {
            return false;
        }
    }

    for (int co = 0; co < 9; co++) {
        if (grid[row][co] == c) {
            return false;
        }
    }

    grid[row][col] = c;

    return true;
}

void Grid::remove(int row, int col) {
    grid[row][col] = ' ';
}

bool Grid::isWin() {
    for (int r = 0; r < 9; r++) {
        bool containsVal[9];
        
        for (int c = 0; c < 9; c++) {
            if (grid[r][c] == ' ') {
                return false;
            } else {
                string s = "";
                s += grid[r][c];
                int val = stoi(s);
                containsVal[val-1] = true;
            }
        }

        bool winRow = true;
        for (bool b : containsVal) {
            winRow &= winRow;
        }
        if (!winRow) {
            return false;
        }
    }

    return true;
}

string Grid::toString() {
    string str = "";

    str += "-----------------------------------------\n||-------------------------------------||\n";
    for (int i = 0; i < 9; i++) {
        str += "||";
        for (int j = 0; j < 9; j++) {
            str += " ";
            str.push_back(grid[i][j]);
            str += " |";
            if ((j + 1) % 3 == 0) {
                str += "|";
            }
        }
        str += "\n";
        if ((i + 1) % 3 == 0) {
                str += "||-------------------------------------||\n";
            }
        if (i != 8) {
            str += "||-------------------------------------||\n";
        } else {
            str += "-----------------------------------------\n";
        }
    }
    return str;
}
