#pragma once

#include <iostream>
using namespace std;
//Template for insertion sort

template <class T>
T* insertionSort(T* head, string data, bool asc) {
	T* current = head;
	T* sortedHead = NULL;

	//traversing the linked list
	while (current != NULL) {
		T* next = current->nextAdd;
		sortedHead = sortedInsert(sortedHead, current, data, asc);
		current = next; //update the current node

	}
	return sortedHead;
}

// inserting the element into the sorted head
template <class T>
T* sortedInsert(T* sortedHead, T* current, string data, bool asc) {
	if (asc) { //ascending sort
		if (sortedHead == NULL || !sortedHead->compareAttributes(current, data)) { //the current data becomes the new head
			current->nextAdd = sortedHead;
			return current;
		}

		else { // the current data is inserted in between the sorted head based on the order
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && temp->nextAdd->compareAttributes(current, data)) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}
	else if (!asc) { //descending sort
		if (sortedHead == NULL || sortedHead->compareAttributes(current, data)) {
			current->nextAdd = sortedHead;
			return current;
		}

		else {
			T* temp = sortedHead;
			while (temp->nextAdd != NULL && !temp->nextAdd->compareAttributes(current, data)) {
				temp = temp->nextAdd;
			}
			current->nextAdd = temp->nextAdd;
			temp->nextAdd = current;
		}
		return sortedHead;
	}

	

}