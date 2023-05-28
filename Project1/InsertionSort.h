#pragma once

#include <iostream>
using namespace std;
//Template for insertion sort

template <class T>
T* insertionSort(T* head, string data) {
	T* current = head;
	T* sortedHead = NULL;

	//traversing the linked list
	while (current != NULL) {
		T* next = current->nextAdd;
		sortedHead = sortedInsert(sortedHead, current, data);
		current = next; //update the current node

	}
	return sortedHead;
}
template <class T>
T* insertionSort_user(T* head, string data) {
	T* current = head;
	T* sortedHead = NULL;

	//traversing the linked list
	while (current != NULL) {
		T* next = current->nextAdd;
		sortedHead = sortedInsert_user(sortedHead, current, data);
		current = next; //update the current node

	}
	return sortedHead;
}
template <class T>
T* sortedInsert(T* sortedHead, T* current, string data) {
	if (data == "institution") {
		if (sortedHead == NULL || sortedHead->institution.compare(current->institution) >= 0) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->institution.compare(current->institution) < 0) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	else if (data == "rank") {
		if (sortedHead == NULL || sortedHead->rank <= current->rank) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->rank > current->rank) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	else if (data == "ArScore") {
		if (sortedHead == NULL || sortedHead->ArScore <= current->ArScore) {
			current->nextAdd = sortedHead;
			return current;
		}

		else  {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->ArScore > current->ArScore) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	else if (data == "FsrScore") {
		if (sortedHead == NULL || sortedHead->FsrScore <=  current->FsrScore) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->FsrScore > current->FsrScore) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}

	else if (data == "ErScore") {
		if (sortedHead == NULL || sortedHead->ErScore <= current->ErScore) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->ErScore > current->ErScore) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	return NULL;
	
}


template <class T>
T* sortedInsert_user(T* sortedHead, T* current, string data) {
	if (data == "date") {
		if (sortedHead == NULL || sortedHead->lastActiveDate.compare(current->lastActiveDate) <= 0) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->lastActiveDate.compare(current->lastActiveDate) > 0) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	

}