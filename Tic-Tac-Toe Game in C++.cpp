//This is a console-based implementation of the classic Tic-Tac-Toe game developed in C++. 
//The game allows two players to take turns marking spaces in a 3x3 grid. 
//The player who successfully places three of their marks in a row, column, or diagonal wins the game. 
//If the grid is filled and no player has won, the game ends in a draw.
//By JEREMIE MWEMBO BASASE(Jeje_bass)

#include <iostream>
#include <limits> // For handling input validation
#include <cstdlib> // For system() to clear the screen
using namespace std;

// Global variables for the game board, markers, and player details
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker; // Current player's marker (X or O)
int currentPlayer;  // Current player's number (1 or 2)
string player1Name, player2Name; // Names of the players

// Function to clear the screen
// This ensures a clean and uncluttered interface for the user
void clearScreen() {
    // For Windows
    #ifdef _WIN32
    system("CLS");
    // For Unix/Linux/Mac
    #else
    system("clear");
    #endif
}

// Function to display the game title and player names
// This function is called at the beginning of every major interaction to keep the title and player information visible
void displayTitle() {
    cout << "===================" << endl;
    cout << "   TIC-TAC-TOE   " << endl;
    cout << "===================" << endl;
    cout << "Player 1: " << player1Name << " (X)" << endl;
    cout << "Player 2: " << player2Name << " (O)" << endl;
    cout << "===================\n" << endl;
}

// Function to display the current state of the game board
// This provides a visual representation of the game for the players
void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to place the current player's marker on the board
// Returns true if the marker is successfully placed, false if the slot is already occupied
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        cout << "Slot already occupied! Try again." << endl;
        return false;
    }
}

// Function to check if the current player has won the game
// Returns the player number (1 or 2) if they have won, 0 if there is no winner
int checkWin() {
    // Check rows, columns, and diagonals for a win
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
    }
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0; // No win detected
}

// Function to switch the current player and marker after each turn
// This function alternates turns between the two players
void swapPlayerAndMarker() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Function to get valid input from the user
// Ensures that the input is a number between 1 and 9 and corresponds to an available slot
int getValidInput() {
    int slot;
    while (true) {
        cout << "It's " << ((currentPlayer == 1) ? player1Name : player2Name) << "'s turn. Enter your slot (1-9): ";
        cin >> slot;

        // Check if the input is a number and within the valid range
        if(cin.fail() || slot < 1 || slot > 9) {
            cout << "Invalid input! Please enter a number between 1 and 9." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            break;
        }
    }
    return slot;
}

// Function to reset the board for a new game
// This restores the board to its initial state with numbered slots
void resetBoard() {
    char initial[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = initial[i][j];
        }
    }
}

// Function to display the "About the Game" information
// This provides players with an overview of how to play the game
void aboutGame() {
    clearScreen();
    displayTitle();
    cout << "\n--- About the Game ---" << endl;
    cout << "Tic-Tac-Toe is a simple game where two players take turns" << endl;
    cout << "marking spaces in a 3x3 grid. The player who places three" << endl;
    cout << "marks in a row, column, or diagonal wins the game." << endl;
    cout << "If all spaces are filled and no player has won, the game ends in a draw.\n" << endl;
    cout << "\t\tBY JEREMIE MWEMBO BASASE\n\n";
    cout << "Press Enter to return to the main menu...";
    cin.ignore();
    cin.get(); // Wait for the user to press Enter
    clearScreen();
}

// Main game function
// Handles the flow of the game, including alternating turns, checking for a winner, and displaying the results
void game() {
    resetBoard(); // Reset the board for a new game

    clearScreen();
    displayTitle();

    int playerWon = 0;

    for(int i = 0; i < 9; i++) {
        drawBoard(); // Display the board after each move
        int slot = getValidInput(); // Get a valid input from the player

        // Attempt to place the marker; if failed, prompt again
        if(!placeMarker(slot)) {
            i--; // Don't count invalid moves
            continue;
        }

        clearScreen();
        displayTitle();

        playerWon = checkWin(); // Check if there's a winner

        if(playerWon == 1 || playerWon == 2) {
            drawBoard();
            cout << "Congratulations! " << ((playerWon == 1) ? player1Name : player2Name) << " wins!" << endl;
            break;
        }

        swapPlayerAndMarker(); // Switch turns
    }

    if(playerWon == 0) {
        drawBoard();
        cout << "It's a draw!" << endl; // No winner after 9 moves
    }

    cout << "Press Enter to return to the main menu...";
    cin.ignore();
    cin.get(); // Wait for the user to press Enter
    clearScreen();
}

// Function to display the main menu and handle user selection
// Provides options to view game info, start the game, or exit
void mainMenu() {
    int choice;
    do {
        clearScreen();
        displayTitle();

        // Display menu options
        cout << "--- Main Menu ---" << endl;
        cout << "1. About the Game" << endl;
        cout << "2. Start Game" << endl;
        cout << "3. Exit" << endl;
        cout << "Please choose an option (1-3): ";
        cin >> choice;

        // Handle menu selection
        switch(choice) {
            case 1:
                aboutGame(); // Display about information
                break;
            case 2:
                clearScreen();
                displayTitle();
                // Get player names before starting the game
                cout << "Enter Player 1's name: ";
                cin >> player1Name;
                cout << "Enter Player 2's name: ";
                cin >> player2Name;
                game(); // Start the game
                break;
            case 3:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option! Please choose 1, 2, or 3." << endl;
                cout << "Press Enter to try again...";
                cin.ignore();
                cin.get(); // Wait for the user to press Enter
        }
    } while(choice != 3); // Repeat menu until user chooses to exit
}

// Main function
// Entry point for the program, starts by displaying the main menu
int main() {
    mainMenu(); // Start the main menu
    return 0;
}
