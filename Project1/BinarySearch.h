#include <iostream>
#pragma once

using namespace std;



template <class T>
T* middle(T* start, T* end) {
	if (start == NULL) {
		return NULL;
	}
	T* slow = start;
	T* fast = start->nextAdd;
	
	while (fast != end && fast != NULL)
	{
		fast = fast->nextAdd;
		if (fast != end && fast != NULL) {
			slow = slow->nextAdd;
			fast = fast->nextAdd;
		}
	}
	
	return slow;
}

template <class T>
T* binarySearch(T* head, string data) {
	T* start = head;
	T* end = NULL;
	//finding middle node
	while (start != end) {
		T* midNode = middle(start, end);
		if (stoi(data) == midNode->rank || data == midNode->institution || data == midNode->Location){
			return midNode;
		}


		else if (midNode->rank > stoi(data) || midNode->institution > data || midNode->Location > data) {
			end = midNode->prevAdd;
		}

		else {
			start = midNode->nextAdd;
		}
	}
	return NULL;

	
}