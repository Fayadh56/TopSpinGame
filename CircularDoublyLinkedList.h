/* Made by Fayadh Ahamed Mohamed Nafeez,
* Student Number 250833038 */


#pragma once
#include <iostream>
template <class T>
class CircularDoublyLinkedList {
public:
	class Node {
	public:
		Node(T val, Node * nx = nullptr, Node * prv = nullptr) : value(val), next(nx), prev(prv) { };
		T value;
		Node * next;
		Node * prev;
	};
	// end of Node Class

public:
	CircularDoublyLinkedList(); //constructor
	~CircularDoublyLinkedList(); //destructor
	void addHead(T item);
	unsigned int size() const;
	Node* getHead() { return m_head; }
	void move_head(bool direction); // to move left and right through the cdll

public:
	Node * m_head;
	Node * m_tail;
	unsigned int m_size;

public:
	class Iterator { // iterators for secure traversal of the cd-linkedlists
	private:
		Node* m_ptr; // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) {m_ptr = ptr;}
		void operator++ () {m_ptr = m_ptr->next;} 
		void operator-- () {m_ptr = m_ptr->prev;}	// for backward traversing
		bool operator != (const Iterator& b) {return m_ptr != b.m_ptr;}
		T getValue() {return m_ptr->value;}
		void setValue(T val) {m_ptr->value = val;}
	}; 
	// End of Iterator Class

	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() const {return Iterator(m_head);} //must have const, so as to prevent outside modification 
	Iterator end() const {return Iterator(m_tail);}
	Iterator getHead() const { return Iterator(m_head); }
};
// End of CDLL class

template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(): m_head(nullptr), m_tail(nullptr), m_size(0)
{
	cout << "The game board has been created" << std::endl;
}

template <class T>
void CircularDoublyLinkedList<T>::addHead(T item)
{
	m_head = new Node(item, m_head, m_tail); 
	if (m_tail == NULL) {
		m_tail = m_head; // m_tail and m_head point to the same thing
		m_head->next = m_head;
		m_head->prev = m_head;
	}
	else {
		m_tail->next = m_head; //make your tail node pointer point to the new m_head
		m_head->next->prev = m_head; 
	}

	m_size++;
}

// getSize of CircularDoublyLinkedList
template <class T>
unsigned int CircularDoublyLinkedList<T> ::size() const { 
	return m_size;
}

//destructor
template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() { 
	Node * here = m_head, *nextNode;
	while (this->m_size > 0) {
		nextNode = here->next;
		delete here;
		here = nextNode;
		m_size--;
		//cout << "Destructor called" << endl;
	}

}

// My move head function, which moves the head from one node to the other, either left(backwards) or right(forwards)

template <class T>
void CircularDoublyLinkedList<T>::move_head(bool direction) {
	if (direction) {
		// move right
		m_head = m_head->next;
		m_tail = m_tail->next;
	}
	else {
		// moving left
		m_head = m_head->prev;
		m_tail = m_tail->prev;
	}
}







