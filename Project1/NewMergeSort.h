#pragma once
#include <iostream>
#include <string>
#include "HelperNode.h"
using namespace std;

template <class U>
class MergedSort
{
public:
	MergedSort() {};
	~MergedSort() {};
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
