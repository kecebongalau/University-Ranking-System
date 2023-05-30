#pragma once
#include <iostream>
#include <string>
using namespace std;

// Template U can be linked list. Any class with compareAttributes and nextAdd

template <class U>
class MergedSort
{
public:
	MergedSort() {};
	~MergedSort() {};
	// accessable funcgtion to init merge sort
	void mergeSort(U** headRef, string attribute, bool asc = true) {

		U* head = *headRef;
		U* a;
		U* b;

		if ((head == NULL) || (head->nextAdd == NULL))
		{
			return;
		}

		frontBackSplit(head, &a, &b);

		mergeSort(&a, attribute, asc);
		mergeSort(&b, attribute, asc);

		if (asc)
		{
			*headRef = sortedMerge(a, b, attribute);
		}
		else
		{
			*headRef = sortedMergeDesc(a, b, attribute);
		}
	}

private:
	// function to merge and compare the linked list
	U* sortedMerge(U* a, U* b, string attribute) {
		U* result = NULL;

		if (a == NULL)
		{
			return b;
		}
		else if (b == NULL) {
			return a;
		}

		if (a->compareAttributes(b, attribute))
		{
			result = a;
			result->nextAdd = sortedMerge(a->nextAdd, b, attribute);
		}
		else
		{
			result = b;
			result->nextAdd = sortedMerge(a, b->nextAdd, attribute);
		}

		return result;
	}
	// function to merge and compare the linked list but descending
	U* sortedMergeDesc(U* a, U* b, string attribute) {
		U* result = NULL;

		if (a == NULL)
		{
			return b;
		}
		else if (b == NULL) {
			return a;
		}

		if (!a->compareAttributes(b, attribute))
		{
			result = a;
			result->nextAdd = sortedMergeDesc(a->nextAdd, b, attribute);
		}
		else
		{
			result = b;
			result->nextAdd = sortedMergeDesc(a, b->nextAdd, attribute);
		}

		return result;
	}
	// function to split the linked list
	void frontBackSplit(U* source, U** frontRef, U** backRef) {
		U* fast;
		U* slow;
		slow = source;
		fast = source->nextAdd;

		while (fast != NULL)
		{
			fast = fast->nextAdd;
			if (fast != NULL)
			{
				slow = slow->nextAdd;
				fast = fast->nextAdd;
			}
		}

		*frontRef = source;
		*backRef = slow->nextAdd;
		slow->nextAdd = NULL;
	}
};
