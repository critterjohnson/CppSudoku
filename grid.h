#ifndef GRID_H
#define GRID_H

#include <string>

using namespace std;

class Grid {
    public:
        char grid[9][9];
        
        Grid();

        bool place(char c, int row, int col);
        void remove(int row, int col);
        bool isWin();
        string toString();
};

#endif
