/******************************************************************************
* dygw3
* DJ Yuhn
* Assignment 1
******************************************************************************/

#include <iostream>
#include "QueueLinkList.h"

void tryPop(QueueLinkList<int>& list);
void tryFront(QueueLinkList<int>& list);

int main() {

	// Testing the implementation of Stack using Linked List
	QueueLinkList<int> theQueue;

	theQueue.push(1);
	theQueue.push(2);

	tryPop(theQueue);
	tryFront(theQueue);

	tryFront(theQueue);
	tryPop(theQueue);

	tryPop(theQueue);

	system("Pause");
	return 0;
}

// Try to pop the top item from the Stack.
void tryPop(QueueLinkList<int>& list)
{
	try {
		std::cout << list.pop() << " was removed from the queue.\n";
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what() << std::endl;
	}
}

// Try to view the top item of the stack.
void tryFront(QueueLinkList<int>& list)
{
	try {
		std::cout << list.getFront() << " is at the front of the queue.\n";
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what() << std::endl;
	}
}