Tic-Tac-Toe Game


Overview
This is a console-based implementation of the classic Tic-Tac-Toe game developed in C++. The game allows two players to take turns marking spaces in a 3x3 grid. The player who successfully places three of their marks in a row, column, or diagonal wins the game. If the grid is filled and no player has won, the game ends in a draw.
Features
•	User-Friendly Interface: Players interact with the game through a simple console-based interface.
•	Player Names: Players can enter their names, which are displayed during the game to indicate whose turn it is.
•	Error Handling: The game includes basic error handling for invalid inputs, such as entering a slot number outside the valid range.
•	Clear Screen: The screen is cleared before each major interaction to maintain a clean and easy-to-read interface.
•	Game Menu: The main menu provides options to learn about the game, start a new game, or exit the program.
How to Play
1.	Launch the Game: Run the program to display the main menu.
2.	About the Game: Choose "About the Game" to learn how to play.
3.	Start a New Game: Select "Start Game" to begin. You will be prompted to enter the names of the two players.
4.	Gameplay:
o	The game board is displayed with numbered slots from 1 to 9.
o	Players take turns entering the number corresponding to the slot where they want to place their marker.
o	The game automatically checks for a win or draw after each move.
5.	Winning the Game: A player wins by placing three markers in a row, column, or diagonal.
6.	Draw: If all slots are filled and no player has won, the game ends in a draw.
7.	Exit: Choose "Exit" from the main menu to quit the game.
System Requirements
•	C++ compiler
•	Compatible with Windows, Linux, and macOS (supports system("clear") and system("CLS") for screen clearing)
