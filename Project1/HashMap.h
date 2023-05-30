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
	// hash map based on a linked list
	DoubleLinkedList<HashMapNode<T>> HashMapdll;
	HashMap() {
	}
	~HashMap() {
	};
	// Set the value of a hash map node based on the key to value
	void setValue(string key, T value) {
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

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
	// Get the value of a hash map node based on the key
	T getValue(string key) {
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

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
	// Display the content of the linked list
	void display() {
		this->HashMapdll.displayAll();
	}
	// Check if the hash map has the key
	bool hasKey(string key) {
		LinearSearch<HashMapNode<T>> linearSearchClass;
		HashMapNode<T>* node = linearSearchClass.linearSearch_Node(HashMapdll.head, key, "key");

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