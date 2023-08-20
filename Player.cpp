#include "Player.h"    
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Player constructor
Player::Player(PlayerType p, TeamColor t, Board* boards) {
    player = p;
    teamType = t;
    board = boards;
}

// getter function to get board
Board* Player::getBoard() {
    return board;
}

// checks if player is in checkmate
bool Player::isCheckmated() {
    Moves* testCheckmate = new Moves(board);
    if(getPlayerColor() == white) {
        if(testCheckmate->isCheckmated(BLACK)) {        // checks if black is in checkmate through moves class
            delete testCheckmate;
            return true;
        }
    }
    if (getPlayerColor() == black) {
        if (testCheckmate->isCheckmated(WHITE)) {       // checks if white is in checkmate through moves class
            delete testCheckmate;
            return true;
        }
    }
    delete testCheckmate;
    return false;
}

// getter function that gets player color
TeamColor Player::getPlayerColor() {
    return teamType;
}

// Move function
// checks if input fits the board
bool Player::moveInputValidation(int value){
    if(value < 1 || value > 8){
        return false;
    }
    return true;
}

// gets move input, checks for the move validity, and calls the move 
void Player::move() {

    int prev_x_coord;
    int prev_y_coord;
    int new_x_coord;
    int new_y_coord;

    Moves* playerMovement;

    while(true) {
        cout << "What square would you like to move from? Type in the x-coordinate" << endl;

        // get start square x coord
        while(true){
            cin >> prev_x_coord;
            //
            if(moveInputValidation(prev_x_coord)){
                prev_x_coord -= 1;
                break;
            }
            else{
                cout << "Please type in a valid input (Numbers 1-8)" << endl;
            }
        }

        cout << "What square would you like to move from? Type in the y-coordinate" << endl;

        // get start square y coord
        while(true){
            cin >> prev_y_coord;
            if(moveInputValidation(prev_y_coord)){
                prev_y_coord -= 1;
                break;
            }
            else{
                cout << "Please type in a valid input (Numbers 1-8)" << endl;
            }
        }  

        cout << "What square would you like to move to? Type in the x-coordinate" << endl;

        // get end square x coord
        while(true){
            cin >> new_x_coord;
            if(moveInputValidation(new_x_coord)){
                new_x_coord -= 1;
              break;
            }
            else{
                cout << "Please type in a valid input (Numbers 1-8)" << endl;
            }
        }

        cout << "What square would you like to move to? Type in the y-coordinate" << endl;

        // get end square y coord
        while(true){
            cin >> new_y_coord;
            if(moveInputValidation(new_y_coord)){
                new_y_coord -= 1;
                break;
            }
            else{
                cout << "Please type in a valid input (Numbers 1-8)" << endl;
            }
        }
        // check if a castle move is valid by calling the castleMove function
        if (castleMove(board->getSquare(prev_x_coord, prev_y_coord), board->getSquare(new_x_coord, new_y_coord), board)) {
            playerMovement = new Moves(getBoard()->getSquare(prev_x_coord, prev_y_coord), getBoard()->getSquare(new_x_coord, new_y_coord), WHITE, getBoard(), WHITE, true);
            break;
        }

        // create a move object and test if it is valid
        if (getPlayerColor() == white) {
            playerMovement = new Moves(getBoard()->getSquare(prev_x_coord, prev_y_coord), getBoard()->getSquare(new_x_coord, new_y_coord), WHITE, getBoard(), WHITE);
        }
        else{
            playerMovement = new Moves(getBoard()->getSquare(prev_x_coord, prev_y_coord), getBoard()->getSquare(new_x_coord, new_y_coord), BLACK, getBoard(), BLACK);
        }
        // checking move validity
        if(playerMovement->isValidMove()){
            break;
        }
        // if move is not valid, delete and ask for another one
        else{
            delete playerMovement;
        }
        cout << "Please type a valid move" << endl;   
    }

    // Call isValidInput
    // Call Actualy Move from Move class. 
    playerMovement->callForMove();
    delete playerMovement;
}

// check if a castle move is valid
bool Player::castleMove(Square* start, Square* end, Board* board) {
    if ((start->getPiece()->getPieceType() == KING) && (start->getPiece()->getColor() == BLACK)) {
        if ((start->getSquareX() == 4) && (start->getSquareY() == 0)) {
            if ((end->getSquareX() == 6) && (end->getSquareY() == 0) && (end->getPiece() == nullptr) && (board->getSquare(5, 0)->getPiece() == nullptr)) {
                if ((board->getSquare(7, 0)->getPiece()->getPieceType() == ROOK) && (board->getSquare(7, 0)->getPiece()->getColor() == BLACK)) {
                    return true;
                }
            }
            else if ((end->getSquareX() == 2) && (end->getSquareY() == 0) && (end->getPiece() == nullptr) && (board->getSquare(1, 0)->getPiece() == nullptr) && (board->getSquare(3, 0)->getPiece() == nullptr)) {
                if ((board->getSquare(0, 0)->getPiece()->getPieceType() == ROOK) && (board->getSquare(0, 0)->getPiece()->getColor() == BLACK)) {
                    return true;
                }
            }
        }
    }
    else if ((start->getPiece()->getPieceType() == KING) && (start->getPiece()->getColor() == WHITE)) {
        if ((start->getSquareX() == 4) && (start->getSquareY() == 7)) {
            if ((end->getSquareX() == 6) && (end->getSquareY() == 7) && (end->getPiece() == nullptr) && (board->getSquare(5, 7)->getPiece() == nullptr)) {
                if ((board->getSquare(7, 7)->getPiece()->getPieceType() == ROOK) && (board->getSquare(7, 7)->getPiece()->getColor() == WHITE)) {
                    return true;
                }
            }
            else if ((end->getSquareX() == 2) && (end->getSquareY() == 7) && (end->getPiece() == nullptr) && (board->getSquare(1, 7)->getPiece() == nullptr) && (board->getSquare(3, 7)->getPiece() == nullptr)) {
                if ((board->getSquare(0, 7)->getPiece()->getPieceType() == ROOK) && (board->getSquare(0, 7)->getPiece()->getColor() == WHITE)) {
                    return true;
                }
            }
        }
    }
    return false;
}
