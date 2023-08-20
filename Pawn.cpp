#include "Pawn.h"
#include <iostream>

using namespace std;

//Constructor for creating a pawn with the correct color and where it will be placed and the piece it will be established as
Pawn::Pawn(teamType color): Piece(PAWN, 20, color) {}

// prints pawn on board
string Pawn::print() {
    if (getColor() == BLACK) {
        return "  \u2659   |";
    }
    return "  \u265F   |";
}