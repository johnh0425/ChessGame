#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

using namespace std;

class Queen : public Piece{
    private:

    public:
    Queen(teamType);
    string print();
};

#endif