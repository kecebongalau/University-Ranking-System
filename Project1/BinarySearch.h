#include <iostream>
#pragma once

using namespace std;

//template <class T>
//T* middle(T* start, T* last)
//{
//    if (start == NULL)
//        return NULL;
//
//    T* slow = start;
//    T* fast = start->nextAdd;
//
//    while (fast != last)
//    {
//        fast = fast->nextAdd;
//        if (fast != last)
//        {
//            slow = slow->nextAdd;
//            fast = fast->nextAdd;
//        }
//    }
//
//    return slow;
//}
//
//// Function for implementing the Binary
//// Search on linked list
//template <class T>
//T* binarySearch(T* head, string value)
//{
//    T* start = head;
//    T* last = NULL;
//
//    do
//    {
//        // Find middle
//        T* mid = middle(start, last);
//
//        // If middle is empty
//        if (mid == NULL)
//            return NULL;
//
//        // If value is present at middle
//        if (mid->rank.compare(value) == 0) {
//            cout << mid->institution << endl;
//            return mid;
//        }
//            
//
//        // If value is more than mid
//        else if (mid->institution.compare(value) < 0)
//            start = mid->nextAdd;
//
//        // If the value is less than mid.
//        else
//            last = mid;
//
//    } while (last == NULL ||
//        last != start);
//
//    // value not present
//    return NULL;
//}
//T* midNode(T* left, T* right) {
//    T* slow = left;
//    T* fast = left;
//    while (fast != right && fast->nextAdd != right) {
//        slow = slow->nextAdd;
//        fast = fast->nextAdd->nextAdd;
//    }
//    return slow;
//}
//
//template <class T>
//T* binarySearch(T* head, string targetUniv) {
//    T* left = head;
//    T* right = NULL;
//    T* middle = head;
//    while (right == NULL || left != right->nextAdd) {
//        T* middle = midNode(left, right);
//        if (middle == NULL) {
//            return NULL;
//        }
//        else if (middle->institution.compare(targetUniv) == 0) {
//            return middle;
//        }
//        else if (middle->institution.compare(targetUniv) < 0) {
//            left = middle->nextAdd;
//        }
//        else {
//            right = middle->prevAdd;
//        }
//        
//        return middle;
//    }
//    return  NULL;
//}

//template <class T>
//T* binarySearch(T* head, string targetUniv){
//    T *start = head;
//    T *end = nullptr;
//    cout << head->institution << endl;
//    cout << targetUniv << endl;
//
//    while(start != end){
//        T *midNode = start;
//        int count = 0;
//
//        while (midNode != end && midNode->nextAdd != end) {
//            midNode = midNode->nextAdd;
//            count++;
//        }
//
//        if(midNode == nullptr){
//            break;
//        }
//
//        for (int i = 0; i < count / 2; i++){
//            midNode = midNode->prevAdd;
//        }
//
//        if (midNode->institution.compare(targetUniv) == 0) {
//            return midNode;
//        }
//        else if(midNode->institution.compare(targetUniv) < 0){
//            start = midNode->nextAdd;
//        }
//
//        else{
//            end = midNode;
//            
//        }
//    }
//    return nullptr;
//}
//template <class T>
//T* BinarySearch(T* head, T* tail,string data)
//{
//
//    T* left = head;
//    T* right = tail;
//
//
//    while (right != left->nextAdd)
//    {
//        int mid = 0;
//        T* midNode = left;
//
//        // calculate the middle index and node
//        while (mid < (right - left) / 2)
//        {
//            midNode = midNode->nextAdd;
//            ++mid;
//        }
//        // check if the middle node matches the target institution
//        if (midNode->rank.compare(data) == 0)
//        {
//            cout << "University found!" << endl;
//            // do something with the node
//            return midNode;
//            //int rank = stoi(current->rank);
//
//            
//        }
//
//        // if the middle node is less than the target, search the right half
//        else if (midNode->rank.compare(data) < 0)
//        {
//            left = midNode->nextAdd;
//        }
//        // if the middle node is greater than the target, search the left half
//        else
//        {
//            right = midNode->prevAdd;
//        }
//    }
//
//    // check if the last node matches the target rank
//    if (left->rank == data)
//    {
//        cout << "University found!" << endl;
//    }
//    else
//    {
//        cout << "University not found." << endl;
//    }
//    return NULL;
//}

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
		if (stoi(data) == midNode->rank){
			return midNode;
		}

		else if (midNode->rank > stoi(data)) {
			end = midNode->prevAdd;
		}

		else {
			start = midNode->nextAdd;
		}
	}
	return NULL;

	
}