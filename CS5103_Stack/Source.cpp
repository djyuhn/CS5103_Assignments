/******************************************************************************
* dygw3
* DJ Yuhn
* 10/26/17
* Assignment 1
******************************************************************************/

#include <iostream>
#include "StackLinkList.h"

int main() {
	
	// Testing the implementation of Stack using Linked List
	StackLinkList<int> theStack;
	int theTop;

	theStack.push(1);
	theStack.push(2);
	theStack.push(3);
	theStack.push(4);

	std::cout << theStack.getTop() << " is the top most item in the Stack.\n";

	theStack.pop();

	std::cout << theStack.getTop() << " is now the top most item.\n";

	theStack.pop();

	std::cout << theStack.getTop() << " is now the top most item.\n";


	system("Pause");
	return 0;
}