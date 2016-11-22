// TopSpin.h

#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

// 

class TopSpinADT {
public:
	//virtual void shiftLeft() = 0;
	//virtual void shiftRight() = 0;
	//virtual void spin() = 0;
	//virtual bool isSolved() = 0;
};

class TopSpin : public TopSpinADT {
	// WIP
private:
	int m_boardSize;
	int m_spinSize;
	CircularDoublyLinkedList<int> gameBoard; // circular doubly linked list of game board 

public:
	TopSpin(int size, int spinSize); // overloaded constructor


	// TopSpin functions
	int getSize() const;
	//void shiftLeft();
	//void shiftRight();
	//void spin();
	//bool isSolved();
};

ostream& operator<< (std::ostream& os, const TopSpin& ts);
