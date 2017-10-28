/******************************************************************************
* dygw3
* DJ Yuhn
* 10/26/17
* Assignment 1
******************************************************************************/

#include <iostream>
#include "StackLinkList.h"

void tryPop(StackLinkList<int>& list);
void tryTop(StackLinkList<int>& list);

int main() {
	
	// Testing the implementation of Stack using Linked List
	StackLinkList<int> theStack;

	theStack.push(1);
	theStack.push(2);

	tryPop(theStack);
	tryTop(theStack);

	tryPop(theStack);
	tryPop(theStack);

	system("Pause");
	return 0;
}

// Try to pop the top item from the Stack.
void tryPop(StackLinkList<int>& list)
{
	try {
		std::cout << list.pop() << " was removed from the stack.\n";
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what() << std::endl;
	}
}

// Try to view the top item of the stack.
void tryTop(StackLinkList<int>& list)
{
	try {
		std::cout << list.getTop() << " is at the top of the Stack.\n";
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what() << std::endl;
	}
}
