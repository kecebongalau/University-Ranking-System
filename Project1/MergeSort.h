#pragma once
#include <iostream>
#include <string>
#include "DoubleLinkedList.h"
#include "HelperNode.h"
using namespace std;

/// <summary>
/// T = {SingleLinkedList, DoubleLinkedList}
/// U = {University, RegisteredUser, AdminUser, HelperNode}
/// </summary>
/// <typeparam name="T"></typeparam>
/// <typeparam name="U"></typeparam>
template <class T, class U>
class MergeSort
{
public:
	MergeSort() {
	};
	~MergeSort() {
	};

	// add compare method to class

private:
	void cloneArray(T* listFrom, T** listTo, int const start, int const end) {
		U* currentFrom = listFrom->head;

		int i = 0;

		while (currentFrom != NULL)
		{
			if (i >= start && i < end)
			{
				(*listTo)->insertEnd(currentFrom);
			}
			currentFrom = currentFrom->nextAdd;
			i++;
		}
	}

	void splitArray(T* list, T** leftArray, T** rightArray, int const countArray1, int const countArray2, int const left, int const mid) {

		cloneArray(list, leftArray, left, countArray1 + left);

		cloneArray(list, rightArray, mid + 1, countArray2 + mid + 1);
	}

	void merge(T* list, int const left, int const mid, int const right) {
		auto const subArray1 = mid - left + 1;
		auto const subArray2 = right - mid;

		T leftArrayObject, rightArrayObject;
		T* leftArray = &leftArrayObject, * rightArray = &rightArrayObject;

		splitArray(list, &leftArray, &rightArray, subArray1, subArray2, left, mid);

		auto indexSubArray1 = 0,
			indexSubArray2 = 0,
			indexMergedArray = left;

		while (indexSubArray1 < subArray1 && indexSubArray2 < subArray2)
		{
			// CODE for comparison
			if (true)
			{
				list->setValueAt(leftArray->getValueAt(indexSubArray1), indexMergedArray);
				indexSubArray1++;
			}
			else
			{
				list->setValueAt(rightArray->getValueAt(indexSubArray2), indexMergedArray);
				indexSubArray2;
			}
			indexMergedArray++;
		}

		while (indexSubArray1 < subArray1)
		{
			list->setValueAt(leftArray->getValueAt(indexSubArray1), indexMergedArray);
			indexSubArray1++;
			indexMergedArray++;
		}

		while (indexSubArray2 < subArray2)
		{
			list->setValueAt(rightArray->getValueAt(indexSubArray2), indexMergedArray);
			indexSubArray2++;
			indexMergedArray++;
		}
	}

	void mergeSort(T* list, int const begin, int const end) {
		if (begin >= end)
		{
			return;
		}

		int mid = begin + (end - begin) / 2;

		mergeSort(list, begin, mid);

		mergeSort(list, mid + 1, end);

		merge(list, begin, mid, end);
	}

};
