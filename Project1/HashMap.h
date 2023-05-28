#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "DoubleLinkedList.h"
#include "NewLinearSearch.h"
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
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

		//HashMapNode<T>* node = linearSearch<HashMapNode<T>>(HashMapdll.head, key, "key");

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
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

		//HashMapNode<T>* node = linearSearch<HashMapNode<T>>(HashMapdll.head, key, "key");

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
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

		// HashMapNode<T>* node = linearSearch<HashMapNode<T>>(HashMapdll.head, key, "key");

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