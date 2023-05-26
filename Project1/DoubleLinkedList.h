#pragma once
#include <iostream>
#include "HelperNode.h"
using namespace std;

// T needs nextAdd, prevAdd, and display()

template <class T>
class DoubleLinkedList
{
public:
	T* head;
	T* tail;

	int getSize() {
		return size;
	}

	DoubleLinkedList() {
		size = 0;
		head = NULL;
		tail = NULL;
	};
	~DoubleLinkedList() {
	};

	void insertFront(T* newNode) { // O(1)
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->nextAdd = head;
			head->prevAdd = newNode;
			head = newNode;
		}

		size++;
	}

	void insertEnd(T* newNode) { // O(1)
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->nextAdd = newNode;
			newNode->prevAdd = tail;
			tail = newNode;
		}

		size++;
	}

	void deleteNode(T* node) {
		if (head == NULL)
		{
			return;
		}
		else {
			if (node->nextAdd == NULL && node->prevAdd == NULL) {
				tail = NULL;
				head = NULL;
				delete node;
			}
			else if (node->nextAdd == NULL)
			{
				T* newTail = node->prevAdd;
				newTail->nextAdd = NULL;
				tail = newTail;
				delete node;
			}
			else if (node->prevAdd == NULL) {
				T* newHead = node->nextAdd;
				newHead->prevAdd = NULL;
				head = newHead;
				delete node;
			}
		}
	};

	T* getValueAt(int index) { // O(n)
		T* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->nextAdd;
		}

		return current;
	}

	void setValueAt(T* newNode, int index) { // O(n)
		T* current = head;
		T* nextNode;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->nextAdd;
		}

		nextNode = current->nextAdd;

		delete current->nextAdd;

		current->nextAdd = newNode;

		newNode->nextAdd = nextNode->nextAdd;
	}

	void displayAll() { // O(n)
		T* current = head;

		while (current != NULL)
		{
			current->display();
			cout << endl;
			current = current->nextAdd;
		}

		cout << "List is ended here!" << endl;
	}
private:
	int size;

};