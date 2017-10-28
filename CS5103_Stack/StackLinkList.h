/******************************************************************************
* dygw3
* DJ Yuhn
* 10/26/17
* Assignment 1
******************************************************************************/

#ifndef STACKLINKLIST_H
#define STACKLINKLIST_H

#include <iostream>

template<class T>
class StackLinkList {

public:
	StackLinkList() { top = nullptr; }
	~StackLinkList() { deleteList(); }
	
	StackLinkList(const StackLinkList &obj);

	StackLinkList& operator=(const StackLinkList& rhs);

	// Get the top node in the stack's data value
	T getTop() const;

	// Add a new node to the top of the stack with a data value
	void push(T value);

	// Remove the node from the top of the stack
	T pop();

	// Check if the linked list is empty
	bool isEmpty() const { return top == nullptr; }

private:
	// Structure for nodes in the list to hold data
	struct Node {
		T data;
		Node *next = nullptr;
	};

	Node *top; // Pointer to top of the stack

	// Delete entirety of the list
	void deleteList();

	// Deep copy the linked lists
	void deepCopy(const StackLinkList& obj);

};

template<class T>
StackLinkList<T>::StackLinkList(const StackLinkList &obj) {
	if (obj.top == nullptr)
		this->top = nullptr;

	// Perform deep copy
	else
		this->deepCopy(obj)
};

template<class T>
StackLinkList<T>& StackLinkList<T>::operator=(const StackLinkList& rhs) {
	if (this != &rhs) {
		this->deleteList();
		this->deepCopy(rhs);
	}

	return *this;
};

template<class T>
T StackLinkList<T>::getTop() const {
	// Check to see if stack is empty and throw exception if true.
	if (isEmpty())
		throw std::out_of_range("Stack is empty.");

	else
		return top->data;
};

template<class T>
void StackLinkList<T>::push(T value) {
	// Create new node and insert the value into data
	Node *temp = new Node;
	temp->data = value;

	// If stack is empty point top to temp
	if (isEmpty())
		top = temp;

	// Have temp next pointer point to top. Aassign top to temp.
	else {
		temp->next = top;
		top = temp;
	}
};

template<class T>
T StackLinkList<T>::pop() {
	// Check to see if stack is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("Stack is empty.");

	// If stack is not empty, delete the top node and return its value
	else {
		Node *temp = top;
		top = temp->next;

		T data = temp->data;

		delete temp;
		temp = nullptr;

		return data;
	}
}

template<class T>
void StackLinkList<T>::deleteList() {
	Node *temp = nullptr;

	// Check if list has any nodes and continue to delete until empty
	while (!isEmpty()) {
		temp = top;
		top = temp->next;

		delete temp;
	}

	top = nullptr;
	temp = nullptr;
}

template<class T>
void StackLinkList<T>::deepCopy(const StackLinkList& obj) {
	Node* p1; // Pointer for this current node
	Node* o1; // Pointer for obj next node

	this->top = new Node;
	this->top->data = obj.top->data;

	p1 = top;
	o1 = obj.top->next;

	while (o1 != nullptr) {
		p1->next = new Node;
		p1->next->data = o1->data;
		p1 = p1->next;
		o1 = o1->next;
	}
}
;

#endif