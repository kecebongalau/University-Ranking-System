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
T* binarySearch(T* head, string data, string input) {
	T* start = head;
	T* end = NULL;
	//finding middle node
	if (input == "rank") {
		while (start != end) {
			T* midNode = middle(start, end);
			if (stoi(data) == midNode->rank/* || data == midNode->institution || data == midNode->Location*/) {
				return midNode;
			}


			else if (midNode->rank > stoi(data)/* || midNode->institution > data || midNode->Location > data*/) {
				end = midNode->prevAdd;
			}

			else {
				start = midNode->nextAdd;
			}
		}
	}
	else if (input == "institution") {
		while (start != end) {
			T* midNode = middle(start, end);
			if (data.compare(midNode->institution) == 0/* || data == midNode->institution || data == midNode->Location*/) {
				return midNode;
			}


			else if (midNode->institution.compare(data) > 0/* || midNode->institution > data || midNode->Location > data*/) {
				end = midNode->prevAdd;
			}

			else {
				start = midNode->nextAdd;
			}
		}
	}
	//while (start != end)
	//{
	//	T* midNode = middle(start, end);
	//	string objectData = midNode->getValueOf(input);
	//	/*cout << objectData << endl;*/
	//	if (data == objectData)
	//	{
	//		return midNode;
	//	}
	//	else if (objectData > data) {
	//		end = midNode->prevAdd;
	//	}

	//	else {
	//		start = midNode->nextAdd;
	//	}
	//}
	return NULL;

	
}