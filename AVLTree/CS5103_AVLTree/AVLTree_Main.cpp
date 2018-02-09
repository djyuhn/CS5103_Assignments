/**
CS5103 - Assignment 2 AVL Tree
AVLTree_Main.cpp

@author DJ Yuhn
*/

#include <iostream>
#include "AVL.h"

int main() {
	AVL<int> tree;
	int arr[] = { 9,27,50,15,2,21,18,32,44,28,36 }; //Sequence of numbers given


	for (int i = 0; i < 11; i++) {
		if (i == 0) {
			std::cout << arr[i] << " was inserted into the tree." << std::endl;
			tree.insert(arr[i]);
			std::cout << "The following is the tree's data inorder:" 
				<< std::endl;
			
			tree.inorder();
			std::cout << "\nThe height of the tree is: " 
				<< tree.getTreeHeight() << std::endl;
		}
		else {
			std::cout << "\n\n" << arr[i] << " was inserted into the tree.";
			tree.insert(arr[i]);
			std::cout << "\nThe following is the tree's data inorder after any necessary rotations:" 
				<< std::endl;
			
			tree.inorder();
			std::cout << "\nThe height of the tree is: "
				<< tree.getTreeHeight() << std::endl;
		}
	}

	return 0;
};
