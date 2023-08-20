#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

using namespace std;

class Rook : public Piece{
    private:

    public:
    Rook(teamType);
    string print();
};

#endif