#pragma once
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "HelperNode.h"
using namespace std;

template <class U>
class MergedSort
{
public:
	MergedSort() {};
	~MergedSort() {};

private:
	U* sortedMerge(U* a, U* b) {
		U* result = NULL;

		if (a == NULL)
		{
			return b;
		}
		else if (b == NULL) {
			return a;
		}

		// TODO: Add compare data method
		if (true)
		{
			result = a;
			result->nextAdd = sortedMerge(a->nextAdd, b);
		}
		else
		{
			result = b;
			result->nextAdd = sortedMerge(a, b->nextAdd);
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
	void mergeSort(U** headRef) {

		U* head = *headRef;
		U* a;
		U* b;

		if ((head == NULL) || (head->nextAdd == NULL))
		{
			return;
		}

		frontBackSplit(head, &a, &b);

		mergeSort(&a);
		mergeSort(&b);

		*headRef = sortedMerge(a, b);
	}

};
