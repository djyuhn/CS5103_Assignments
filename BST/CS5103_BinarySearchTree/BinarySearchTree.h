/**
	CS5103 - Assignment 2

	@author DJ Yuhn
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>


template<class T>
class BinarySearchTree {
public:
	BinarySearchTree() { root = nullptr; }
	~BinarySearchTree();

	BinarySearchTree(const BinarySearchTree &obj);
	BinarySearchTree& operator= (const BinarySearchTree& rhs);

	void insert(T data); // Allow user to insert data into the tree
	bool *search(T data); // Return true if data is found in tree, false if not
	void destroyTree(); // Allow user to delete all nodes from the tree
	void deleteNode(T data); // Allow user to delete node holding the data
	
	void preorder() { preorder(root); } // Output to command line preorder data
	void inorder() { inorder(root); } // Output to command line inorder data
	void postorder() { postorder(root); } // Output to command line postorder data
	

private:
	struct node {
		T data;
		node *left;
		node *right;
		node *parent;
	};

	node *root; // Root of the tree

	void insert(T data, node *leaf); // Recursively traverse tree to insert data
	node *search(T data, node* leaf); // Recursively search for the data
	void destroyTree(node *leaf); // Recursively destroy the tree
	void deleteNode(T data, node* leaf); // Recursively find node to delete


	void preorder(node* leaf);
	void inorder(node* leaf);
	void postorder(node* leaf);

	void copyTree(node *& sourceRoot, node *& thisRoot); // Copy from a source root
	node *searchMax(node* leaf);
	node *searchMin(node* leaf);

};


template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	destroyTree(root);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree & obj) {
	copyTree(obj->root, this->root);
};

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree & rhs)
{
	if (this != &rhs) {
		destroyTree(this->root);
		root = nullptr;
		copyTree(rhs.root, this->root);
	}
};

template<class T>
void BinarySearchTree<T>::insert(T data) {
	if (root != nullptr)
		insert(data, root);

	else {
		root = new node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
	}
};

template<class T>
bool * BinarySearchTree<T>::search(T data) {
	node* nodePtr = search(data, root);
	
	return (nodePtr != nullptr); // If nodePtr is nullptr, data was not found.
};

template<class T>
void BinarySearchTree<T>::destroyTree() {
	destroyTree(root);
};

template<class T>
void BinarySearchTree<T>::deleteNode(T data) {
	deleteNode(data, root);
};

template<class T>
void BinarySearchTree<T>::destroyTree(node* leaf) {
	if (leaf != nullptr) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
};

template<class T>
void BinarySearchTree<T>::deleteNode(T data, node * leaf)
{
	node* nodePtr = nullptr;

	if (leaf == nullptr)
		return nullptr;
	else if (data < leaf->data)
		leaf->left = deleteNode(data, leaf->left);
	else if (data > leaf->data)
		leaf->right = deleteNode(data, leaf->right);
	else if (leaf->left != nullptr && leaf->right != nullptr) {
		nodePtr = searchMin(leaf->right);
		leaf->data = nodePtr->data;
		leaf->right = deleteNode(leaf->data, leaf->right);
	}
	else {
		nodePtr = leaf;
		if (leaf->left == nullptr)
			leaf = leaf->right;
		else if (leaf->right == nullptr)
			leaf = leaf->left;
		delete nodePtr;
	}

	return leaf;
};

template<class T>
void BinarySearchTree<T>::insert(T data, node * leaf) {
	if (data < leaf->data) {
		if (leaf->left != nullptr)
			insert(data, leaf->left);
		else {
			leaf->left = new node;
			leaf->left->data = data;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
			leaf->left->parent = leaf;
		}
	}

	else if (data >= leaf->data) {
		if (leaf->right != nullptr)
			insert(data, leaf->right);
		else {
			leaf->right = new node;
			leaf->right->data = data;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
			leaf->right->parent = leaf;
		}
	}
};

template<class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::search(T data, node * leaf)
{
	if (leaf == nullptr)
		return nullptr;

	else if (data < leaf->data)
		return search(data, leaf->left);

	else if (data > leaf->data)
		return search(data, leaf->right);

	else
		return leaf;
};

template<class T>
void BinarySearchTree<T>::preorder(node * leaf) {
	if (root == nullptr)
		std::cout << "Tree is empty" << std::endl;

	else if (leaf != nullptr) {
		std::cout << leaf->data << " ";
		preorder(leaf->left);
		preorder(leaf->right);
	}
};

template<class T>
void BinarySearchTree<T>::inorder(node * leaf) {
	if (root == nullptr)
		std::cout << "Tree is empty" << std::endl;

	else if (leaf != nullptr) {
		preorder(leaf->left);
		std::cout << leaf->data << " ";
		preorder(leaf->right);
	}
};

template<class T>
void BinarySearchTree<T>::postorder(node * leaf) {
	if (root == nullptr)
		std::cout << "Tree is empty" << std::endl;

	else if (leaf != nullptr) {
		preorder(leaf->left);
		preorder(leaf->right);
		cout << leaf->data << " ";
	}
};

template<class T>
void BinarySearchTree<T>::copyTree(node *& sourceRoot, node *& thisRoot) {
	if (sourceRoot == nullptr)
		thisRoot == nullptr;
	else {
		thisRoot = new node;
		thisRoot->data = sourceRoot->data;
		copyTree(sourceRoot->left, thisRoot->left);
		copyTree(sourceRoot->right, thisRoot->right);
	}
};

template<class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::searchMax(node * leaf) {
	if (leaf == nullptr)
		return nullptr;
	else if (leaf->right == nullptr)
		return leaf;
	else
		return searchMax(leaf->right);
};

template<class T>
typename BinarySearchTree<T>::node* BinarySearchTree<T>::searchMin(node * leaf)
{
	if (leaf == nullptr)
		return nullptr;
	else if (leaf->left == nullptr)
		return leaf;
	else
		return searchMin(leaf->left);
};

#endif