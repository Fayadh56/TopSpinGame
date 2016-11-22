#include "TopSpin.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <string>

/* THIS ONLY WORKS ON WINDOWS - AS I NEEDED THE WINDOWS.H LIBRARY 
	AND THE CONIO.H Library. */

// definitions for my keyboard controls of the game, using the conio.h and a switch-case loop
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE ' '

/* READ MEEEE
 * My game is controlled using the Arrow keys( Left arrow key to move left one unit, Right arrow key to move right one Unit
 * this was done using the conio.h library, and getch() in my switch case. I clear the console after each press, so its kind of animated
 * also, to choose right spin, enter 1, and left spin enter 0 for initializing the game properly. 
 * Hope this is a good implementation of the game. 
 * Fayadh Ahamed Mohamed Nafeez - Student Number 250833038
*/

using namespace std;
void printGameBoardInstructions();


int main()
{
	int c = 0;
	int gameBoard, spinSize, noOfShifts;
	bool direction = 0;

	cout << "Welcome to TopSpin - A game created by Fayadh Ahamed Mohamed Nafeez \n" << "\n";
	cout << "This game is base on the popular TopSpin Puzzle \n" << "\n";
	cout << "\n" << "Please enter the Game Board Size \n" << "\n";
	cin >> gameBoard;
	cout << "\n" << "Please enter the Spinner Size you'd like \n" << "\n";
	cin >> spinSize;
	cout << "\n" << "How many shifts would you like to start with?? \n" << "\n";
	cin >> noOfShifts;
	cout << "\n";
	cout << "\n" << "What direction should we shift the board in?? Enter 1 for Right, 0 for Left. \n" << "\n";
	cin >> direction;

	// initialize the game board
	TopSpin theGameBoard(gameBoard, spinSize);
	cout << "\n" << "Please hold on while we initialize your game \n" << "\n";
	cout << "Randomizing your board\n";

	for (int i = 0; i < noOfShifts; i++) {
		if (direction) {
			theGameBoard.shiftRight();
			theGameBoard.spin();
		}
			else {
				theGameBoard.shiftLeft();
				theGameBoard.spin();
			}
	}
	

	// Should randomize board now before allowing the user to play...
	// call the randomShift function to spin and shift the board according to noOfShifts, and choosen direction
	// Now print the game board
	cout << theGameBoard << endl;
	
	// begin loop
	while (1) {
		c = 0;
		switch ((c = _getch())) {
		case KEY_RIGHT:
			theGameBoard.shiftRight();
			cout << "Right key pressed\n" << theGameBoard << endl;
			if (theGameBoard.isSolved()) return 0;
			break;
		case KEY_LEFT:
			theGameBoard.shiftLeft();
			cout << "Left Key Pressed\n" << theGameBoard << endl;
			if (theGameBoard.isSolved()) return 0;
			break;
		case KEY_SPACE:
			theGameBoard.spin();
			cout << "You've spun the top\n" << theGameBoard << endl;
			if (theGameBoard.isSolved()) return 0;
			break;

		case KEY_UP:
			cout << "Thank you for playing\n"; // hit the up key to exit the game
			return 0;
			break;
		default:
			system("cls");
			printGameBoardInstructions();
			break;
		}
	}
}

void printGameBoardInstructions()
{
	cout << " Hit the Right arrow to shift Right \n Hit the left arrow to shift left \n Hit space to spin the top! \n Hit the Up Key to exit the game at anytime\n" << endl;
}

