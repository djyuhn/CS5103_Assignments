/******************************************************************************
* dygw3
* DJ Yuhn
* Assignment 1
******************************************************************************/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


template<class T>
class DoublyLinkedList {

public:
	DoublyLinkedList() { front = nullptr, back = nullptr, numNode = 0; }
	~DoublyLinkedList() { deleteList(); }

	DoublyLinkedList(const DoublyLinkedList &obj);

	DoublyLinkedList& operator=(const DoublyLinkedList& rhs);

	void getNodeNum() const { return numNode; }

	// Add new nodes
	void insertTail(T value);
	void insertHead(T value);
	void insertAt(T value, int pos);

	// Remove the node from the front of the list
	T pop();

	// Check if the linked list is empty
	bool isEmpty() const { return front == nullptr; }

private:
	// Structure for nodes in the list to hold data
	struct Node {
		T data;
		
		Node *next = nullptr;
		Node *prev = nullptr;
	};

	Node *front; // Pointer to front of the list
	Node *back; // Pointer to back of list
	int numNode;
	
	// Delete entirety of the list
	void deleteList();

	// Deep copy the linked lists
	void deepCopy(const DoublyLinkedList& obj);

};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &obj) {
	if (obj.front != nullptr)
		this->deepCopy(obj);
};

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& rhs) {
	if (this != &rhs) {
		this->deleteList();
		this->deepCopy(rhs);
	}

	return *this;
}

template<class T>
void DoublyLinkedList<T>::insertTail(T value) {
	// Create new node and insert the value into data
	Node *temp = new Node;
	temp->data = value;

	// If list is empty point front and back to temp
	if (isEmpty()) {
		front = temp;
		back = temp;
	}

	// Have back next pointer point to temp, temp prev point to back.
	else {
		back->next = temp;
		temp->prev = back;
		back = temp;
	}

	// Increment number of nodes
	numNode++;
};

template<class T>
void DoublyLinkedList<T>::insertHead(T value){
	// Create new node and insert the value into data
	Node *temp = new Node;
	temp->data = value;

	// If list is empty point front and back to temp
	if (isEmpty()) {
		front = temp;
		back = temp;
	}

	// Have temp next pointer point to front, front prev point to temp
	else {
		temp->next = front;
		front->prev = temp;
		front = temp;
	}

	// Increment number of nodes
	numNode++;
}

template<class T>
void DoublyLinkedList<T>::insertAt(T value, int pos) {
	Node *temp = front;
	Node *temp2 = nullptr;
	Node *newNode = new Node;
	newNode->data = value;

	if (pos <= getNodeNum()) {
		// Traverse list until node before desired position.
		for (int i = 0; i < (pos - 1); i++) {
			temp = temp->next
		}

		temp2 = temp->next; // Hold the next node
		newNode->prev = temp; // Assign newNode prev pointer to temp
		newNode->next = temp2; // Assign newNode next pointer to temp2
		temp->next = newNode; // Assign temp next pointer to the new node
		temp2->prev = newNode; // Assign temp2 prev pointer to the new node

	}

	else
		throw std::out_of_range("Inserting outside range of the list.");

};

template<class T>
T DoublyLinkedList<T>::pop() {
	// Check to see if list is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("List is empty.");

	// If list is not empty, delete the front node and return its value
	else {
		Node *temp = front;
		front = temp->next;

		T data = temp->data;

		delete temp;
		temp = nullptr;

		// If front is now a nullptr, insure back is nullptr
		if (front == nullptr)
			back = nullptr;

		return data;
	}
};

template<class T>
void DoublyLinkedList<T>::deleteList() {
	Node *temp = nullptr;

	// Check if list has any nodes and continue to delete until empty
	while (!isEmpty()) {
		temp = front;
		front = temp->next;

		delete temp;
	}

	back = nullptr;
	temp = nullptr;
}

template<class T>
void DoublyLinkedList<T>::deepCopy(const DoublyLinkedList& obj) {
	Node* p1; // Pointer for this current node
	Node* o1; // Pointer for obj next node

	this->front = new Node;
	this->front->data = obj.front->data;

	p1 = front;
	o1 = obj.front->next;

	while (o1 != nullptr) {
		p1->next = new Node;
		p1->next->data = o1->data;

		this->back = p1;
		p1 = p1->next;
		o1 = o1->next;
	}
};


#endif

