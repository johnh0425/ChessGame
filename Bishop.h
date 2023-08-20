#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

using namespace std;

class Bishop : public Piece{

    private:

    public:
    Bishop(teamType);
    string print();
};

#endif