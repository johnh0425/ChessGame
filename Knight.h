#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

using namespace std;

class Knight : public Piece{
    private:


    public:
    Knight(teamType);
    string print();
};

#endif