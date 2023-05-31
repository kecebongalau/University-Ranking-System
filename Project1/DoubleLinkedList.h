#pragma once
#include <iostream>
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

	void insertFront(T* newNode) { // O(1)  inserting to front of the list
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

	void insertEnd(T* newNode) { // O(1)  inserting to end of the list
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

	void deleteNode(T* node) { // deleting the selected node
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
	void setTail() { // setting the new tail and prev address after the linked list is sorted
		T* current = head;
		T* temp = NULL;
		while (current->nextAdd != NULL) {
			tail = current->nextAdd;
			current->prevAdd = temp;
			temp = current;
			current = current->nextAdd;
		}
	}
	void displayAll() { // O(n) displaying all details of the linked list
		T* current = head;
		int counter = 0;
		int opt,x, temp;
		current->header(); // calling the header of the template class attributes
		while (current != NULL)
		{
			current->display(); // calling the details of the template class attributes
			cout << endl;
			current = current->nextAdd;
			counter++;
			if (counter % 10 == 0) {
				cout << "Do you want to check on more?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. Go to previous page" << endl;
				cout << "3. No Stop Here" << endl;
				cin >> opt;
				switch (opt)
				{
				case 1:
					break;
				case 2:
					cout << counter << endl;
					if (counter < 10) { // automatically break if there's no previous page
						break;
					}
					else if (counter % 10 == 0) {
						x = 20;
						temp = 0;
					}
					else {
						x = counter % 10 + 10;
						temp = 0;
					}
					while (x > temp) { // counter to go to the previous page
						if (current->prevAdd != NULL) {
							current = current->prevAdd;
							x--;
							counter--;
						}
						else {
							return;
						}
					}
					break;
				default:
					return;
					break;
				}
			}
		}

		cout << "List is ended here!" << endl;
	}
private:
	int size;

};
