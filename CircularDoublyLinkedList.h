//
// Created by Matthew Chan on 2016-11-19.
//

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

public:
	CircularDoublyLinkedList(); //constructor
	~CircularDoublyLinkedList(); //destructor
	void addHead(T item);
	unsigned int size() const;
	void print();
	void reversePrint();
	Node* getHead() { return m_head; }
	void move_head(bool direction); // to move left and right through the cdll

public:
	Node * m_head;
	Node * m_tail;
	unsigned int m_size;

public:
	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { 
			m_ptr = ptr; 
		}

		void operator++ () {
			m_ptr = m_ptr->next;	// for forward traversing, e,g, Iterator i=begin(); ... ++i
		} 

		

		void operator-- () {
			m_ptr = m_ptr->prev;	// for backward traversing
		}

		bool operator != (const Iterator& b) {
			return m_ptr != b.m_ptr;
		}

		T operator *() { 
			return m_ptr->value;
		}
		T getValue() {
			return m_ptr->value;
		}

		void setValue(T val) {
			m_ptr->value = val;
		}
	};

	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() { return Iterator(m_head); }
	Iterator end() { return Iterator(m_tail); }
};

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

template <class T>
void CircularDoublyLinkedList<T>::print() {
	int i = 0;
	Node* temp = m_head;
	std::cout << "Forward: ";
	while (i < m_size) {
		std::cout << temp->value << " ";
		temp = temp->next; // prints forwardly, as in 1,2,3,4,5..
		i++;
	}
	cout << endl;
}

template <class T>
void CircularDoublyLinkedList<T>::reversePrint() {

	int i = 0;
	Node* temp = m_tail;
	std::cout << "Reverse: ";

	while (i < m_size) {
		std::cout << temp->value << " ";
		temp = temp->prev; // prints in reverse, 20,19,18....
		i++;
	}
	cout << endl;
}

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







