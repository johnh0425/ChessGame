#include <string>
#include "Board.h"
#include "Moves.h"

using namespace std;

#ifndef __PLAYER_H__
#define __PLAYER_H__

enum TeamColor{white, black};       // team colors
enum PlayerType{COMPUTER, HUMAN};       // player types

class Player {
    protected:
        TeamColor teamType;
        PlayerType player;
        Board* board;
        bool player1Checkmate = false;
        bool player2Checkmate = false;


    public:
        Player(PlayerType, TeamColor, Board*);      // constructor
        void move();        // Prompts the user to see where they want to move their piece.
        bool moveInputValidation(int value);
        bool isCheckmated();
        TeamColor getPlayerColor();
        Board* getBoard();
        bool castleMove(Square* start, Square* end, Board* board);
};

#endif