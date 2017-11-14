/**
CS5103 - Assignment 2 AVL Tree
AVL.h

@author DJ Yuhn
*/

#ifndef AVL_H
#define AVL_H

template <class T>
class AVL {
public:
	AVL() { root = nullptr; }
	~AVL() { destroyTree(); }

	void insert(T value) { insert(value, root); }

private:
	struct node {
		T data;
		node* left;
		node* right;
		int height;

		node(T data) {
			data = data;
			left = nullptr;
			right = nullptr;
			height = 0;
		}
		
		void updateHeight();
	};

	node* root;

	void insert(T data, node* leaf);
	void destroyTree(node*& leaf);

	void rebalance(node*& leaf);
	int getDiff(node* leaf);
	node* rotateLeft(node*& leaf);
	node* rotateRight(node*& leaf);
	node* rotateRightLeft(node*& leaf);
	node* rotateLeftRight(node*& leaf);
};

#endif // !AVL_H

/**
Updates the node height when called. Use when inserting or deleting nodes.
*/
template<class T>
inline void AVL<T>::node::updateHeight() {
	int leftH = 0;
	int rightH = 0;
	int max;

	if (left != nullptr)
		leftH = left->height;
	if (right != nullptr)
		rightH = right->height;

	if (leftH > rightH)
		max = leftH;
	else
		max = rightH;

	height = max + 1;
}

/**
Inserts the value into the AVL. Update the height of the node and rebalance.

@param value The value of the data in the node.
@param leaf Pointer of type node to a leaf.
*/
template<class T>
inline void AVL<T>::insert(T value, node * leaf) {
	if (leaf == nullptr) {
		leaf = new node(value);
		leaf->updateHeight();
	}

	else {
		if (value < leaf->data) {
			insert(value, leaf->left);
			leaf->updateHeight();
			rebalance(leaf);
		}
		else {
			insert(value, leaf->right);
			leaf->updateHeight();
			rebalance(leaf);
		}
	}
}


/**
Recursively deletes the nodes of the AVL tree

@param leaf Pointer of type node to a leaf.
*/
template<class T>
inline void AVL<T>::destroyTree(node *& leaf) {
	if (leaf != nullptr) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

/**
Get the difference of the node's left and right branch heights.
If it is positive, the left side is greater. Else the right side is greater.

@param leaf Pointer of type node to a leaf.
*/
template<class T>
inline int AVL<T>::getDiff(node * leaf) {
	int leftH = 0;
	int rightH = 0;

	if (left != nullptr)
		leftH = left->height;
	if (right != nullptr)
		rightH = right->height;

	return leftH - rightH;
}

/**
Rotates a branch to the left to balance and updates the height of the node.

@param leaf Pointer of type node to a leaf.
@return temp Pointer to the elevated right node that is now above the original leaf
*/
template<class T>
inline node * AVL<T>::rotateLeft(node *& leaf) {
	node* temp = leaf->right;
	leaf->right = temp->left;
	temp->left = leaf;

	leaf->updateHeight();

	return temp;
}