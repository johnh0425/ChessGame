#ifndef __MOVES_H__
#define __MOVES_H__

#include <iostream>
#include <stdexcept>
#include <string>
#include<vector>
#include "Board.h"
using namespace std;

//class is a object of an actual action of a move if it was executed
class Moves {
    
    private:
        //the starting and ending position of a move are calculated here
        Square * startPosition;
        Square * endPosition;
        //this is used to keep track of the correct color piece is moving
        teamType teamColor;
        //this is the piece that is acutally going to be moved on the board.
        Piece * involvedPiece;
        Board * board;
        vector<Moves*> blackMoves;
        vector<Moves*> whiteMoves;
        bool checkUpdate;
        teamType originalColor;
        bool castleCheck;

    public:
        Moves(Board * b);
        Moves(Square * startPosition, Square * endPosition, teamType teamColor, Board * board);
        Moves(Square * sPosition, Square * ePosition, teamType color, Board * b, teamType original);
        Moves(Square * sPosition, Square * ePosition, teamType color, Board * b, teamType original, bool castleMove);
        Square* getEndPosition();
        Square* getStartPosition();

        bool isCheckmated(teamType color);
        bool isChecked(teamType color);
        Square* getKingPosition(teamType color);
        Board* getBoard();
        vector<Moves*> getBlackMoves();
        vector<Moves*> getWhiteMoves();
        void updateMoves(teamType color);

        bool isValidMove();
        bool isValidPawnMove(int pawnX, int pawnY, int spaceX, int spaceY, teamType color, bool oppPiece);
        bool isValidKingMove(int kingX, int kingY, int spaceX, int spaceY, teamType color, bool oppPiece);
        
        bool isValidBishopMove(int bishopX, int bishopY, int spaceX, int spaceY, teamType color, bool oppPiece);
        bool isValidBishopMoveHelper1(int bishopX, int bishopY, int spaceX, int spaceY);
        bool isValidBishopMoveHelper2(int bishopX, int bishopY, int spaceX, int spaceY);
        bool isValidBishopMoveHelper3(int bishopX, int bishopY, int spaceX, int spaceY);
        bool isValidBishopMoveHelper4(int bishopX, int bishopY, int spaceX, int spaceY);

        bool isValidRookMove(int rookX, int rookY, int spaceX, int spaceY, teamType color, bool oppPiece);
        bool isValidRookMoveHelper1(int rookX, int rookY, int spaceX, int spaceY);
        bool isValidRookMoveHelper2(int rookX, int rookY, int spaceX, int spaceY);
        bool isValidRookMoveHelper3(int rookX, int rookY, int spaceX, int spaceY);
        bool isValidRookMoveHelper4(int rookX, int rookY, int spaceX, int spaceY);

        bool isValidQueenMove(int queenX, int queenY, int spaceX, int spaceY, teamType color, bool oppPiece);

        bool isValidKnightMove(int knightX, int knightY, int spaceX, int spaceY, teamType color, bool oppPiece);


        void callForMove();
        void castle(Square*, Square*, Board*);
};


#endif