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
	~AVL() { destroyTree(root); }

	void insert(T value) { insert(value, root); }
	void inorder() { inorder(root); }
	int getTreeHeight() const { return root->height - 1; }

private:
	struct node {
		T data;
		node* left;
		node* right;
		int height;

		node(T val) {
			data = val;
			left = nullptr;
			right = nullptr;
			height = 0;
		}
		
		void updateHeight();
	};

	node* root;

	void insert(T data, node*& leaf);
	void destroyTree(node*& leaf);

	void rebalance(node*& leaf);
	int getDiff(node*& leaf);
	node* rotateLeft(node*& leaf);
	node* rotateRight(node*& leaf);
	node* rotateRightLeft(node*& leaf);
	node* rotateLeftRight(node*& leaf);

	void inorder(node * leaf);
};

/**
Updates the node height when called. Use when inserting or deleting nodes.
*/
template<class T>
void AVL<T>::node::updateHeight() {
	int leftH = 0;
	int rightH = 0;
	int max = 0;

	if (left != nullptr)
		leftH = left->height;
	if (right != nullptr)
		rightH = right->height;

	if (leftH > rightH)
		max = leftH;
	else
		max = rightH;

	height = max + 1;
};

/**
Inserts the value into the AVL. Update the height of the node and rebalance.

@param value The value of the data in the node.
@param leaf Pointer of type node to a leaf.
*/
template<class T>
void AVL<T>::insert(T value, node *& leaf) {
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

	leaf->updateHeight();
};


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
};

/**
Checks each node's left and right branches. Determines if they are unbalanced.
If the branches are unbalanced, they are rotated upwards until the heights are equal.

@paramm leaf Pointer of type node to a leaf.
*/
template<class T>
inline void AVL<T>::rebalance(node *& leaf) {
	int heightDiff = getDiff(leaf);
	if (heightDiff > 1) {
		if (getDiff(leaf->left) > 0)
			leaf = rotateRight(leaf);
		else
			leaf = rotateLeftRight(leaf);
	}
	else if (heightDiff < -1) {
		if (getDiff(leaf->right) < 0)
			leaf = rotateLeft(leaf);
		else
			leaf = rotateRightLeft(leaf);
	}
}

/**
Get the difference of the node's left and right branch heights.
If it is positive, the left side is greater. Else the right side is greater.

@param leaf Pointer of type node to a leaf.
*/
template<class T>
inline int AVL<T>::getDiff(node *& leaf) {
	int leftH = 0;
	int rightH = 0;

	if (leaf->left != nullptr)
		leftH = leaf->left->height;
	if (leaf->right != nullptr)
		rightH = leaf->right->height;

	return leftH - rightH;
};

/**
Rotates a branch to the left to balance and updates the height of the node.

@param leaf Pointer of type node to a leaf.
@return temp Pointer to the elevated right node that is now above the original leaf
*/
template<class T>
typename AVL<T>:: node * AVL<T>::rotateLeft(node *& leaf) {
	node* temp = leaf->right;
	leaf->right = temp->left;
	temp->left = leaf;

	leaf->updateHeight();

	std::cout << "\n\tThe node containing " << temp->data
		<< " and its right branch were rotated left. \n\tThe node containing "
		<< leaf->data << " and its left branch are now " << temp->data
		<< " node's left branch.";

	return temp;
};

/**
Rotates a branch to the right to balance and updates the height of the node.

@param leaf Pointer of type node to a leaf.
@return temp Pointer to the elevated left node that is now above the original leaf
*/
template<class T>
typename AVL<T>:: node * AVL<T>::rotateRight(node *& leaf) {
	node* temp = leaf->left;
	leaf->left = temp->right;
	temp->right = leaf;

	std::cout << "\n\tThe node containing " << temp->data
		<< " and its left branch were rotated right. \n\tThe node containing "
		<< leaf->data << " and its right branch are now " << temp->data
		<< " node's right branch.";

	leaf->updateHeight();

	return temp;
};

/**
Rotates a branch to the right and then the left.

@param leaf Pointer of type node to a leaf.
@return Pointer to the elevated leaf's right node's left branch.
*/
template<class T>
typename AVL<T>:: node * AVL<T>::rotateRightLeft(node *& leaf) {
	node* temp = leaf->right;
	leaf->right = rotateRight(temp);

	return rotateLeft(leaf);
};

/**
Rotates a branch to the left and then the right.

@param leaf Pointer of type node to a leaf.
@return Pointer to the elevated leaf's left node's right branch.
*/
template<class T>
typename AVL<T>:: node * AVL<T>::rotateLeftRight(node *& leaf) {
	node* temp = leaf->left;
	leaf->left = rotateLeft(temp);

	return rotateRight(leaf);
}

/**
Traverses the tree inorder, outputting contents of each node.

@param leaf Pointer of type node to a leaf.
*/
template<class T>
void AVL<T>::inorder(node * leaf) {
	if (root == nullptr)
		std::cout << "Tree is empty" << std::endl;

	else if (leaf != nullptr) {
		inorder(leaf->left);
		std::cout << leaf->data << " ";
		inorder(leaf->right);
	}
};

#endif