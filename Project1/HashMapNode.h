#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class HashMapNode
{
public:
	string key;
	T value;

	HashMapNode* prevAdd;
	HashMapNode* nextAdd;

	HashMapNode(string key, T data) {
		this->key = key;
		this->value = data;
		this->prevAdd = NULL;
		this->nextAdd = NULL;
	};
	~HashMapNode() {
	};

	void display() {
		cout << left << setw(10) << this->key << '|';
		cout << setw(10) << this->value << '|' << endl;
	}
	void header() {
		cout << left << setw(10) << "Institution" << '|';
		cout << setw(10) << "Total Favorite" << '|' << endl;
	}
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

private:

};