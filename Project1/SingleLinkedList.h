#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// SingleLinkedList can only be used by Univeristy, Users, and Admin Accounts
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
class SingleLinkedList
{
public:
	T* head;

	int getSize() {
		return size;
	}

	SingleLinkedList() {
		size = 0;
		head = NULL;
	};
	~SingleLinkedList() {
	};

	void insertFront(T * newNode) {
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->nextAdd = head;
			head = newNode;
		}

		size++;
	}

	void insertEnd(T * newNode) {
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			T* current = head;
			while (current->nextAdd != NULL)
			{
				current = current->nextAdd;
			}

			current->nextAdd = newNode;
		}

		size++;
	}

	T* getValueAt(int index) {
		T* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->nextAdd;
		}

		return current;
	}

	void setValueAt(T* newNode, int index) {
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

/// <summary>
/// Template Specilization for display list
/// </summary>
/// <typeparam name="T"></typeparam>

//	template <>
//	void displayList<University> {

//	}
private:
	int size;

};