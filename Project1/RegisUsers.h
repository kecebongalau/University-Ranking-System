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
#include "Favorite.h"
#include "Feedback.h"
#include "University.h"
#include "Users.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace std::chrono;

class RegisteredUsers : Users {
public:
	DoubleLinkedList<RegisteredUsers> regisDLL;
	string lastActiveDate;
	RegisteredUsers* head, * tail;
	RegisteredUsers* nextAdd;
	RegisteredUsers* prevAdd;
	RegisteredUsers() {
		this->ID = "";
		this->name = "";
		this->password = "";
		this->lastActiveDate = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
	RegisteredUsers(string ID, string name, string password, string lastActiveDate) {
		this->ID = ID;
		this->name = name;
		this->password = password;
		this->lastActiveDate = lastActiveDate;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
	void menu(RegisteredUsers* users, University* univ, Feedback* feed, Favorite* fav);
	void user_register(RegisteredUsers* regis);
	RegisteredUsers* login(string ID, string password);
	string generateID();
	void insertToList(string ID, string name, string password, string lastactivedate);
	void writeData(RegisteredUsers* users);
	void deleteFromList(string ID, int position);
	void search(string ID);
	bool compareAttributes(RegisteredUsers* otherRegisteredUser, string attribute);
	void feedback(string ID, string name, University* univ, Feedback* feed);
	void favorite(string ID, string name, University* univ, Favorite* fav);
	void insertToFile();
	string getValueOf(string input);
	void regis_insertionSort();
	void regis_mergeSort(string attribute);
	void setId(string userId);
	void setPassword(string password);
	void setName(string name);
	void displayAll();
	void display();

};


void RegisteredUsers::display() {
	cout << this->ID << " " << this->name << endl;
}

void RegisteredUsers::displayAll() {
	this->regisDLL.displayAll();
}

void RegisteredUsers::regis_insertionSort() {
	auto start = high_resolution_clock::now();
	regisDLL.head = insertionSort_user(regisDLL.head, "date");
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by insertion sort algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}
void RegisteredUsers::insertToFile() {
	ofstream file_new("RegisUsers.csv");

	if (file_new.is_open()) {
		RegisteredUsers* current = regisDLL.head;
		cout << "TESID: " << current->ID << endl;
		cout << "ENDID: " << regisDLL.tail->ID << endl;
		while (current != NULL) //means still not the end of the list
		{
			cout << "id: " << current->ID << endl;
			cout << "name: " << current->name << endl;
			cout << "password: " << current->password << endl;
			cout << "last activity date: " << current->lastActiveDate << endl << endl;

			file_new << current->ID << ',';
			file_new << current->name << ',';
			file_new << current->password << ',';
			file_new << current->lastActiveDate << endl;

			current = current->nextAdd; //if you forgot this, will become a infinity loop
		}
		cout << "List is ended here! " << endl;
	}
	file_new.close();
}
void RegisteredUsers::feedback(string ID, string name, University* univ, Feedback* feed) {
	int univ_chosen;
	string feedback;

	cout << "Choose the university based on the rank number: ";
	cin >> univ_chosen;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "What's your feedback?";
	getline(cin, feedback);
	University* current = univ->univDLL.head;

	while (current != NULL) {
		if (univ_chosen == current->rank) {
			cout << "TES" << endl;
			cout << current->institution << endl;
			feed->InsertFeedback(ID, name, current->institution, feedback);
		}
		current = current->nextAdd;
	}
}
void RegisteredUsers::favorite(string ID, string name, University* univ, Favorite* fav) {

	int univ_chosen;


	cout << "Choose the university based on the rank number: ";
	cin >> univ_chosen;
	University* current = univ->univDLL.head;
	while (current != NULL) {
		if (univ_chosen == current->rank) {
			fav->insertToFavorite(ID, name, current->institution);
		}
		current = current->nextAdd;
	}


}
void RegisteredUsers::insertToList(string ID, string name, string password, string lastactivedate) {
	RegisteredUsers* newnode = new RegisteredUsers(ID, name, password, lastactivedate);
	regisDLL.insertEnd(newnode);
}

void RegisteredUsers::menu(RegisteredUsers* users, University* univ, Feedback* feed, Favorite* fav) {
	int opt;
	bool is_sort, is_chosen;
	do
	{
		cout << "HELLO: " << users->ID << "||" << users->name << endl;
		cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
		cout << "Select the option below: " << endl;
		cout << " 1. Search University" << endl;
		cout << " 2. Show University List" << endl;
		cout << " 3. Feedback" << endl;
		cout << " 4. Logout" << endl;
		cout << " 5. Exit" << endl;
		cin >> opt;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (opt)
		{
		case 1:

			//cout << "This is search" <<endl;
			univ->Cust_Bin_Search();

			break;
		case 2:
			int choice;
			int category;
			is_sort = false;
			is_chosen = false;
			while (!is_sort) {
				cout << "Which sorting algorithm will you choose?" << endl;
				cout << "1. Insertion Sort" << endl;
				cout << "2. Merge Sort" << endl;
				cin >> choice;
				switch (choice) {
				case 1:
					while (!is_chosen) {
						cout << "Which category will you sort on ?" << endl;
						cout << "1. Institution" << endl;
						cout << "2. Academic Reputation " << endl;
						cout << "3. Faculty/Student Ratio " << endl;
						cout << "4. Employer Reputation Score" << endl;
						cin >> category;
						switch (category)
						{
						case 1:
							univ->Univ_InsertionSort("institution");

							is_chosen = true;
							break;
						case 2:
							univ->Univ_InsertionSort("ArScore");

							is_chosen = true;
							break;
						case 3:
							univ->Univ_InsertionSort("FsrScore");

							is_chosen = true;
							break;
						case 4:
							univ->Univ_InsertionSort("ErScore");

							is_chosen = true;
							break;
						default:
							break;
						}
					}

					is_sort = true;
					break;
				case 2:
					cout << "This is merge sort" << endl;
					is_sort = true;
					break;
				default:
					cout << "Invalid Option" << endl;
					break;

				}
			}

			univ->displayUniversityInfo();
			int op;
			cout << "Please select one of the option" << endl;
			cout << "1. Back to menu" << endl;
			cout << "2. Set Favorite University" << endl;
			cout << "3. Give Feedback to University" << endl;
			cin >> op;
			switch (op) {
			case 1:
				break;
			case 2:
				favorite(users->ID, users->name, univ, fav);
				break;
			case 3:
				feedback(users->ID, users->name, univ, feed);
				break;
			default:
				cout << "Invalid input, please try again" << endl;
				break;

			}
			break;
		case 3:
			cout << "This will be feedback" << endl;

			break;
		case 4:
			break;

		case 5:
			return;
		default:
			cout << "Invalid input, please try again" << endl;
			break;
		}
	}

	while (opt != 4);
}
string RegisteredUsers::generateID() {
	if (regisDLL.head == NULL) {
		string newID = "US0001";
		return newID;
	}
	else if (regisDLL.head != NULL) {

		string lastID = regisDLL.tail->ID.substr(2, 4);
		int lastDigit = stoi(lastID);
		std::stringstream buffer;
		buffer << "US" << setw(4) << setfill('0') << lastDigit + 1;
		string newID = buffer.str();
		return newID;

	}
}

// TODO: check if these work
void RegisteredUsers::setId(string userId) {
	this->ID = userId;
}

void RegisteredUsers::setPassword(string password) {
	this->password = password;
}

void RegisteredUsers::setName(string name) {
	this->name = name;
}

bool RegisteredUsers::compareAttributes(RegisteredUsers* otherRegisteredUser, string attribute) {
	if (attribute == "name")
	{
		return (name.compare(otherRegisteredUser->name) <= 0);
	}
	else if (attribute == "ID")
	{
		return (ID.compare(otherRegisteredUser->ID) <= 0);
	}
	else if (attribute == "date") {
		return (lastActiveDate.compare(otherRegisteredUser->lastActiveDate) <= 0);
	}
}

string RegisteredUsers::getValueOf(string input) {
	if (input == "userId") {
		// TODO: check if this works
		return Users::ID;
	}
}

void RegisteredUsers::regis_mergeSort(string attribute) {
	auto start = high_resolution_clock::now();

	MergedSort<RegisteredUsers> mergeSortClass;
	mergeSortClass.mergeSort(&(regisDLL.head), attribute);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by merge sort algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}

void RegisteredUsers::user_register(RegisteredUsers* regis) {
	//cout << regisDLL.tail->ID << endl;
	string ID = generateID();
	string name, password, lastActiveDate;
	// current date/time based on current system
	time_t now = time(NULL);
	tm* ltm = localtime(&now);

	std::stringstream buffer;
	buffer << 1900 + ltm->tm_year << '/' << ltm->tm_mon + 1 << '/' << ltm->tm_mday << ' ' << ltm->tm_hour + 5 << ':' <<
		30 + ltm->tm_min << ':' << ltm->tm_sec;
	lastActiveDate = buffer.str();
	cout << "Enter your name: ";
	getline(cin, name);

	cout << "Enter your password: ";
	getline(cin, password);
	//std::ios::app
	insertToList(ID, name, password, lastActiveDate);
}


RegisteredUsers* RegisteredUsers::login(string ID, string password) {
	RegisteredUsers* current = regisDLL.head;
	while (current != NULL) {
		if (ID == current->ID && password == current->password) {
			cout << "Hello " << current->name << endl;
			// current date/time based on current system
			time_t now = time(NULL);
			tm* ltm = localtime(&now);

			std::stringstream buffer;
			buffer << 1900 + ltm->tm_year << '/' << ltm->tm_mon + 1 << '/' << ltm->tm_mday << ' ' << ltm->tm_hour + 5 << ':' <<
				30 + ltm->tm_min << ':' << ltm->tm_sec;
			lastActiveDate = buffer.str();
			return current;
		}
		current = current->nextAdd;
	}
	cout << "User not found!" << endl;
	return NULL;
}