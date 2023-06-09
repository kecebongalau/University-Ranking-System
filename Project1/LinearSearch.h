#pragma once

#include <iostream>

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
	/*else if (input == "key") {
		while (node != NULL) {
			if (data == node->key) {
				return node;
			}
			node = node->nextAdd;
		}
	}
	else if (input == "userId"){
		while (node != NULL) {
			if (data == node->user) {
				return node;
			}
			node = node->nextAdd;
		}
	}*/

	return nullptr;
}

template <class T>
T* linearSearch_User(T* head, string data, string input) {
	T* node = head;

	if (input == "userID") {
		while (node != NULL) {
			if (data == node->getID()) {

				return node;
			}
			node = node->nextAdd;
		}
	}
	
}

template <class T>
T* linearSearch_Hash(T* head, string data, string input) {
	T* node = head;

	if (input == "key") {
	while (node != NULL) {
		if (data == node->key) {
			return node;
		}
		node = node->nextAdd;
	}
	}
}


