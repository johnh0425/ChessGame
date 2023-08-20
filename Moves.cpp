#include "Moves.h"
#include <iostream>
#include <vector>

using namespace std;

Moves::Moves(Board * b) {
    board = b;                      // pointer to board
    castleCheck = false;            // check if move is a castle
}

//This is the constructor that is going to process the Move of going from one place to another
Moves::Moves(Square * sPosition, Square * ePosition, teamType color, Board * b) {
    startPosition = sPosition;       // where the involved piece is at before being moved
    endPosition = ePosition;        // where the involved piece is being moved to
    teamColor = color;              // color of player moving
    board = b;
    castleCheck = false;           
}

Moves::Moves(Square * sPosition, Square * ePosition, teamType color, Board * b, teamType original) {
    startPosition = sPosition;
    endPosition = ePosition;
    teamColor = color;
    board = b;
    originalColor = original;           // prevents nonstop recursion
    castleCheck = false;
}

Moves::Moves(Square * sPosition, Square * ePosition, teamType color, Board * b, teamType original, bool castleMove) {
    startPosition = sPosition;
    endPosition = ePosition;
    teamColor = color;
    board = b;
    originalColor = original;
    castleCheck = castleMove;
}

// getter function that gets board
Board* Moves::getBoard() {
    return this->board;
}

// getter function that gets the square where the move ends
Square* Moves::getEndPosition() {
    return endPosition;
}

// getter function that gets the square where the move starts
Square* Moves::getStartPosition() {
    return startPosition;
}

//this is what will return whether a person is checkmated or not.
bool Moves::isCheckmated(teamType color) {
    vector<Moves*> validMoves;
    Piece* placeholder;
    validMoves.clear();
    updateMoves(BLACK);     // update list of black moves available
    updateMoves(WHITE);     // update list of white moves available
    if(color == WHITE){
        if(isChecked(WHITE)){ // If the King is in threat of being captured then return true;
            for (unsigned int i = 0; i < whiteMoves.size(); i++) {      // check all white moves that stops check
                placeholder = whiteMoves.at(i)->getEndPosition()->getPiece();
                whiteMoves.at(i)->getEndPosition()->placedPiece(whiteMoves.at(i)->getStartPosition()->getPiece());
                whiteMoves.at(i)->getStartPosition()->placedPiece(nullptr); 
                updateMoves(BLACK);
                if (!isChecked(WHITE)) {        // if there is a move the prevents check, push to a different vector
                    validMoves.push_back(whiteMoves.at(i));
                }
                whiteMoves.at(i)->getStartPosition()->placedPiece(whiteMoves.at(i)->getEndPosition()->getPiece());
                whiteMoves.at(i)->getEndPosition()->placedPiece(placeholder);
            }
            if (validMoves.size() == 0) {       // if there are no moves that prevent check, then there is a checkmate
                return true;
            }
        }
    }
    else if (color == BLACK) {
        if (isChecked(BLACK)){
            for (unsigned int i = 0; i < blackMoves.size(); i++) { // check all black moves that stops check
                placeholder = blackMoves.at(i)->getEndPosition()->getPiece();
                blackMoves.at(i)->getEndPosition()->placedPiece(blackMoves.at(i)->getStartPosition()->getPiece());
                blackMoves.at(i)->getStartPosition()->placedPiece(nullptr); 
                updateMoves(WHITE);
                if (!isChecked(BLACK)) {
                    validMoves.push_back(blackMoves.at(i));
                }
                blackMoves.at(i)->getStartPosition()->placedPiece(blackMoves.at(i)->getEndPosition()->getPiece());
                blackMoves.at(i)->getEndPosition()->placedPiece(placeholder);
            }
            if (validMoves.size() == 0) { // if there are no moves that prevent check, then there is a checkmate
                return true;
            }
        }
    }
    return false;
}    

//this is what will return whether or not a player is checked or not
bool Moves::isChecked(teamType color){
    Moves* checkMove;
    if (color == WHITE){
        if (originalColor == WHITE) {
            updateMoves(BLACK);             // update list of black moves available
        }
        for (unsigned int i = 0; i < blackMoves.size(); i++) {
            checkMove = blackMoves.at(i);
            // check if any of the available black moves hit the king's position
            if ((checkMove->getEndPosition()->getSquareX() == getKingPosition(WHITE)->getSquareX()) && (checkMove->getEndPosition()->getSquareY() == getKingPosition(WHITE)->getSquareY())) {
                return true;
            }
        }
    }
    else if (color == BLACK){
        if (originalColor == BLACK) {
            updateMoves(WHITE);             // update list of white moves available
        }
        for (unsigned int i = 0; i < whiteMoves.size(); i++) {
            checkMove = whiteMoves.at(i);
            // check if any of the available white moves hit the king's position
            if ((checkMove->getEndPosition()->getSquareX() == getKingPosition(BLACK)->getSquareX()) && (checkMove->getEndPosition()->getSquareY() == getKingPosition(BLACK)->getSquareY())) {
                return true;
            }
        }
    }
    return false;
}

// gets the king's position based on the color parameter
Square* Moves::getKingPosition(teamType color) {
    if (color == BLACK) {       // if BLACK, return the square that holds the black king
        for (unsigned int i = 0; i <= 7; i++) {
            for (unsigned int j = 0; j <= 7; j++) {     // check the whole board for the king's position
                if (board->getSquare(i, j)->getPiece() != nullptr) {
                    // if the black king is found, return its square
                    if ((board->getSquare(i, j)->getPiece()->getPieceType() == KING) && (board->getSquare(i, j)->getPiece()->getColor() == BLACK)) {
                        return board->getSquare(i, j);
                    }
                }
            }
        }
    }
    else if (color == WHITE) {      // if WHITE, return the square that holds the black king
        for (unsigned int i = 0; i <= 7; i++) {
            for (unsigned int j = 0; j <= 7; j++) { // check the whole board for the king's position
                if (board->getSquare(i, j)->getPiece() != nullptr) {        // makes sure square is not nullptr before checking its piece and color
                    // if the white king is found, return its square
                    if ((board->getSquare(i, j)->getPiece()->getPieceType() == KING) && (board->getSquare(i, j)->getPiece()->getColor() == WHITE)) {
                        return board->getSquare(i, j);
                    }
                }
            }
        }
    }
    return 0;
}

// gets the list of black moves available
vector<Moves*> Moves::getBlackMoves() {
    return this->blackMoves;
}

// gets the list of white moves available
vector<Moves*> Moves::getWhiteMoves() {
    return this->whiteMoves;
}

// updates a vector list of available moves for both BLACK and WHITE depending on the parameter
void Moves::updateMoves(teamType color) {
    if (color == BLACK) {
        for (unsigned int i = 0; i < blackMoves.size(); i++) {      // clears the vector list
            delete blackMoves.at(i);
        }
        blackMoves.clear();
        for (unsigned int i = 0; i <= 7; i++) {
            for (unsigned int j = 0; j <= 7; j++) {
                if (board->getSquare(i, j)->getPiece() != nullptr) {
                    for (unsigned int k = 0; k <= 7; k++) {
                        for (unsigned int l = 0; l <= 7; l++) {     // checks the whole board and all available moves
                            // makes sure the moves create are valid
                            Moves* newMove = new Moves(getBoard()->getSquare(i, j), getBoard()->getSquare(k, l), BLACK, getBoard());
                            // if moves are valid push to list
                            if (newMove->isValidMove()) {
                                blackMoves.push_back(newMove);
                            }
                            // delete move if move is not valid
                            else {
                                delete newMove;
                            }   
                        }  
                    }
                }
            }
        }
    }
    // same as updating black moves but for white this time
    else {
        for (unsigned int i = 0; i < whiteMoves.size(); i++) {
            delete whiteMoves.at(i);
        }
        whiteMoves.clear();
        for (unsigned int i = 0; i <= 7; i++) {
            for (unsigned int j = 0; j <= 7; j++) {
                if (board->getSquare(i, j)->getPiece() != nullptr) {
                    for (unsigned int k = 0; k <= 7; k++) {
                        for (unsigned int l = 0; l <= 7; l++) {
                            Moves* newMove = new Moves(getBoard()->getSquare(i, j), getBoard()->getSquare(k, l), WHITE, getBoard());
                            if (newMove->isValidMove()) {
                                whiteMoves.push_back(newMove);
                            }
                            else {
                                delete newMove;
                            }   
                        }  
                    }
                }
            }
        }
    }
}

//returns whether or not it is a valid move and this method will be later used
//for making an list of all of the valid moves that are allowed each turn.
bool Moves::isValidMove(){
    bool validMove = false;
    involvedPiece = startPosition->getPiece();
    int fromX = startPosition->getSquareX();
    int fromY = startPosition->getSquareY();
    int toX = endPosition->getSquareX();
    int toY = endPosition->getSquareY();
    teamType color = teamColor;
    bool oppPiece = false;
    if(endPosition->getPiece() != nullptr){
        oppPiece = true;
        if(endPosition->getPiece()->getColor() == color){
            return false;
        }
    }
    if (startPosition == endPosition){      // makes sure start and end position are not the same
        return false;
    }
    if (involvedPiece == nullptr){          // makes sure player is moving a piece
        return false;
    }
    if (involvedPiece->getColor() != teamColor){        // makes sure piece being moved matches the player color
        return false;
    }
    else if (involvedPiece->getPieceType() == PAWN){
        validMove = isValidPawnMove(fromX, fromY, toX, toY, color, oppPiece);       // checks move validity for a pawn
    }
    else if (involvedPiece->getPieceType() == KING){
        validMove = isValidKingMove(fromX, fromY, toX, toY, color, oppPiece);       // checks move validity for a king
    }
    else if (involvedPiece->getPieceType() == QUEEN){
        validMove = isValidQueenMove(fromX, fromY, toX, toY, color, oppPiece);      // checks move validity for a queen
    }
    else if (involvedPiece->getPieceType() == BISHOP){
        validMove = isValidBishopMove(fromX, fromY, toX, toY, color, oppPiece);     // checks move validity for a bishop
    }
    else if (involvedPiece->getPieceType() == ROOK){
        validMove = isValidRookMove(fromX, fromY, toX, toY, color, oppPiece);       // checks move valdity for a rook
    }
    else if (involvedPiece->getPieceType() == KNIGHT){
        validMove = isValidKnightMove(fromX, fromY, toX, toY, color, oppPiece);        // checks move validity for a knight
    }

    if ((involvedPiece->getColor() == BLACK) && validMove) {                
        Piece* placeholderEnd = endPosition->getPiece();
        Piece* placeholderStart = startPosition->getPiece();
        endPosition->placedPiece(involvedPiece);
        startPosition->placedPiece(nullptr);
        if (isChecked(BLACK)) {                 // checks if black move made is going to put black in check
            validMove = false;
        }
        else {
            validMove = true;
        }
        endPosition->placedPiece(placeholderEnd);
        startPosition->placedPiece(placeholderStart);
    }
    else if ((involvedPiece->getColor() == WHITE) && validMove) {
        Piece* placeholderEnd = endPosition->getPiece();
        Piece* placeholderStart = startPosition->getPiece();
        endPosition->placedPiece(involvedPiece);
        startPosition->placedPiece(nullptr);
        if (isChecked(WHITE)) {         // checks if white move made is going to put white in check
            validMove = false;
        }
        else {
            validMove = true;
        }
        endPosition->placedPiece(placeholderEnd);
        startPosition->placedPiece(placeholderStart);
    }

    return validMove;
}

// function used to check pawn validity
bool Moves::isValidPawnMove(int pawnX, int pawnY, int spaceX, int spaceY, teamType color, bool oppPiece) {
    //Accounting for the case of a pawn as a Black piece where it will work towards the board
    if (color == BLACK) {
        //checks case 1 of a pawn movement where it only moves forward
        if ((pawnX == spaceX) && (pawnY + 1 == spaceY) && (oppPiece == false)) {
            return true;
        }
        //checks case 2 of pawn movement where it overtakes another object diagonally
        else if ((pawnX + 1 == spaceX || pawnX - 1 == spaceX) && (pawnY + 1 == spaceY) && (oppPiece == true)) {
            return true;
        }
        //checks for the case when a pawn starts and goes up two spaces
        else if((pawnX == spaceX) && (pawnY == 1) && (pawnY + 2 == spaceY) && (board->getSquare(pawnX, pawnY+1)->getPiece() == nullptr) && (oppPiece == false)){
            return true;
        } else {
            return false;
        }
    }
    
    //Accounting for the case of a pawn as a Black piece where it will work against the board
    else if (color == WHITE) {
        //checks case 1 of a pawn movement where it only moves forward
        if ((pawnX == spaceX) && (pawnY - 1 == spaceY) && (oppPiece == false)) {
            return true;
        }
        //checks case 2 of pawn movement where it overtakes another object diagonally
        else if ((pawnX + 1 == spaceX || pawnX - 1 == spaceX) && (pawnY - 1 == spaceY) && (oppPiece == true)) {
            return true;
        }
        //checks for the case when a pawn starts and goes up two spaces
        else if((pawnX == spaceX) && (pawnY == 6) && (pawnY - 2 == spaceY) && (board->getSquare(pawnX, pawnY-1)->getPiece() == nullptr) && (oppPiece == false)){
            return true;
        } 
        else {
            return false;
        }
    }

    return false;
}

//checks for the specific case where the king is making a valid move or not
bool Moves::isValidKingMove(int kingX, int kingY, int spaceX, int spaceY, teamType color, bool oppPiece){
    //checks if the resulting space is within the region of one space
    if ( abs(spaceX - kingX) <=  1) {
        //checks if the resulting space is within the region of one space
        if ( abs(spaceY - kingY) <= 1 ) {
            //if the king is not in the same space
            if(!(spaceX == kingX && spaceY == kingY)){
                return true;
            }
        }
    }
    return false;
}

//checks if the Knight is making a valid move
bool Moves::isValidKnightMove(int knightX, int knightY, int spaceX, int spaceY, teamType color, bool oppPiece) {
    if ((abs(knightX - spaceX) == 2 && abs(knightY - spaceY) == 1) || (abs(knightX - spaceX) == 1 && abs(knightY - spaceY) == 2)) {
        return true;
    }
    return false;
}   

//checks if the Bishop is make a valid move
bool Moves::isValidBishopMove(int bishopX, int bishopY, int spaceX, int spaceY, teamType color, bool oppPiece) {
    //checks if the diagonal pattern is being followed
    if ( abs( bishopX - spaceX ) == abs( bishopY - spaceY )) {
        //checks the 4 different paths it can go through
        bool path1 = isValidBishopMoveHelper1(bishopX, bishopY, spaceX-1, spaceY-1);
        if(path1 == true){
            return true;
        }

        bool path2 = isValidBishopMoveHelper2(bishopX, bishopY, spaceX-1, spaceY+1);
        if(path2 == true){
            return true;
        }

        bool path3 = isValidBishopMoveHelper3(bishopX, bishopY, spaceX+1, spaceY+1);
        if(path3 == true){
            return true;
        }

        bool path4 = isValidBishopMoveHelper4(bishopX, bishopY, spaceX+1, spaceY-1);
        if(path4 == true){
            return true;
        }
    }
    return false;
}

//checks path 1 case for bishop
bool Moves::isValidBishopMoveHelper1(int bishopX, int bishopY, int spaceX, int spaceY){
    if(bishopX == spaceX && bishopY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidBishopMoveHelper1(bishopX, bishopY, spaceX-1, spaceY-1);
}

//checks path 2 case for bishop
bool Moves::isValidBishopMoveHelper2(int bishopX, int bishopY, int spaceX, int spaceY){
    if(bishopX == spaceX && bishopY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidBishopMoveHelper2(bishopX, bishopY, spaceX-1, spaceY+1);
}

//checks path 3 case for bishop
bool Moves::isValidBishopMoveHelper3(int bishopX, int bishopY, int spaceX, int spaceY){
    if(bishopX == spaceX && bishopY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidBishopMoveHelper3(bishopX, bishopY, spaceX+1, spaceY+1);
}

//checks path 4 case for bishop
bool Moves::isValidBishopMoveHelper4(int bishopX, int bishopY, int spaceX, int spaceY){
    if(bishopX == spaceX && bishopY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidBishopMoveHelper4(bishopX, bishopY, spaceX+1, spaceY-1);
}



//checks if the Rook is make a valid move
bool Moves::isValidRookMove(int rookX, int rookY, int spaceX, int spaceY, teamType color, bool oppPiece) {
    //checks if the diagonal pattern is being followed
    //checks the 4 different paths it can go through
    if (rookX == spaceX || rookY == spaceY) {
        bool path1 = isValidRookMoveHelper1(rookX, rookY, spaceX+1, spaceY);
        if(path1 == true){
            return true;
        }

        bool path2 = isValidRookMoveHelper2(rookX, rookY, spaceX, spaceY+1);
        if(path2 == true){
            return true;
        }

        bool path3 = isValidRookMoveHelper3(rookX, rookY, spaceX-1, spaceY);
        if(path3 == true){
            return true;
        }

        bool path4 = isValidRookMoveHelper4(rookX, rookY, spaceX, spaceY-1);
        if(path4 == true){
            return true;
        }
    }
    
    return false;
}

//checks path 1 case for rook
bool Moves::isValidRookMoveHelper1(int rookX, int rookY, int spaceX, int spaceY){
    if(rookX == spaceX && rookY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidRookMoveHelper1(rookX, rookY, spaceX+1, spaceY);
}

//checks path 2 case for rook
bool Moves::isValidRookMoveHelper2(int rookX, int rookY, int spaceX, int spaceY){
    if(rookX == spaceX && rookY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidRookMoveHelper2(rookX, rookY, spaceX, spaceY+1);
}

//checks path 3 case for rook
bool Moves::isValidRookMoveHelper3(int rookX, int rookY, int spaceX, int spaceY){
    if(rookX == spaceX && rookY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidRookMoveHelper3(rookX, rookY, spaceX-1, spaceY);
}

//checks path 4 case for rook
bool Moves::isValidRookMoveHelper4(int rookX, int rookY, int spaceX, int spaceY){
    if(rookX == spaceX && rookY == spaceY){
        return true;
    }

    if(spaceX < 0 || spaceY < 0 || spaceX > 7 || spaceY > 7){
        return false;
    }
    
    if((board->getSquare(spaceX, spaceY)->getPiece() != nullptr)){
        return false;
    }

    return isValidRookMoveHelper4(rookX, rookY, spaceX, spaceY-1);
}


//Validates the queen's moves by using the Rook and Bishop validation patterns
bool Moves::isValidQueenMove(int queenX, int queenY, int spaceX, int spaceY, teamType color, bool oppPiece) {
    return isValidRookMove(queenX, queenY, spaceX, spaceY, color, oppPiece) || isValidBishopMove(queenX, queenY, spaceX, spaceY, color, oppPiece);

}

// checks if a castle move is valid, if it is move the rook
void Moves::castle(Square* start, Square* end, Board* board) {
    if ((start->getPiece()->getPieceType() == KING) && (start->getPiece()->getColor() == BLACK)) {
        if ((start->getSquareX() == 4) && (start->getSquareY() == 0)) {
            if ((end->getSquareX() == 6) && (end->getSquareY() == 0) && (end->getPiece() == nullptr) && (board->getSquare(5, 0)->getPiece() == nullptr)) {
                if ((board->getSquare(7, 0)->getPiece()->getPieceType() == ROOK) && (board->getSquare(7, 0)->getPiece()->getColor() == BLACK)) {
                    board->getSquare(5, 0)->placedPiece(board->getSquare(7, 0)->getPiece());
                    board->getSquare(7, 0)->placedPiece(nullptr);
                }
            }
            else if ((end->getSquareX() == 2) && (end->getSquareY() == 0) && (end->getPiece() == nullptr) && (board->getSquare(1, 0)->getPiece() == nullptr) && (board->getSquare(3, 0)->getPiece() == nullptr)) {
                if ((board->getSquare(0, 0)->getPiece()->getPieceType() == ROOK) && (board->getSquare(0, 0)->getPiece()->getColor() == BLACK)) {
                    board->getSquare(3, 0)->placedPiece(board->getSquare(0, 0)->getPiece());
                    board->getSquare(0, 0)->placedPiece(nullptr);
                }
            }
        }
    }
    else if ((start->getPiece()->getPieceType() == KING) && (start->getPiece()->getColor() == WHITE)) {
        if ((start->getSquareX() == 4) && (start->getSquareY() == 7)) {
            if ((end->getSquareX() == 6) && (end->getSquareY() == 7) && (end->getPiece() == nullptr) && (board->getSquare(5, 7)->getPiece() == nullptr)) {
                if ((board->getSquare(7, 7)->getPiece()->getPieceType() == ROOK) && (board->getSquare(7, 7)->getPiece()->getColor() == WHITE)) {
                    board->getSquare(5, 7)->placedPiece(board->getSquare(7, 7)->getPiece());
                    board->getSquare(7, 7)->placedPiece(nullptr);
                }
            }
            else if ((end->getSquareX() == 2) && (end->getSquareY() == 7) && (end->getPiece() == nullptr) && (board->getSquare(1, 7)->getPiece() == nullptr) && (board->getSquare(3, 7)->getPiece() == nullptr)) {
                if ((board->getSquare(0, 7)->getPiece()->getPieceType() == ROOK) && (board->getSquare(0, 7)->getPiece()->getColor() == WHITE)) {
                    board->getSquare(3, 7)->placedPiece(board->getSquare(0, 7)->getPiece());
                    board->getSquare(0, 7)->placedPiece(nullptr);
                }
            }
        }
    }
}

// moves the piece on the board
void Moves::callForMove(){
    if (castleCheck == true) {      // if the move is a castle, call castle function to move rook
        castle(startPosition, endPosition, board);
    }
    delete endPosition->getPiece();         // delete the piece at the end square
    endPosition->placedPiece(startPosition->getPiece());        // place the piece on the end square
    startPosition->placedPiece(nullptr);       // clear the start square
}