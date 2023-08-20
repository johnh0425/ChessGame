#include "Rook.h"
#include <iostream>

using namespace std;

// rook constructor
Rook::Rook(teamType color): Piece(ROOK, 250, color) {}

// prints rook on the board
string Rook::print() {
    if (getColor() == BLACK) {
        return "  \u2656   |";
    }
    return "  \u265C   |";
}