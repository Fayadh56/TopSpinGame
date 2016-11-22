#include "TopSpin.h"
#include <iostream>
#include <string>


using namespace std;



int main()
{

	int gameBoard, spinSize;
	
	cout << "Welcome to TopSpin - A game created by Fayadh A. \n";
	cout << "This game is base on the popular TopSpin Puzzle \n";

	cout << "Please enter the Game Board Size \n";
	cin >> gameBoard;

	cout << "Please enter the Spinner Size you'd like \n";
	cin >> spinSize;


	// Creating game board
	// TEST
	TopSpin theGameBoard(gameBoard, spinSize);

	// cout << a "\n"; ???
	// THIS IS FOR TESTING. 
	

	
}
