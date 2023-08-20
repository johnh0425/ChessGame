#include "Square.h"
#include "Piece.h"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

// default square constructor
Square::Square() {
    squareX = 0;            // x coord on board
    squareY = 0;            // y coord on board
    pieces = nullptr;       // stores the piece on square
}

// square constructor
Square::Square(int x, int y, Piece* p) {
    squareX = x;
    squareY = y;
    pieces = p;
}

// getter function for getting piece on square
Piece* Square::getPiece() {
    return this->pieces;
}

// getter function for getting x-coord of square
int Square::getSquareX() {
    return this->squareX;
}

// getter function for getting y-coord of square
int Square::getSquareY() {
    return this->squareY;
}

// setter function for setting the x-coord on square (only used by function newBoard())
void Square::setSquareX(int x) {
    squareX = x;
}

// setter function for setting the y-coord on square (only used by function newBoard())
void Square::setSquareY(int y) {
    squareY = y;
}

// places piece on square
void Square::placedPiece(Piece* p) {
    pieces = p;
}
