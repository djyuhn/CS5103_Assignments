/**
CS5103 - Assignment 2 AVL Tree
AVLTree_Main.cpp

@author DJ Yuhn
*/

#include <iostream>
#include "AVL.h"

int main() {
	AVL<int> tree;

	tree.insert(9);
	tree.insert(27);
	tree.insert(50);
	tree.insert(15);
	tree.insert(2);
	tree.insert(21);
	tree.insert(18);
	tree.insert(32);
	tree.insert(44);
	tree.insert(28);
	tree.insert(36);

	return 0;
};