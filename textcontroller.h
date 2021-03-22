#ifndef TEXTCONTROLLER_H
#define TEXTCONTROLLER_H

#include <string>
#include "grid.h"

using namespace std;

class TextController {
    public:
        TextController(Grid &grid);

        bool action(string input);
    
    private:
        Grid &grid;
};

#endif
