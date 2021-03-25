#if !defined(BOARD_DISPLAY_H)
#define BOARD_DISPLAY_H

#include "grid.h"

class BoardDisplayInterface {
    public:
        virtual void display(Grid g);
};

#endif // BOARD_DISPLAY_H
