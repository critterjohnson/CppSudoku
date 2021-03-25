#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "grid.h"
#include "textcontroller.h"

TextController::TextController(Grid &g) : grid(g) {

}

bool TextController::action(string input) {
    int pos = 0;
    
    stringstream strstrm(input);
    vector<string> words = vector<string>();
    string word;
    while (strstrm >> word) {
        words.push_back(word);
    }

    if (words.size() < 3) {
        cout << words.size() << endl;
        cout << "inputs should be of the format: place|remove row col <number (if place)>" << endl;
        return false;
    }

    if (words.at(0) != "place" && words.at(0) != "remove") {
        cout << "inputs should be of the format: place|remove row col <number (if place)>" << endl;
        return false;
    }

    int row;
    int col;
    try {
        row = stoi(words.at(1));
        col = stoi(words.at(2));
    } catch (invalid_argument) {
        cout << "input row or col could not be parsed to an int" << endl;
        return false;
    } catch (out_of_range) {
        cout << "number should be in range 0-8" << endl;
        return false;
    }

    if (row < 0 || row > 8) {
        cout << "row should be in range 0-8" << endl;
        return false;
    }
    if (col < 0 || col > 8) {
        cout << "col should be in range 0-8" << endl;
        return false;
    }

    if (words.at(0) == "place" && words.size() < 4) {
        cout << "place input should be of the format: place row col number";
        return false;
    }

    if (words.at(0) == "place") {
        grid.place(words.at(3).at(0), row, col);
    } else if (words.at(0) == "remove") {
        grid.remove(row, col);
    }
}
