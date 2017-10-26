/******************************************************************************
* dygw3
* DJ Yuhn
* 10/26/17
* Assignment 1
******************************************************************************/
#include <iostream>

#ifndef STACKLINKLIST_H
#define STACKLINKLIST_H

template<class T>
class StackLinkList {
public:
	StackLinkList() { top = nullptr; }

	T getTop() const { 
		if (top != nullptr) {
			return top->data;
		}
		else {
			std::cout << "\nStack is empty.\n";
		}
	}

	void push(T value) {
		// Create new node and insert the value into data
		Node *temp = new Node;
		temp->data = value;

		// If stack is empty, have the new node be the top.    
		if (top == nullptr)
			temp->next = nullptr;
		// If stack is not empty, have the new node point to the node below it.
		else
			temp->next = top;

		// Assign top to be the new node.
		top = temp;
	}
	
	void pop() {
		// Check to see if stack is empty.
		if (top == nullptr)
			std::cout << "Stack is empty.";

		// If stack is not empty, delete the top node.
		else {
			Node *temp = top;
			top = temp->next;
			delete temp;
			temp = nullptr;
		}
	}

private:
	struct Node {
		T data;
		Node *next;
	};

	Node *top;

};

#endif