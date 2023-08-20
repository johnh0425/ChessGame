#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <string>
#include <iostream>
#include <stdexcept>
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
using namespace std;

class Square {
    private:
        int squareX;
        int squareY;
        Piece* pieces;   

    public:
    Square();
    Square(int x, int y, Piece* p);
    Piece* getPiece();
    int getSquareX();
    int getSquareY();
    void setSquareX(int x);
    void setSquareY(int x);
    void placedPiece(Piece* );

};

#endif