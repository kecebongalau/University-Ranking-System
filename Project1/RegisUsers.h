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
	void feedback(string ID, University* univ, Feedback* feed);
	void favorite(string ID,  University* univ, Favorite* fav);
	void insertToFile();
	string getValueOf(string input);
	void regis_insertionSort(string data, bool asc);
	void regis_mergeSort(string attribute);
	void setId(string userId);
	void setPassword(string password);
	void setName(string name);
	void displayAll();
	void display();

};


void RegisteredUsers::display() {
	cout << left << setw(10) << this->ID << '|';
	cout << setw(20) << this->password << '|';
	cout << setw(30) << this->name << '|';
	cout << setw(30) << this->lastActiveDate << '|' <<endl;
}

void RegisteredUsers::displayAll() {
	this->regisDLL.displayAll();
}

void RegisteredUsers::regis_insertionSort(string data, bool asc) {
	auto start = high_resolution_clock::now();
	regisDLL.head = insertionSort(regisDLL.head, data, asc);
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

			file_new << current->ID << ',';
			file_new << current->name << ',';
			file_new << current->password << ',';
			file_new << current->lastActiveDate << endl;

			current = current->nextAdd; //if you forgot this, will become a infinity loop
		}
		cout << "Updating RegisUsers.csv " << endl;
	}
	file_new.close();
}
void RegisteredUsers::feedback(string ID, University* univ, Feedback* feed) {
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
			feed->InsertFeedback(ID, current->institution, feedback);
			return;
		}
		current = current->nextAdd;
	}
}
void RegisteredUsers::favorite(string ID, University* univ, Favorite* fav) {

	int univ_chosen;


	cout << "Choose the university based on the rank number: ";
	cin >> univ_chosen;
	University* current = univ->univDLL.head;
	while (current != NULL) {
		if (univ_chosen == current->rank) {
			fav->insertToFavorite(ID, current->institution);
			return;
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
	LinearSearch<Favorite> linearSearchFav;
	LinearSearch<Feedback> linearSearchFeed;
	do
	{
		cout << "HELLO: " << users->ID << "||" << users->name << endl;
		cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
		cout << "Select the option below: " << endl;
		cout << " 1. Search University" << endl;
		cout << " 2. Show University List" << endl;
		cout << " 3. Show Favorite University" << endl;
		cout << " 4. Show All Feedback" << endl;
		cout << " 5. Logout" << endl;
		cin >> opt;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (opt){
		case 1:
			univ->Cust_LinSearch();
			break;
		case 2:
			int choice;
			int category;
			is_sort = false;
			is_chosen = false;
			int sort;
			int op;
			bool asc;
			cout << "Please select one of the option" << endl;
			cout << "1. Display University" << endl;
			cout << "2. Set Favorite University" << endl;
			cout << "3. Give Feedback to University" << endl;
			cin >> op;
			switch (op) {
			case 1:
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
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort!=1 && sort!=2);
								
								univ->Univ_InsertionSort("institution", asc);

								is_chosen = true;
								break;
							case 2:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_InsertionSort("arscore", asc);

								is_chosen = true;
								break;
							case 3:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_InsertionSort("fsrscore", asc);

								is_chosen = true;
								break;
							case 4:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_InsertionSort("erscore", asc);

								is_chosen = true;
								break;
							default:
								break;
							}
						}

						is_sort = true;
						break;
					case 2:
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
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_MergedSort("institution");

								is_chosen = true;
								break;
							case 2:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_MergedSort("arscore");

								is_chosen = true;
								break;
							case 3:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_MergedSort("fsrscore");

								is_chosen = true;
								break;
							case 4:
								do
								{
									cout << "Which order will you sort on? " << endl;
									cout << "1. Ascending" << endl;
									cout << "2. Descending" << endl;
									cin >> sort;
									switch (sort)
									{
									case 1:
										asc = true;
										break;
									case 2:
										asc = false;
										break;
									default:
										break;
									}
								} while (sort != 1 && sort != 2);
								univ->Univ_MergedSort("erscore");

								is_chosen = true;
								break;
							default:
								break;
							}
							is_sort = true;
							break;
						}
					default:
						cout << "Invalid Option" << endl;
						break;

					}
				}
				system("pause");
				univ->displayUniversityInfo();
				break;
			case 2:
				favorite(users->ID, univ, fav);
				break;
			case 3:
				feedback(users->ID, univ, feed);
				break;
			default:
				cout << "Invalid input, please try again" << endl;
				break;

			}
			break;
		case 3:

				
			linearSearchFav.linearSearch(fav->favDLL.head,users->ID, "userId");
			break;
		case 4:
			linearSearchFeed.linearSearch(feed->feedDLL.head, users->ID, "userID");
		case 5:
			break;

		default:
			cout << "Invalid input, please try again" << endl;
			break;
		}
	}

	while (opt != 5);
}
string RegisteredUsers::generateID() {
	if (regisDLL.head == NULL) {
		string newID = "US0001";
		return newID;
	}
	else if (regisDLL.head != NULL) {
		regisDLL.head = insertionSort(regisDLL.head, "ID", true);
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
		return this->ID;
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
	buffer << 1900 + ltm->tm_year << '/' << setw(2) << setfill('0') << ltm->tm_mon + 1 << '/' <<
		setw(2) << setfill('0') << ltm->tm_mday << ' ' << setw(2) << setfill('0') << ltm->tm_hour << ':' <<
		setw(2) << setfill('0') << ltm->tm_min << ':' << setw(2) << setfill('0') << ltm->tm_sec;
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
			buffer << 1900 + ltm->tm_year << '/' << setw(2) << setfill('0') << ltm->tm_mon + 1 << '/' << 
				setw(2) << setfill('0') << ltm->tm_mday << ' ' << setw(2) << setfill('0') << ltm->tm_hour << ':' <<
				setw(2) << setfill('0') << ltm->tm_min << ':' << setw(2) << setfill('0') << ltm->tm_sec;
			current->lastActiveDate = buffer.str();
			return current;
		}
		current = current->nextAdd;
	}
	cout << "User not found!" << endl;
	return NULL;
}