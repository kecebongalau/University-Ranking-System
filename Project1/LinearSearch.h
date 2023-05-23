#pragma once

#include <iostream>

using namespace std;

template <class T>
T* linearSearch(T* head, string data) {
	T* node = head;
	while (node != NULL) {
			if (stoi(data) == node->rank || stoi(data) == node->institution) {
				return node;
			}
			node = node->nextAdd;
		}
	}
		return nullptr;
	}
