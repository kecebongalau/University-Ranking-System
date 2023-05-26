#pragma once

#include <iostream>

using namespace std;

template <class T>
T* linearSearch(T* head, string data, int opt) {
	T* node = head;

	if (opt == 1){
		while (node != NULL) {
			if (stoi(data) == node->rank) {

				return node;
			}
			node = node->nextAdd;
		}

	}
	else if (opt == 2){
		while (node != NULL) {
			if (data == node->institution) {
				return node;
			}
			node = node->nextAdd;
		}
	}
	//else if (opt == "3"){
	//	while (node != NULL) {
	//		if (data == node->user) {
	//			return node;
	//		}
	//		node = node->nextAdd;
	//	}
	//}

	return nullptr;
}

