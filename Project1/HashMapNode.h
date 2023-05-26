#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T >
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
	};
	~HashMapNode() {
	};
	void display() {
		cout << "Key: " << key << ", " << "Value: " << data << endl;
	}

private:

};