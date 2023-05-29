#pragma once

#include <iostream>

using namespace std;

// T is for University, RegisteredUser, or HashMapNode and U is for string or int
// Needs string getValueOf(string)

template <class T> class LinearSearch
{
public:
	LinearSearch() {
	};
	~LinearSearch() {
	};

	T* linearSearch_Node(T* head, string data, string input) {
		T* current = head;
		bool found = false;
		while (current != NULL)
		{
			string objectData = current->getValueOf(input);
			if (data == objectData)
			{
				found = true;
				return current;
				
			}
			current = current->nextAdd;
		}


		return nullptr;
	};

	void linearSearch(T* head, string data, string input) {
		T* current = head;
		bool found = false;;
		while (current != NULL)
		{
			string objectData = current->getValueOf(input);
			if (data == objectData)
			{
				current->display();
				found = true;
			}
			current = current->nextAdd;
		}
		if (!found) {
			cout << "UNIVERSITY NOT FOUND!!!" << endl << endl;
		}

	};

	void linearSearchScore(T* head, double lowerRange, double upperRange, string input) {
		T* current = head;
		bool found = false;
		while (current != NULL) {
			double objectData = current->getDoubleValueOf(input);
			if (objectData >= lowerRange && objectData <= upperRange) {
				current->display();
				found = true;
			}
			current = current->nextAdd;
		}
		if (!found) {
			cout << "UNIVERSITY NOT FOUND!!!" << endl << endl;
		}

	};

private:

};