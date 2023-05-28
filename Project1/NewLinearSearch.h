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

	T* linearSearch(T* head, string data, string input) {
		T* current = head;
		while (current != NULL)
		{
			string objectData = current->getValueOf(input);
			cout << objectData << endl;
			if (data == objectData)
			{
				return current;
			}
			current = current->nextAdd;
		}
		return nullptr;
	}

	T* linearSearchScore(T* head, double lowerRange, double upperRange, string input) {
		T* current = head;
		while (current != NULL) {
			string objectData = current->getValueOf(input);
			if (stod(objectData) >= lowerRange && stod(objectData) <= upperRange) {
				return current;
			}
			current = current->nextAdd;
		}
		return nullptr;
	}

private:

};