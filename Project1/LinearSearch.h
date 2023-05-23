#pragma once

#include <iostream>

using namespace std;

template <class T>
T* linearSearch(T* head, string data) {
	T* node = head;
	while (node != NULL) {
		if (isdigit(data) == true) {
			if (stoi(data) == node->rank) {
				return node;
			}
			node = node->nextAdd;
		}
		else if (isdigit(data) = false) {
			if (stoi(data) == node->rank) {
				return node;
			}
			node = node->nextAdd;
		}
	}
		return nullptr;
	}
