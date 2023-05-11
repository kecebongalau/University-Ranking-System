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

	SingleLinkedList();
	~SingleLinkedList();

	void insertFront(T * newNode) {
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
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
			while (current->next != NULL)
			{
				current = current->next;
			}

			current->next = newNode;
		}

		size++;
	}

	T* getValueAt(int index) {
		T* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		return current
	}

	void setValueAt(T* newNode, int index) {
		T* current = head;
		T* nextNode;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		nextNode = current->next;

		delete current->next;

		current->next = newNode;

		newNode->next = nextNode->next;
	}

private:
	int size;

};