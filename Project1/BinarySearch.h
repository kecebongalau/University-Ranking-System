#include <iostream>
#pragma once

using namespace std;

template <class T>
T* middle(T* start, T* end) {
	// Check if the start pointer is NULL
	if (start == NULL) {
		return NULL;
	}
	T* slow = start;
	T* fast = start->nextAdd;
	
	// Use two pointers to find the middle element in a linked list
	// The fast pointer moves twice as fast as the slow pointer
	// When the fast pointer reaches the end or becomes NULL, the slow pointer will be at the middle

	while (fast != end )
	{
		fast = fast->nextAdd;
		// Move the slow pointer only if the fast pointer is not at the end or NULL
		if (fast != end && fast != NULL) {
			slow = slow->nextAdd;
			fast = fast->nextAdd;
		}
	}

	// Return the middle element
	return slow;
}

template <class T>
T* binarySearch(T* head, string data, string input) {
	T* start = head;
	T* end = NULL;

	// Perform binary search based on the input parameter
	if (input == "rank") {
		// Search by rank
		while (start != end) {
			T* midNode = middle(start, end);
			// Check if the rank of the middle node matches the search data
			if (stoi(data) == midNode->rank) {
				return midNode;
			}
			else if (midNode->rank > stoi(data)) {
				// If the rank of the middle node is greater, search in the first half
				end = midNode;
			}
			else {
				// If the rank of the middle node is smaller, search in the second half
				start = midNode->nextAdd;
			}
		}
	}
	else if (input == "institution") {
		// Search by institution name
		while (start != end) {
			T* midNode = middle(start, end);
			// Compare the institution name of the middle node with the search data
			if (data.compare(midNode->institution) == 0) {
				return midNode;
			}
			else if (midNode->institution.compare(data) > 0) {
				// If the institution name of the middle node is greater, search in the first half
				end = midNode;
			}
			else {
				// If the institution name of the middle node is smaller, search in the second half
				start = midNode->nextAdd;
			}
		}
	}
	// Return NULL if the search data is not found
	return NULL;
}