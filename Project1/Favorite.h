#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "SingleLinkedList.h"
#include "InsertionSort.h"
#include "DoubleLinkedList.h"
#include "BinarySearch.h"
#include "NewMergeSort.h"
#include "HashMap.h"
#include "NewLinearSearch.h"
#include "LinearSearch.h"
#include <chrono>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace std::chrono;

class Favorite {
public:
	string regisID;
	string regisName;
	string institution;
	Favorite* nextAdd;
	Favorite* prevAdd;
	DoubleLinkedList<Favorite> favDLL;

	Favorite(string regisID, string regisName, string institution) {
		this->regisID = regisID;
		this->regisName = regisName;
		this->institution = institution;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	Favorite() {
		this->regisID = "";
		this->regisName = "";
		this->institution = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	void insertToFavorite(string regisID, string regisName, string institution) {
		Favorite* newnode = new Favorite(regisID, regisName, institution);
		favDLL.insertEnd(newnode);

	}

	void insertToFile() {
		ofstream file("Favorite.csv");
		if (file.is_open()) {
			Favorite* current = favDLL.head;
			while (current != NULL) //means still not the end of the list
			{
				cout << "User ID: " << current->regisID << endl;
				cout << "User Name: " << current->regisName << endl;
				cout << "Favorite Institution: " << current->institution << endl;

				file << current->regisID << ',';
				file << current->regisName << ',';
				file << current->institution << endl;

				current = current->nextAdd; //if you forgot this, will become a infinity loop
			}
			cout << "List is ended here! " << endl;
		}
	}
};