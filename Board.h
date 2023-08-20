#ifndef __BOARD_H__
#define __BOARD_H__

#include "Square.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Board {
    private:
        Square squares[8][8];
    public:
        ~Board();
        void newBoard();
        Square* getSquare(int x, int y);
        string printBoard();
        void move();
};


#endif