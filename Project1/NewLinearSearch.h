#pragma once

#include <iostream>

using namespace std;

// T is for University, RegisteredUser, or HashMapNode and U is for string or int

template <class T> class LinearSearch
{
public:
	LinearSearch() {
	};
	~LinearSearch() {
	};

	T* linearSearch_Node(T* head, string data, string input) {
		T* current = head;
		while (current != NULL)
		{
			string objectData = current->getValueOf(input);
			if (data == objectData)
			{
				return current;
			}
			current = current->nextAdd;
		}
		return nullptr;
	};

	void linearSearch(T* head, string data, string input) {
		T* current = head;
		while (current != NULL)
		{
			string objectData = current->getValueOf(input);
			if (data == objectData)
			{
				current->display();
			}
			current = current->nextAdd;
		}

	};

	void linearSearchScore(T* head, double lowerRange, double upperRange, string input) {
		T* current = head;
		while (current != NULL) {
			double objectData = current->getDoubleValueOf(input);
			if (objectData >= lowerRange && objectData <= upperRange) {
				current->display();
			}
			current = current->nextAdd;
		}
	};

private:

};