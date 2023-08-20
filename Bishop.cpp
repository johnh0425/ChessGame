#include "Bishop.h"
#include <iostream>

using namespace std;

// bishop constructor
Bishop::Bishop(teamType color): Piece(BISHOP, 100, color) {}

// prints bishop on board
string Bishop::print() {
    if (getColor() == BLACK) {
        return "  \u2657   |";
    }
    return "  \u265D   |";
}