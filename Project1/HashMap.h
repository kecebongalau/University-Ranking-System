#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "DoubleLinkedList.h"
#include "LinearSearch.h"
#include "HashMapNode.h"

template <class T>
class HashMap
{
public:
	DoubleLinkedList<HashMapNode<T>> HashMapdll;
	HashMap() {
	}
	~HashMap() {
	};
	void setValue(string key, T value) {
		HashMapNode<T>* node = linearSearch_Hash<HashMapNode<T>>(HashMapdll.head, key, "key");

		if (node == NULL) {
			HashMapNode<T>* newNode = new HashMapNode<T>(key, value);
			this->HashMapdll.insertEnd(newNode);
		}
		else
		{
			node->value = value;
		}
		return;
	}
	T getValue(string key) {
		HashMapNode<T>* node = linearSearch_Hash<HashMapNode<T>>(HashMapdll.head, key, "key");

		if (node == NULL)
		{
			return NULL;
		}
		else
		{
			return node->value;
		}

		return NULL;
	}
	void display() {
		this->HashMapdll.displayAll();
	}
	bool hasKey(string key) {
		HashMapNode<T>* node = linearSearch_Hash<HashMapNode<T>>(HashMapdll.head, key, "key");

		if (node == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};