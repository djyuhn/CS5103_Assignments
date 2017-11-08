/******************************************************************************
* dygw3
* DJ Yuhn
* Assignment 1
******************************************************************************/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


template<class T>
class BinarySearchTree {
public:
	BinarySearchTree() { root = nullptr; }
	~BinarySearchTree();

	BinarySearchTree(const BinarySearchTree &obj);
	BinarySearchTree& operator= (const BinarySearchTree& rhs);

	void insert(T data); // Allow user to insert data into the tree
	node *search(T data); // Allow user to search through tree
	void destroy_tree(); // Allow user to delete all nodes from the tree

	// Allow user to output to command line various orders of the tree
	T preorder();
	T inorder(); 
	T postorder();
	

private:
	struct node {
		T data;
		node *left;
		node *right;
	};

	node *root; // Root of the tree

	void destroyTree(node *leaf); // Recursively destroy the tree
	void insert(T data, node *leaf); // Recursively insert the data
	node *search(T data, node* leaf); // Recursively search for the data

	// Recursively output data from the tree.
	T preorder(node* leaf);
	T inorder(node* leaf);
	T postorder(node* leaf);

};


#endif // !BINARYSEARCHTREE_H
