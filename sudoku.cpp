#include <iostream>
#include <string>

#include "grid.h"
#include "textcontroller.h"

using namespace std;

int main() {
    Grid g;
    TextController tc(g);
    // g.grid[0][0] = '0';

    while (true) {
        cout << g.toString() << endl;

        if (g.isWin()) {
            cout << "win!" << endl;
            break;
        }

        string uinput;
        getline(cin, uinput);
        tc.action(uinput);    
    }
}
