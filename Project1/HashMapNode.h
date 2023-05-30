#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class HashMapNode
{
public:
	// Key value pair
	string key;
	T value;

	// needed for double linked list
	HashMapNode* prevAdd;
	HashMapNode* nextAdd;

	// Init function
	HashMapNode(string key, T data) {
		this->key = key;
		this->value = data;
		this->prevAdd = NULL;
		this->nextAdd = NULL;
	};
	~HashMapNode() {
	};

	// Display content of this node
	void display() {
		cout << left << setw(80) << this->key << '|';
		cout << setw(20) << this->value << '|' << endl;
	}
	// Table display
	void header() {
		cout << left << setw(80) << "Institution" << '|';
		cout << setw(20) << "Total Favorite" << '|' << endl;
	}
	// Needed for sort algorithm, compare attributes
	bool compareAttributes(HashMapNode<T>* otherNode, string attribute) {
		if (attribute == "value")
		{
			return (value >= otherNode->value);
		}
	}
	string getValueOf(string input) {
		if (input == "key") {
			return this->key;
		}
	}
};