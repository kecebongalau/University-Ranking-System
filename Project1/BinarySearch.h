#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

using namespace std;

template <class T>

T* binarySearch(T* head, string targetUniv){
    T *start = head;
    T *end = nullptr;

    while(start != end){
        T *midNode = start;
        int cnt = 0;

        while(midNode != end && midNode != end){
            midNode = midNode->nextAdd;
        }

        if(mid == nullptr){
            break;
        }

        for (int i = 0; i < count / 2; i++){
            mid = midNode->prevAdd;
        }

        if(mid->Institution == targetUniv){
            start = midNode->nextAdd;
        }

        else{
            end = midNode;
        }
    }
    return nullprt;
}