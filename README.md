# Chess Game

> Why create a Chess Game?\
Chess is a game that even the computer or AI cannot manage to master as there is an infinite number of possibilities to play. The project provides grounds to allow players to explore different moves and strategies. A chess game contains various strategies and methods to play. While the movements of the pieces may seem simple, the combinations of movements that occur tell a story that the project can help show as well. The movements may reveal vulnerabilities in the way we think or the strengths in the way we implement the strategies. Chess allows us to reveal how we think and that is why making a way to implement the game of chess allows us to show the love for the nature of the game.

> Languages/Tools/Technologies:\
C++

> Input / Outputs:\
Input option for player vs player
Input a chess move
Output the winner of the chess game
Output the result of a move

> Project Features:\
Players should be able to verse another player.
Players should have the option to move and take pieces from the opponent.
Players should be able to see if a move will put them into check.

> Description:\
> There will be 3 main classes: Board, Pieces, and Moves. The Board class will contain pieces and squares. The purpose of the Board class is to recognize where the pieces are when moved by the user. The Pieces class will have 6 derived classes, one for each piece of the Chess Game. These pieces are Pawn, King, Queen, Bishop, Knight, and Rook. The purpose of the Pieces class is to create pieces on the board where each piece has a team color and location on the board. The purpose of the Move class is to get valid user moves, determine whether the game is in check or checkmate and whether the game has ended.

> Class Diagram:
> 
![Chess Game Class Diagram](https://github.com/johnh0425/ChessGame/assets/116481391/038b7ba9-49dc-41d4-9532-3d9be239d109)
> User Diagram:
> 
![User Diagram](https://github.com/johnh0425/ChessGame/assets/116481391/c17a6fc8-b49b-4967-a741-293189afafd3)

>  Screen Descriptions:\
> Main Menu\
The options for the user on the main menu will be to begin the game or exit the program. Attempting to begin the game will present a Y/N to both users if they would like to begin. The “Exit” option will present a Y/N choice if the user would like to quit the program.

>Chess Board\
The board screen will present the players with both teams, with the white team at the bottom of the board, and the black team at the top. Moving a chess piece will notify the player if such a move is possible. With the completion of a game, the winner will be displayed before the starting menu is once again displayed.

 > SOLID Principles\
 > Single Responsibility Principle (SRP)\
The Single Responsibility Principle implements classes that should only have a single responsibility, that is, only changes to one part of the software’s specification should be able to affect the specification of the class. The Board class deals with and has the responsibility of setting up the chessboard. The Square class deals with storing the location on the board and knowing where the pieces are on the board. The Piece class will have the responsibility of dealing with each piece and how they will be moved. The Game class has the responsibility of dealing with the specific rules of the chess game. The Menu class will have the responsibility of printing options and the board to the terminal. This helped better the code by organizing code to better pick up on errors and reduce the chances of writing unnecessary code.

 > Open-Closed Principle (OCP)\
The Open-Closed Principles allow the software entities to be open for extension but closed for modification. The Computer class and Human class inherit from playerType. This allows for an open extension if we were to in the future add another player type like a more advanced computer player rather than having to modify old classes. This principle allows us to easily implement new enhancements to the code while leaving the original code alone. This reduces the chances of creating errors in the previous working code or code that other group members have developed.
 
 > Interface Segregation Principle (ISP)\
The Interface Segregation Principle is when the client should never be forced to implement an interface that it doesn’t use, or clients shouldn’t be forced to depend on methods they do not use. In the project, each specific chess piece inherits from a piece class. Since all pieces in a chess board can take a piece or are able to move, these functions are placed into the parent Piece class so all chess pieces can inherit. For functions unique to each piece like a rook and king being able to castle, these function implementations are created within the specific Rook children class that inherits from the Piece class. Overall the main idea is that high-level classes do not depend on low-level classes. This implementation of the ISP helps stop the code from being more bloated.

> Game Terminal Visuals\
> User screen prompt and first user input.
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/732002d0-5042-41d4-9afb-862d51247db0">
>
> 
> Prevent any moves that keep you in check
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/ab5a2753-9a1b-493c-b17a-5f3010f8f4b1">
>
> 
> Player 1 (WHITE) puts Player 2 (BLACK) in checkmate
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/76219610-e995-4aa0-9e30-4fa663098bf4">
>
> WHITE: Invalid move is inputted
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/6a98fc1c-162d-401e-a2db-19575775d51b">
>
> WHITE performs a castle move with King and Rook
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/74770da4-9f5e-4384-b19a-dce99ec319ff">
>
> Cannot make moves that puts yourself in check
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/bb6ef55f-3e4d-48b4-9b58-2e30a48de27d">
>
> BLACK cannot move WHITE pieces
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/d5311aad-ca25-448e-821b-4b87b1464a49">
>
> Player 2 (BLACK) puts Player 1 (WHITE) in checkmate
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/5722a2f3-e689-4cc0-9b00-8e93096a10c8">
>
> WHITE promotes a Pawn to a Queen
>
> 
> <img width="500" alt="image" src="https://github.com/johnh0425/ChessGame/assets/116481391/467acd03-d963-40cb-9048-f42f9f7788ca">

> Installation/Usage\
> Compile and run in the terminal using g++ and ./a.out, or using CMakeLists and cmake to compile. Then the user will be prompted if they wish to play a game with another user. At the start of a game, the chess board will be printed, the white team at the bottom of the board and the black team at the top. The chess board acts as a grid with an x and y-axis. Following the standard rules of chess, the white moves first. The player on the white team will be prompted for the x coordinate of the piece that they want to move, followed by the y coordinate. If an invalid coordinate is entered for either value, the user will be prompted to enter a new value. The program will then ask for the x and y coordinates of where the user would like that piece to move, similar to the previous prompts. Upon a valid entry, the piece will be moved and the board will be reprinted to show the change. The game will then alternate between black and white for their respective turns until a checkmate is achieved by either side and the game is brought to an end.
