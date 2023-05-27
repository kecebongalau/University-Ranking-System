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
		cout << "Key: " << key << ", " << "Value: " << value << endl;
	}
	bool compareAttributes(HashMapNode<T>* otherNode, string attribute) {
		if (attribute == "value")
		{
			return (value >= otherNode->value);
		}
	}

private:

};