#include "Board.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

// Board descontructor (deletes all objects on board)
Board::~Board() {
    for (unsigned int i = 0; i <= 7; i++) {
        for (unsigned int j = 0; j <= 7; j++) {
            if (squares[i][j].getPiece() != nullptr) {
                delete squares[i][j].getPiece();
            }
        }
    }
}

// creates a new board (also places the pieces at the start of the game)
void Board::newBoard() {
    for (unsigned int i = 0; i <= 7; i++) {
        for (unsigned int j = 0; j <= 7; j++) {
            squares[i][j].setSquareX(i);
            squares[i][j].setSquareY(j);
        }
    }

    for (unsigned int i = 0; i <= 7; i++) {

        squares[i][1].placedPiece(new Pawn(BLACK));
        squares[i][6].placedPiece(new Pawn(WHITE));
    }

    squares[0][0].placedPiece(new Rook(BLACK));
    squares[1][0].placedPiece(new Knight(BLACK));
    squares[2][0].placedPiece(new Bishop(BLACK));
    squares[3][0].placedPiece(new Queen(BLACK));
    squares[4][0].placedPiece(new King(BLACK));
    squares[5][0].placedPiece(new Bishop(BLACK));
    squares[6][0].placedPiece(new Knight(BLACK));
    squares[7][0].placedPiece(new Rook(BLACK));

    squares[0][7].placedPiece(new Rook(WHITE));
    squares[1][7].placedPiece(new Knight(WHITE));
    squares[2][7].placedPiece(new Bishop(WHITE));
    squares[3][7].placedPiece(new Queen(WHITE));
    squares[4][7].placedPiece(new King(WHITE));
    squares[5][7].placedPiece(new Bishop(WHITE));
    squares[6][7].placedPiece(new Knight(WHITE));
    squares[7][7].placedPiece(new Rook(WHITE));

}

// getter function for square
Square* Board::getSquare(int x, int y) {
    return &squares[x][y];
}

// prints the board and calls print function for each piece
string Board::printBoard() {
    string board;

    for (unsigned int j = 0; j <= 7; j++) {
        board = board + "  +------+------+------+------+------+------+------+------+ \n";
        board += to_string(j + 1);
        board = board + " |";

        for (unsigned int i = 0; i <= 7; i++) {
            if (squares[i][j].getPiece() == nullptr) {
                board = board + "      |";
            }
            else {
                board = board + squares[i][j].getPiece()->print();
            }
        }
        board = board + "\n" ;
    }
    board = board + "  +------+------+------+------+------+------+------+------+ \n";
    board = board + "      1      2      3      4      5      6      7      8    \n";
    return board;
} 


