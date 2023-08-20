#ifndef PIECE_H
#define PIECE_H
#include <iostream>

using namespace std;

enum pieceNames {QUEEN, KING, PAWN, ROOK, BISHOP, KNIGHT};
enum teamType {WHITE, BLACK};

class Piece{

    protected:
    int value;
    pieceNames pieceType;
    teamType teamColor;

    public:
    Piece(pieceNames piece, int val, teamType team);
    void setTeamColor(teamType);
    void setPieceType(pieceNames);
    pieceNames getPieceType() const;
    teamType getColor() const;
    bool captured();
    virtual string print() = 0;
}; 

#endif