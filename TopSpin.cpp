#include "TopSpin.h"

// wip

TopSpin::TopSpin(int size, int spinSize)
{
	if (size < 1 || spinSize > size) {
		// checks for valid entry, if invalid defaults to game size of 20, and spinSize of 4.
		cout << "Invalid Entry, Game has defaulted to a boardSize of 20, and spinSize of 4." << endl;
		m_boardSize = 20;
		m_spinSize = 4;
	}
	else {
		m_boardSize = size;
		m_spinSize = spinSize;
	}

	for (int i = 1; i <= size; i++) {
		gameBoard.addHead(i); // adds the values of the gameBoard to the CircularDoublyLL
		// cout << "| " <<  gameBoard.getHead()->value;
	}
}


/*ostream & operator<<(std::ostream & os, const TopSpin & ts)
{
	// TODO: insert return statement here
	return;
}*/
