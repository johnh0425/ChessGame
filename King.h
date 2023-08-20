#ifndef KING_H
#define KING_H

#include "Piece.h"

using namespace std;

class King : public Piece{

    private:

    public:
    King(teamType);
    string print();
};

#endif