/******************************************************************************
* dygw3
* DJ Yuhn
* Assignment 1
******************************************************************************/

#include <iostream>
#include "DoublyLinkedList.h"


int main() {

	DoublyLinkedList<int> dblList;

	std::cout << dblList.getSize() << std::endl;

	dblList.pushFront(1);
	dblList.pushBack(3);
	dblList.insertAt(2, 1);
	dblList.insertAt(0, 0);

	std::cout << dblList.getSize() << std::endl;

	std::cout << dblList.deleteFront() << " was deleted from the front." << std::endl;
	std::cout << dblList.deleteAt(1) << " was deleted from index 1." << std::endl;
	std::cout << dblList.deleteBack() << " was deleted from the back." << std::endl;

	system("Pause");
	return 0;
}