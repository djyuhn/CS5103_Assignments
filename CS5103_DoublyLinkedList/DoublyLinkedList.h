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

	// Returns number of nodes in the list
	int getSize() const { return numNode; }

	// Add new nodes
	void pushFront(T value);
	void pushBack(T value);
	void insertAt(T value, int pos);

	// Remove nodes
	T deleteFront();
	T deleteBack();
	T deleteAt(int pos);

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
};

// Adds data to the head of the list
template<class T>
void DoublyLinkedList<T>::pushFront(T value){
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
};

// Adds data to the tail of the list
template<class T>
void DoublyLinkedList<T>::pushBack(T value) {
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

// Inserts data at the position. (Indexing begins at 0)
template<class T>
void DoublyLinkedList<T>::insertAt(T value, int pos) {
	// Insure valid number. Must be positive
	if (pos < 0)
		throw std::out_of_range("Negative integer entered.");

	// If index is 0, push to front
	else if (pos == 0)
		pushFront(value);

	else if (pos <= getSize()) {
		Node *before = front;
		Node *after = nullptr;
		Node *newNode = new Node;
		newNode->data = value;

		// Traverse list until node before desired position.
		for (int i = 0; i < (pos - 1); i++)
			before = before->next;

		if (before != nullptr) {
			after = before->next; // Hold the next node
			newNode->prev = before; // Assign newNode prev pointer to the before
			newNode->next = after; // Assign newNode next pointer to after
			before->next = newNode; // Assign before next pointer to the new node

			if (after != nullptr)
				after->prev = newNode; // Assign after previous pointer to the new node
			else
				back = newNode; // End of the list

			numNode++;
		}

		else {
			front = newNode;
			back = newNode;
		}
	}

	else
		throw std::out_of_range("Inserting outside range of the list.");
};

// Deletes data at front of list and returns the value
template<class T>
T DoublyLinkedList<T>::deleteFront() {
	// Check to see if list is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("List is empty.");

	// If list is not empty, delete the front node and return its value
	else {
		Node *temp = front;
		front = temp->next;

		// If front is now a nullptr, insure back is nullptr
		if (front == nullptr)
			back = nullptr;
		else
			front->prev = nullptr;

		T data = temp->data;

		delete temp;
		temp = nullptr;

		numNode--; // Decrement number of nodes

		return data;
	}
};

// Deletes data at back of list and returns the value
template<class T>
T DoublyLinkedList<T>::deleteBack() {
	// Check to see if list is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("List is empty.");

	// If list is not empty, delete the back node and return its value
	else {
		Node *temp = back;
		back = temp->prev;

		// If back is now a nullptr, insure front is nullptr
		if (back == nullptr)
			front = nullptr;
		else
			back->next = nullptr;

		T data = temp->data;

		delete temp;
		temp = nullptr;

		numNode--; // Decrement number of nodes

		return data;
	}
};

// Deletes data at the specified position and returns the value
template<class T>
T DoublyLinkedList<T>::deleteAt(int pos)
{
	// Check to see if list is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("List is empty.");

	// If position is 0 delete front
	else if (pos == 0)
		return deleteFront();

	// If list is not empty attempt search
	else {
		Node *search = front;
		Node *temp1 = nullptr;
		Node *temp2 = nullptr;

		// If position is less than or equal to total number of nodes, search
		if (pos <= getSize()) {
			for (int i = 0; i < pos; i++)
				search = search->next;

			T data = search->data;

			temp1 = search->prev;
			temp2 = search->next;

			if (temp1 != nullptr && temp2 != nullptr) {
				temp1->next = temp2;
				temp2->prev = temp1;
			}
			else if (temp1 != nullptr && temp2 == nullptr) {
				temp1->next = nullptr;
			}
			else if (temp1 == nullptr && temp2 != nullptr) {
				temp2->prev = nullptr;
			}

			delete search;
			numNode--;

			return data;

		}

		else
			throw std::out_of_range("Deleting outside range of the list");
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

