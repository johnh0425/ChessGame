#include "Piece.h"
#include <iostream>

using namespace std;

// piece constructor
Piece::Piece(pieceNames piece, int val, teamType team){
    pieceType = piece;
    value = val;
    teamColor = team;
}

// sets the color of a piece
void Piece::setTeamColor(teamType newTeamColor){
    this->teamColor = newTeamColor;
}

// getter functions that gets the piece color
teamType Piece::getColor() const {
    return this->teamColor;
}

// setter function that sets the piece type (pawn, queen, king, etc..)
void Piece::setPieceType(pieceNames newPieceType) {
    pieceType = newPieceType;
}

// getter function that gets the piece type
pieceNames Piece::getPieceType() const {
    return this->pieceType;
}
 
