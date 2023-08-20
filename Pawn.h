#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

using namespace std;

class Pawn : public Piece{
    //no private attributes of the Pawn class
    private:

    public:
    //This will create a pawn and place it on the board
    Pawn(teamType color);
    string print();
};

#endif