/******************************************************************************
* dygw3
* DJ Yuhn
* Assignment 1
******************************************************************************/

#ifndef QUEUELINKLIST_H
#define QUEUELINKLIST_H


template<class T>
class QueueLinkList {

public:
	QueueLinkList() { front = nullptr, back = nullptr; }
	~QueueLinkList() { deleteList(); }

	QueueLinkList(const QueueLinkList &obj);

	QueueLinkList& operator=(const QueueLinkList& rhs);

	// Get the front node in the queue's data value
	T getFront() const;

	// Add a new node to the end of the queue with a data value
	void push(T value);

	// Remove the node from the front of the queue
	T pop();

	// Check if the linked list is empty
	bool isEmpty() const { return front == nullptr; }

private:
	// Structure for nodes in the list to hold data
	struct Node {
		T data;
		Node *next = nullptr;
	};

	Node *front; // Pointer to front of the queue
	Node *back; // Pointer to back of queue

	// Delete entirety of the list
	void deleteList();

	// Deep copy the linked lists
	void deepCopy(const QueueLinkList& obj);

};

template<class T>
QueueLinkList<T>::QueueLinkList(const QueueLinkList &obj) {
	if (obj.front != nullptr)
		this->deepCopy(obj);
};

template<class T>
QueueLinkList<T>& QueueLinkList<T>::operator=(const QueueLinkList& rhs) {
	if (this != &rhs) {
		this->deleteList();
		this->deepCopy(rhs);
	}

	return *this;
};

template<class T>
T QueueLinkList<T>::getFront() const {
	// Check to see if queue is empty and throw exception if true.
	if (isEmpty())
		throw std::out_of_range("Queue is empty.");

	else
		return front->data;
};

template<class T>
void QueueLinkList<T>::push(T value) {
	// Create new node and insert the value into data
	Node *temp = new Node;
	temp->data = value;

	// If queue is empty point front and back to temp
	if (isEmpty()) {
		front = temp;
		back = temp;
	}

	// Have temp next pointer point to back. Assign back to temp.
	else {
		back->next = temp;
		back = temp;
	}
};

template<class T>
T QueueLinkList<T>::pop() {
	// Check to see if queue is empty and throw exception if true
	if (isEmpty())
		throw std::out_of_range("Queue is empty.");

	// If queue is not empty, delete the front node and return its value
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
}

template<class T>
void QueueLinkList<T>::deleteList() {
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
void QueueLinkList<T>::deepCopy(const QueueLinkList& obj) {
	Node* p1; // Pointer for this current node
	Node* o1; // Pointer for obj next node

	this->front = new Node;
	this->front->data = obj.front->data;

	p1 = front;
	o1 = obj.front->next;

	while (o1 != nullptr) {
		p1->next = new Node;
		p1->next->data = o1->data;
		p1 = p1->next;
		o1 = o1->next;
	}

	this->back = p1;
}
;


#endif
