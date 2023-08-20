#include <iostream>
#include <vector>
#include "menu.h"
using namespace std;

void menu() {
    cout << "Welcome to My Chess Game! By: John Hsu" << endl;       // intro message

    // Pick between new game or old saved game
    cout << "Would you like to play against Player2? (Type Yes or No)" << endl;
    string opponent;
    cin >> opponent;

    while(opponent != "Yes" && opponent != "No") {
            cout << "Not an option, pick a correct opponent option: ";
            cin >> opponent;            // Takes in option for human or computer player
    }
    if(opponent == "No"){
        return;
    }
    if(opponent == "Yes"){
        // creates a new board and sets the game up
        Board* board = new Board();
        board->newBoard();
        cout << board->printBoard() << endl;

        Player* player1 = new Player(HUMAN, white, board);
        Player* player2 = new Player(HUMAN, black, board);

        while(true){
            cout << "WHITE'S TURN" << endl;
            // first player moves
            player1->move();
            // move is printed to the board
            cout << board->printBoard() << endl;
            // check for checkmate after move
            if (player2->isCheckmated() || player1->isCheckmated()){
                break;
            }
            cout << "BLACK'S TURN" << endl;
            // second player mvoes
            player2->move();
            // move is printed to board again
            cout << board->printBoard() << endl;
            // check for checkmate
            if (player2->isCheckmated() || player1->isCheckmated()){
                break;
            }
        }
        // if there is a checkmate, end the game and print the winner
        if (player2->isCheckmated()){
            cout << "Player 2 (BLACK) has won the game!" << endl;
            delete player1;
            delete player2;
            delete board;
        }
        if (player1->isCheckmated()){
            cout << "Player 1 (WHITE) has won the game!" << endl;
            delete player1;
            delete player2;
            delete board;
        }   
    }
    
}




