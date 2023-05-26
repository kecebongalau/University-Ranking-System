#pragma once

#include <iostream>

// TODO: Implement search for "key", Look at HashMap

using namespace std;

template <class T>
T* linearSearch(T* head, string data, string input) {
	T* node = head;

	if (input == "rank") {
		while (node != NULL) {
			if (stoi(data) == node->rank) {

				return node;
			}
			node = node->nextAdd;
		}

	}
	else if (input == "institution") {
		while (node != NULL) {
			if (data == node->institution) {
				return node;
			}
			node = node->nextAdd;
		}
	}
	else if (input == "userId") {
		while (node != NULL) {
			if (data == node->ID) {
				return node;
			}
			node = node->nextAdd;
		}
	}
	//else if (input == "user"){
	//	while (node != NULL) {
	//		if (data == node->user) {
	//			return node;
	//		}
	//		node = node->nextAdd;
	//	}
	//}
	return nullptr;
}

