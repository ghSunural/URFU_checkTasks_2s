#pragma once


template<class T> class TSpecLinkedList {

private:

	struct Node {
		int key;
		T data;
		Node* prevNode;
		Node* nextNode;

	};

	Node* headNode_;
	Node* tailNode_;

public:

	//----------------------------------------------
	TSpecLinkedList<T>() {

	}
	//----------------------------------------------
	void addLast(T data) {

		Node* newNode = new Node;
		newNode->data = data;
		newNode->prevNode = NULL;
		newNode->nextNode = NULL;

		if (!headNode_) {
			headNode_ = newNode;
			headNode_->key = 0;
			tailNode_ = headNode_;
		}
		else {
			newNode->key = (tailNode_->key) + 1;
			newNode->prevNode = tailNode_;
			(newNode->prevNode)->nextNode = newNode;
			tailNode_ = newNode;
		}
	}
	//----------------------------------------------
	T  getFirst() {

		if (headNode_) {

			return headNode_->data;
		}
		else {
			throw TSpecException("Список пуст");
		}
	
	}
	//----------------------------------------------
	T getLast() {
		
		if (tailNode_) {

			return tailNode_->data;
		}
		else {
			throw TSpecException("Список пуст");
		}
		
	}

	//----------------------------------------------
	T  getByKey(int key) {
		Node* currentNode = new Node;
		currentNode = headNode_;
		while (currentNode) {

			if (currentNode->key == key) {

				return currentNode->data;
			}

			currentNode = currentNode->nextNode;
		}

		//		return NULL;			
	}

	//----------------------------------------------
	void recordDataByKey(T data, int key) {
		Node* currentNode = new Node();
		currentNode = headNode_;
		while (currentNode) {

			if (currentNode->key == key) {

				currentNode->data = data;
				return;
			}

			currentNode = currentNode->nextNode;
		}


	}

	//----------------------------------------------
	int  count() {
		if (tailNode_) {
			return tailNode_->key;
		}
		else {
			throw TSpecException("Список пуст");
		}

		//return 1;
	}

	//----------------------------------------------
	void displayList() {
		Node* currentNode = headNode_;
		while (currentNode) {
			cout << "Node " << currentNode->key << ":\n";
			cout << (currentNode->data) << "\n\n";
			currentNode = currentNode->nextNode;
		}

	}
	//----------------------------------------------
	~TSpecLinkedList() {

	}
};

