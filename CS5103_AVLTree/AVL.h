/**
CS5103 - Assignment 2 AVL Tree

@author DJ Yuhn
*/

#ifndef AVL_H
#define AVL_H

template <class T>
class AVL {
public:
	AVL() { root = nullptr; }
	~AVL();

	void insert(T val) { insert(val, root); }

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

	int getDiff(node* leaf);
	node* rotateLeft(node*& leaf);
	node* rotateRight(node*& leaf);
	node* rotateRightLeft(node*& leaf);
	node* rotateLeftRight(node*& leaf);
	void rebalance(node*& leaf);
};

#endif // !AVL_H