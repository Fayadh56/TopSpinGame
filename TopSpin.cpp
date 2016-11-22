/* Made by Fayadh Ahamed Mohamed Nafeez, 
 * Student Number 250833038 */

#include "TopSpin.h"

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
		
	}
}

void TopSpin::shiftLeft()
{
	gameBoard.move_head(0); // see my iterator in CDLL for more info on move_head
}

void TopSpin::shiftRight()
{
	gameBoard.move_head(1);	// see my iterator in CDLL for more info on move_head
}


// spins the top, by swapping the numbers
void TopSpin::spin()
{
	// create two iterators
	CircularDoublyLinkedList<int>::Iterator a(gameBoard.getHead());
	CircularDoublyLinkedList<int>::Iterator b(gameBoard.getHead());

	for (int i = 1; i < m_spinSize; ++i) {
		++a; // get to swap location
	}
	for (int k = 1; k <= (m_spinSize / 2); k++) {
		int temp = b.getValue();
		b.setValue(a.getValue());
		a.setValue(temp);
		++b;
		--a;
	}
}


// checks to see if the board is solved
bool TopSpin::isSolved()
{
	CircularDoublyLinkedList<int>::Iterator solution(gameBoard.getHead());
	bool foundStart = false;
	while (!foundStart) {
		(solution.getValue() == 1) ? foundStart = true : ++solution;
	}
	for (int valueOfNode = solution.getValue(); valueOfNode < m_boardSize; valueOfNode++, --solution) {
		if (valueOfNode != solution.getValue()) {
			return false; // if its not solved return false
		}
	}
	cout << "Congratulations you've solved it!" << "\n";
	return true;
}


// Overloaded output operator, to be able to print a TopSpin object

ostream & operator<<(std::ostream &os, const TopSpin &ts)
{
	CircularDoublyLinkedList<int> :: Iterator it = (ts.gameBoard).begin();
	
	cout << "|_";
	for (int i = 0; i < ts.m_spinSize; i++) {
		cout << "__";
	}
	cout << "__|\n";

	for (int i = 0; i < ts.m_boardSize; i++, ++it) {
		if (i == 0 || i == ts.m_spinSize)
			cout << "|";
		os << it.getValue() << " ";
		
	}
	cout << "\n";
	cout << "|_";

	for (int i = 0; i < ts.m_spinSize; i++) {
		cout << "__";
	}
	cout << "__|\n";

	return os;
}
