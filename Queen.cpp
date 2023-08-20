#include "Queen.h"
#include <iostream>

using namespace std;

// queen constructor
Queen::Queen(teamType color): Piece(QUEEN, 500, color) {}

// prints queen on the board
string Queen::print() {
    if (getColor() == BLACK) {
        return "  \u2655   |";
    }
    return "  \u265B   |";
}