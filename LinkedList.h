#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>

class LinkedList
{
private:

	struct ListNode
	{
		T value;
		struct ListNode* next;
	};

	ListNode* head;

public:

	LinkedList() {
		head = nullptr;
	}

	~LinkedList();


	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
};

template<class T>
inline LinkedList<T>::~LinkedList()
{
	ListNode* nodePtr;
	ListNode* nextNode;
	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		nodePtr = nextNode;
	}
}

template<class T>
inline void LinkedList<T>::appendNode(T newValue)
{
	ListNode* newNode;
	ListNode* nodePtr;

	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else {
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

template<class T>
inline void LinkedList<T>::insertNode(T newValue)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = newValue;

	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

template<class T>
inline void LinkedList<T>::deleteNode(T searchValue)
{
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;
	

	if (!head)
		return;
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) {
			previousNode->next = nodePtr->next;
		}
	}
}

template<class T>
inline void LinkedList<T>::displayList() const
{
	ListNode* nodePtr;
	nodePtr = head;
	cout << left << setw(12) << "Artist" << setw(12) << "CD Name" << setw(12) << "CD Length" << endl;
	while (nodePtr)
	{
		cout << left << setw(12) << nodePtr->value.getArtist();
		cout << setw(12) << nodePtr->value.getTitle();
		cout << setw(12) << nodePtr->value.getLength() << endl;
		//cout << setw(12) << nodePtr->value.disc.title;
		//cout << setw(12) << nodePtr->value.disc.lenght;
		
		nodePtr = nodePtr->next;
	}
}

#endif