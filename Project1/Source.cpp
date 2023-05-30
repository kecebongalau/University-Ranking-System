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
#include "Admin.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace std::chrono;


void login(University* univ, RegisteredUsers* regis, Admin* admin, Feedback* feed, Favorite* fav) {
	string ID, password;
	RegisteredUsers* Log_User;
	Admin* Log_Admin;
	cout << "Enter your ID: ";
	getline(cin, ID);
	cout << "Enter your password: ";
	string type = ID.substr(0, 2);
	getline(cin, password);
	if (type == "US") {
		Log_User = regis->login(ID, password);
		if (Log_User != NULL) {
			regis->menu(Log_User, univ, feed, fav);
		}
	}
	else if (type == "AD") {
		Log_Admin = admin->login(ID, password);
		if (Log_Admin != NULL) {
			admin->menu(Log_Admin, regis,feed, fav);
		}
	}
	else {
		cout << "User Not Found" << endl;
	}
	
}



int menu(University* univ, RegisteredUsers* regis, Admin* admin, Feedback* feed, Favorite* fav)
{
	int opt;
	int sort;
	bool asc;
	bool is_sort = false;
	string ID, password;
	RegisteredUsers* Log_User;
	do
	{
		is_sort = false;
		cout << endl << "===============WELCOME TO UNIVERSITY RANK SYSTEM======================" << endl;
		cout << "Select the option below: " << endl;
		cout << " 1. Register" << endl;
		cout << " 2. Login" << endl;
		cout << " 3. Show University List" << endl;
		cout << " 4. Search University" << endl;
		cout << " 5. Exit" << endl;
		cin >> opt;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (opt)
		{
		case 1:
			regis->user_register(regis);
			regis->menu(regis->regisDLL.tail, univ, feed, fav);
			break;
		case 2:
			login(univ, regis, admin, feed, fav);
			break;
		case 3:
			cout << "===================Display Menu====================" << endl;
			int choice;
			while (!is_sort) {
				cout << "Which sorting algorithm will you choose?" << endl;
				cout << "1. Insertion Sort" << endl;
				cout << "2. Merge Sort" << endl;
				cout << "3. Rank" << endl;
				cin >> choice;
				switch (choice) {
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
					univ->Univ_InsertionSort("institution", asc);
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
					univ->Univ_MergedSort("institution", asc);
					is_sort = true;
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
					is_sort = true;
					break;
				default:
					cout << "Invalid Option" << endl;
					break;

				}
			}

			system("pause");
			univ->displayAll();
			break;
		case 4:
			int opt;

			cout << "Which searching algorithm will you choose?" << endl;
			cout << "1. Binary Search" << endl;
			cout << "2. Linear Search" << endl;
			cin >> opt;
			switch (opt) {
			case 1:
				univ->Bin_Search();
				break;
			case 2:
				univ->Lin_Search();
				break;
			default:
				cout << "Invalid Option" << endl;
				break;
			}
			break;
		case 5:
			cout << "Thank you for using this program!" << endl;
			return 0;
			break;
		default:
			cout << "Invalid input, please try again" << endl;
			break;
		}
	} while (opt != 5);

	return 0;
}


void exit_file(RegisteredUsers* regis, Feedback* feed, Favorite* fav) {
	regis->insertToFile();
	feed->InsertToFile();
	fav->insertToFile();

}
int main()
{

	string rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore,
		CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled;
	string ID, name, password, lastactivedate;
	int counter = 0;
	University* univ = new University();
	RegisteredUsers* regis = new RegisteredUsers();
	Favorite* fav = new Favorite();
	Feedback* feed = new Feedback();
	Admin* admin = new Admin();
	fstream file("2023 QS World University Rankings.csv", ios::in);
	if (file.is_open()) {
		while (file.good())
		{
			getline(file, rank, ',');
			getline(file, institution, ',');
			getline(file, LocationCode, ',');
			getline(file, Location, ',');
			getline(file, ArScore, ',');
			getline(file, ArRank, ',');
			getline(file, ErScore, ',');
			getline(file, ErRank, ',');
			getline(file, FsrScore, ',');
			getline(file, FsrRank, ',');
			getline(file, CpfScore, ',');
			getline(file, CpfRank, ',');
			getline(file, IfrScore, ',');
			getline(file, IfrRank, ',');
			getline(file, IsrScore, ',');
			getline(file, IsrRank, ',');
			getline(file, IrnScore, ',');
			getline(file, IrnRank, ',');
			getline(file, GerScore, ',');
			getline(file, GerRank, ',');
			getline(file, ScoreScaled);

			if (counter > 0) {
				univ->insertToEndList(rank, institution, LocationCode, Location, ArScore, ArRank,
					ErScore, ErRank, FsrScore, FsrRank, CpfScore,
					CpfRank, IfrScore, IfrRank, IsrScore,
					IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);
			}
			counter++;
		}
	}


	file.close();

	ifstream file_regis("RegisUsers.csv", ios::in);
	if (file_regis.is_open()) {
		while (file_regis.peek() != EOF) {
			getline(file_regis, ID, ',');
			getline(file_regis, name, ',');
			getline(file_regis, password, ',');
			getline(file_regis, lastactivedate, '\n');
			regis->insertToList(ID, name, password, lastactivedate);

		}

	}
	file_regis.close();

	string feedbackID, feedback, feedbackDate, reply, replydate;
	ifstream file_feed("Feedback.csv", ios::in);
	if (file_feed.is_open()) {
		while (file_feed.peek() != EOF) {
			getline(file_feed, feedbackID, ',');
			getline(file_feed, ID, ',');
			getline(file_feed, institution, ',');
			getline(file_feed, feedback, ',');
			getline(file_feed, feedbackDate, ',');
			getline(file_feed, reply, ',');
			getline(file_feed, replydate, '\n');
			feed->InsertToList(feedbackID, ID, institution, feedback, feedbackDate, reply, replydate);
		}

	}
	file_feed.close();

	ifstream file_fav("Favorite.csv", ios::in);
	if (file_fav.is_open()) {
		while (file_fav.peek() != EOF) {
			getline(file_fav, ID, ',');
			getline(file_fav, institution, '\n');
			fav->insertToFavorite(ID, institution);
		}

	}
	file_fav.close();

	ifstream file_admin("Admin.csv", ios::in);
	if (file_admin.is_open()) {
		while (file_admin.peek() != EOF) {
			getline(file_admin, ID, ',');
			getline(file_admin, name, ',');
			getline(file_admin, password, '\n');
			admin->insertToList(ID, name, password);
		}
	}
	file_admin.close();
	menu(univ, regis, admin, feed, fav);
	exit_file(regis, feed, fav);
}
