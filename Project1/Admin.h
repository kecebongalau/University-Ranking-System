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
#include "RegisUsers.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace std::chrono;

class Admin : Users {
public:
	DoubleLinkedList<Admin> adminDLL;
	Admin* nextAdd;
	Admin* prevAdd;
	Admin() {
		this->ID = "";
		this->name = "";
		this->password = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}
	Admin(string ID, string name, string password) {
		this->ID = ID;
		this->name = name;
		this->password = password;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	};
	~Admin() {};

	void insertToList(string ID, string name, string password) {
		Admin* newnode = new Admin(ID, name, password);
		adminDLL.insertEnd(newnode);
	}
	void menu(Admin* admin, RegisteredUsers* regis, Feedback* feed, Favorite* fav) {
		int opt, choice;
		string ID, feedbackID;
		HashMap<int>* hashmap;
		do
		{
			cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
			cout << "Select the option below: " << endl;
			cout << " 1. Manage Users" << endl;
			cout << " 2. Manage Feedback" << endl;
			cout << " 3. Generate Report" << endl;
			cout << " 4. Logout" << endl;
			cin >> opt;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (opt)
			{
			case 1:
				
				do {
					cout << "==============Manage User Menu==============" << endl;
					cout << "1. Display all users" << endl;
					cout << "2. Delete User" << endl;
					cout << "3. Modify User" << endl;
					cout << "4. Exit" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						displayAllRegisteredUsers(regis);
						break;
					case 2:
						cout << "Enter the user ID: ";
						cin >> ID;
						cout << "ID: " << ID << endl;
						deleteRegisUser(ID, regis);
						break;
					case 3:
						cout << "Enter the user ID: ";
						cin >> ID;
						modifyUsers(ID, regis);
						break;
					case 4:
						break;
					default:
						break;
					}
				} while (choice != 4);

				break;
			case 2:
				do {
					cout << "==============Manage Feedback Menu==============" << endl;
					cout << "1. Display all Feedback" << endl;
					cout << "2. Reply Feedback" << endl;
					cout << "3. Exit" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						displayAllFeedback(feed);
						break;
					case 2:
						cout << "Enter the feedback ID: ";
						cin >> feedbackID;
						cout << "ID: " << feedbackID << endl;
						replyToFeedback(feedbackID, feed);
						break;

					default:
						break;
					}
				} while (choice!=3);
				break;

			case 3:
				cout << "Generate Report" << endl;
				hashmap = calculateTopUniversities(fav->favDLL);
				hashmap->display();
				break;
			case 4:
				return;
			default:
				cout << "Invalid input, please try again" << endl;
				break;
			}
		}

		while (opt != 6);
	};

	Admin* login(string ID, string password) {
		Admin* current = adminDLL.head;
		while (current != NULL) {
			if (ID == current->ID && password == current->password) {

				cout << "Hello " << current->name << endl;
				return current;

			}

			current = current->nextAdd;
		}
		cout << "User not found!" << endl;
		return NULL;
	}
	// display registered users
	void displayAllRegisteredUsers(RegisteredUsers* regis) {
		int choice, sort;
		bool is_sort = false;
		bool asc;
		while (!is_sort)
		{
			cout << "Which sorting algorithm will you choose?" << endl;
			cout << "1. Insertion Sort" << endl;
			cout << "2. Merge Sort" << endl;
			cin >> choice;
			switch (choice)
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
				regis->regis_insertionSort("date", asc);

				is_sort = true;
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
				regis->regis_mergeSort("date");

				is_sort = true;
				break;
			default:
				break;
			}
		}
		regis->displayAll();
	}
	// delete user
	void deleteRegisUser(string ID, RegisteredUsers* regis) {

		LinearSearch<RegisteredUsers> linearSearchClass;

		RegisteredUsers* users = linearSearchClass.linearSearch_Node(regis->regisDLL.head, ID, "userId");


		regis->regisDLL.deleteNode(users);
	}
	// Generate top 10 uni
	HashMap<int>* calculateTopUniversities(DoubleLinkedList<Favorite> favDLL) {
		HashMap<int>* uniToCount = new HashMap<int>();
		Favorite* current = favDLL.head;
		while (current != NULL)
		{
			if (uniToCount->hasKey(current->institution))
			{
				uniToCount->setValue(current->institution, uniToCount->getValue(current->institution) + 1);
			}
			else
			{
				uniToCount->setValue(current->institution, 1);
			}
			current = current->nextAdd;
		}

		MergedSort<HashMapNode<int>> mergeSortClass;
		mergeSortClass.mergeSort(&(uniToCount->HashMapdll.head), "value");

		return uniToCount;
	}
	// Modify user
	void modifyUsers(string ID, RegisteredUsers* regis) {
		string input;
		int choice = 0;

		while (choice != 1 && choice != 2)
		{
			cout << "Which attribute do you want to change?" << endl;
			cout << "1. Name" << endl;
			cout << "2. Password" << endl;
			cin >> choice;

			LinearSearch<RegisteredUsers> linearSearchClass;
			RegisteredUsers* regisUser;

			switch (choice)
			{
			case 1:
				cout << "What is the new name" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, input);
				regisUser = linearSearchClass.linearSearch_Node(regis->regisDLL.head, ID, "userId");
				if (regisUser != NULL) {
					regisUser->setName(input);
				}
				else {
					cout << "User not found" << endl;
				}
				

				break;
			case 2:
				cout << "What is the new password" << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin,input);
				regisUser = linearSearchClass.linearSearch_Node(regis->regisDLL.head, ID, "userId");
				if (regisUser != NULL) {
					regisUser->setPassword(input);
				}
				else {
					cout << "User not found" << endl;
				}
				
				break;
			default:
				cout << "Invalid Choice" << endl;
				break;
			}
		}
	}
	// Display feedback
	void displayAllFeedback(Feedback* feedbacks) {
	int choice, sort;
	bool is_sort = false;
	bool asc;

	while (!is_sort)
	{
		cout << "Which sorting algorithm will you choose?" << endl;
		cout << "1. Insertion Sort" << endl;
		cout << "2. Merge Sort" << endl;
		cin >> choice;
		switch (choice)
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
			feedbacks->feed_insertionSort("feedbackDate", asc);

			is_sort = true;
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
			feedbacks->mergeSort("feedbackDate", asc);

			is_sort = true;
			break;
		default:
			break;
		}
	}
	feedbacks->displayAll();
	}
	// Replay to feedback
	void replyToFeedback(string feedbackId, Feedback * feedbacks) {
		LinearSearch<Feedback> linearSearchClass;
		Feedback * feedback = linearSearchClass.linearSearch_Node(feedbacks->feedDLL.head, feedbackId, "feedbackId");
		string reply;
		string replyDate;
		if (feedback != NULL) {
			cout << "Please insert the reply here: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, reply);
			
			feedback->setReply(reply);

			// Get current time and convert format
			time_t now = time(NULL);
			tm* ltm = localtime(&now);

			std::stringstream buffer;
			buffer << 1900 + ltm->tm_year << '/' << setw(2) << setfill('0') << ltm->tm_mon + 1 << '/' <<
				setw(2) << setfill('0') << ltm->tm_mday << ' ' << setw(2) << setfill('0') << ltm->tm_hour << ':' <<
				setw(2) << setfill('0') << ltm->tm_min << ':' << setw(2) << setfill('0') << ltm->tm_sec;
			replyDate = buffer.str();

			feedback->setReplyDate(replyDate);
		}
		else {
			cout << "INVALID FEEDBACK ID!" << endl;
		}
		
	}

};