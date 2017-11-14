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

private:
	struct node {
		T data;
		node *left;
		node *right;
		int height;

		node(T data) {
			data = data;
			left = nullptr;
			right = nullptr;
			height = 0;
		}
	};

	node *root;
};

#endif // !AVL_H
