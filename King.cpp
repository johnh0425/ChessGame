#include "King.h"
#include <iostream>

using namespace std;

// king constructor
King::King(teamType color): Piece(KING, 1000, color) {}

// prints king on board
string King::print() {
    if (getColor() == BLACK) {
        return "  \u2654   |";
    }
    return "  \u265A   |";
}
