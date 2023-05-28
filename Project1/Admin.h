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
			cout << " 5. Exit" << endl;
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
				} while (choice != 1 && choice !=2 && choice != 3);

				break;
			case 2:
				do {
					cout << "==============Manage Feedback Menu==============" << endl;
					cout << "1. Display all Feedback" << endl;
					cout << "2. Reply Feedback" << endl;
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
				} while (choice != 4);
				break;

			case 3:
				cout << "Generate Report" << endl;
				hashmap = calculateTopUniversities(fav->favDLL);
				hashmap->display();
				break;
			case 4:
				cout << "Logout" << endl;
				return;
			case 5:
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
		int choice;
		bool is_sort = false;

		while (!is_sort)
		{
			cout << "Which sorting algorithm will you choose?" << endl;
			cout << "1. Insertion Sort" << endl;
			cout << "2. Merge Sort" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				regis->regis_insertionSort();
				cout << "This is insertion sort" << endl;
				is_sort = true;
			case 2:
				regis->regis_mergeSort("date");
				cout << "This is merge sort" << endl;
				is_sort = true;
			default:
				break;
			}
		}
		regis->displayAll();
	}
	// delete user
	void deleteRegisUser(string ID, RegisteredUsers* regis) {

		LinearSearch<RegisteredUsers> linearSearchClass;
		RegisteredUsers* users = linearSearchClass.linearSearch(regis->regisDLL.head, ID, "userId");

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
				cin >> input;
				regisUser = linearSearchClass.linearSearch(regis->regisDLL.head, ID, "userId");

				regisUser->setName(input);

				break;
			case 2:
				cout << "What is the new password" << endl;
				cin >> input;
				regisUser = linearSearchClass.linearSearch(regis->regisDLL.head, ID, "userId");

				regisUser->setPassword(input);
				break;
			default:
				break;
			}
		}
	}
	// Display feedback
	void displayAllFeedback(Feedback* feedbacks) {
	int choice;
	bool is_sort = false;

	while (!is_sort)
	{
		cout << "Which sorting algorithm will you choose?" << endl;
		cout << "1. Insertion Sort" << endl;
		cout << "2. Merge Sort" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			// regis->regis_insertionSort();
			cout << "This is insertion sort" << endl;
			is_sort = true;
		case 2:
			feedbacks->mergeSort("feedbackDate");
			cout << "This is merge sort" << endl;
			is_sort = true;
		default:
			break;
		}
	}
	feedbacks->displayAll();
	}
	// Replay to feedback
	void replyToFeedback(string feedbackId, Feedback * feedbacks) {
		LinearSearch<Feedback> linearSearchClass;
		Feedback * feedback = linearSearchClass.linearSearch(feedbacks->feedDLL.head, feedbackId, "feedbackId");
		string reply;
		string replyDate;

		cout << "Please insert the reply here: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> reply;

		feedback->setReply(reply);

		// Get current time and convert format
		time_t now = time(NULL);
		tm* ltm = localtime(&now);

		std::stringstream buffer;
		buffer << 1900 + ltm->tm_year << '/' << ltm->tm_mon + 1 << '/' << ltm->tm_mday << ' ' << ltm->tm_hour + 5 << ':' <<
			30 + ltm->tm_min << ':' << ltm->tm_sec;
		replyDate = buffer.str();

		feedback->setReplyDate(replyDate);
	}

};