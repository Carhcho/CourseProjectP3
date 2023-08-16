#ifndef LINKEDLISTDVD_H
#define LINKEDLISTDVD_H
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>

class LinkedListDVD
{
private:

	struct ListNode
	{
		T value;
		struct ListNode* next;
	};

	ListNode* head;

public:

	LinkedListDVD() {
		head = nullptr;
	}

	~LinkedListDVD();


	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
};

template<class T>
inline LinkedListDVD<T>::~LinkedListDVD()
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
inline void LinkedListDVD<T>::appendNode(T newValue)
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
inline void LinkedListDVD<T>::insertNode(T newValue)
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
inline void LinkedListDVD<T>::deleteNode(T searchValue)
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
inline void LinkedListDVD<T>::displayList() const
{
	ListNode* nodePtr;
	nodePtr = head;
	cout << left << setw(15) << "Movie Title" << setw(15) << "Movie Length" << setw(15) << "Year" << endl;
	while (nodePtr)
	{
		cout << left << setw(15) << nodePtr->value.getTitle();
		cout << setw(15) << nodePtr->value.getLength();
		cout << setw(15) << nodePtr->value.getYear() << endl;
		//cout << setw(12) << nodePtr->value.dvd.name;
		//cout << setw(12) << nodePtr->value.dvd.role;
		
		nodePtr = nodePtr->next;
	}
}

#endif