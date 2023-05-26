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

	else if (input == "location"){
		while (node != NULL) {
			if (data == node->Location) {

				return node;
			}
			node = node->nextAdd;
		}
	}

	else if (input == "loc_code") {
		while (node != NULL) {
			if (data == node->LocationCode) {
				return node;
			}
			node = node->nextAdd;
		}
	}


	return nullptr;
}

