#include "Knight.h"
#include <iostream>

using namespace std;

// knight constructor
Knight::Knight(teamType color): Piece(KNIGHT, 100, color) {}

// prints knight on board
string Knight::print() {
    if (getColor() == BLACK) {
        return + "  \u2658   |";
    }
    return "  \u265E   |";
}
