#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "DoubleLinkedList.h"
#include <chrono>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace std::chrono;

class Favorite {
public:
	string regisID;
	string institution;
	Favorite* nextAdd;
	Favorite* prevAdd;
	DoubleLinkedList<Favorite> favDLL;

	Favorite(string regisID, string institution) {
		this->regisID = regisID;
		this->institution = institution;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	Favorite() {
		this->regisID = "";
		this->institution = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
	
	// insert newnode to linked list
	void insertToFavorite(string regisID,  string institution) {
		Favorite* newnode = new Favorite(regisID, institution);
		favDLL.insertEnd(newnode);

	}
	// insert the favorite linked list to file
	void insertToFile() {
		ofstream file("Favorite.csv");
		if (file.is_open()) {
			Favorite* current = favDLL.head;
			while (current != NULL) //means still not the end of the list
			{


				file << current->regisID << ',';
				file << current->institution << endl;

				current = current->nextAdd; //if you forgot this, will become a infinity loop
			}
			cout << "Updating Favorite.csv" << endl;
		}
	}

	//return the value of the input
	string getValueOf(string input) {
		if (input == "userId") {
			// TODO: check if this works
			return this->regisID;
		}
	}

	//display the favorite details
	void display() {
		cout << left<< setw(10) << this->regisID << '|';
		cout << setw(10) << this->institution << '|' << endl;
	}
	// callling the display function from the double linked list
	void displayAll() {
		favDLL.displayAll();
	}

	// displaying the header of favorite 
	void header() {
		cout << left << setw(10) << "User ID" << '|';
		cout << setw(10) << "Institution" << '|' << endl;
	}
};
