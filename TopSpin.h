/* Made by Fayadh Ahamed Mohamed Nafeez,
* Student Number 250833038 */
#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;


class TopSpinADT {
public:
	virtual void shiftLeft() = 0;
	virtual void shiftRight() = 0;
	virtual void spin() = 0;	
	virtual bool isSolved() = 0;	
};

class TopSpin : public TopSpinADT {

private:
	int m_boardSize;
	int m_spinSize;
	CircularDoublyLinkedList<int> gameBoard; // circular doubly linked list of game board 

public:
	TopSpin(int size, int spinSize); // overloaded constructor


	// Top Spin ADT Functions implemented
	void shiftLeft();
	void shiftRight();
	void spin();	
	bool isSolved();	


	// overloading the ostream << operator to be able to print out the board
	// declared as friend as without get a too many parameters in the operator error (in visual studio)
	friend ostream& operator<< (std::ostream &os, const TopSpin &ts);
};



