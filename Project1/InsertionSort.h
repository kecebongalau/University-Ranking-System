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
T* sortedInsert(T* sortedHead, T* current, string data) {
	//Sorting the head position first
	if (sortedHead == NULL || sortedHead->institution.compare(current->institution)<=0) {
		current->nextAdd = sortedHead;
		return current;
	}

	else {
		T* temp = sortedHead;
		while (temp->nextAdd != NULL && temp->nextAdd->institution.compare(current->institution) >0) {
			temp = temp->nextAdd;
		}
		current->nextAdd = temp->nextAdd;
		temp->nextAdd = current;
	}
	return sortedHead;
}
