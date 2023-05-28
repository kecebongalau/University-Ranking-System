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






int menu(University* univ, RegisteredUsers* regis, Feedback* feed, Favorite* fav)
{
	int opt;
	bool is_sort = false;
	string ID, password;
	RegisteredUsers* Log_User;
	do
	{
		cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
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
			cout << "Enter your ID: ";
			getline(cin, ID);
			cout << "Enter your password: ";
			getline(cin, password);
			Log_User = regis->login(ID, password);
			if (Log_User != NULL) {
				regis->menu(Log_User, univ, feed, fav);
			}
			break;
		case 3:
			int choice;
			while (!is_sort) {
				cout << "Which sorting algorithm will you choose?" << endl;
				cout << "1. Insertion Sort" << endl;
				cout << "2. Merge Sort" << endl;
				cout << "3. Rank" << endl;
				cin >> choice;
				switch (choice) {
				case 1:
					univ->Univ_InsertionSort("institution");
					is_sort = true;
					break;
				case 2:
					univ->Univ_MergedSort("institution");
					cout << "This is merge sort" << endl;
					is_sort = true;
					break;
				case 3:
					is_sort = true;
					break;
				default:
					cout << "Invalid Option" << endl;
					break;

				}
			}
			univ->displayUniversityInfo();
			break;
		case 4:
			//univ->Univ_Search();
			int opt;
			//bool stat = false;
			cout << "Which searching algorithm will you choose?" << endl;
			cout << "1. Binary Search" << endl;
			cout << "2. Linear Search" << endl;
			cin >> opt;
			switch (opt) {
			case 1:
				cout << "ini bin sea" << endl;
				univ->Bin_Search();
				//stat = true;
				break;
			case 2:
				univ->Lin_Search();
				//stat = true;
				break;
			default:
				cout << "Invalid Option" << endl;
				break;
			}


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

// class Admin : public RegisteredUsers {
// public:
//	Admin(string ID, string name, string password) {
//		this->ID = ID;
//		this->name = name;
//		this->password = password;
//		this->nextAdd = NULL;
//		this->prevAdd = NULL;
//	}
//
//	bool login();
//	void logout();
//	void insertToEndList(string ID, string name, string password, string lastActiveDate);
//	void deleteFromList(string ID, int position);
//	void search(string ID);
//	void replyFeedback();
//	void summarize();
// };

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
			cout << "tes ID: " << ID << endl;
			cout << "name: " << name << endl;
			cout << "Date: " << lastactivedate << endl;
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
			getline(file_feed, name, ',');
			getline(file_feed, institution, ',');
			getline(file_feed, feedback, ',');
			getline(file_feed, feedbackDate, ',');
			getline(file_feed, reply, ',');
			getline(file_feed, replydate, '\n');
			//cout << "FeedbackID: " << feedbackID << "BABI" << endl;
			feed->InsertToList(feedbackID, ID, name, institution, feedback, feedbackDate, reply, replydate);
		}

	}
	file_feed.close();

	ifstream file_fav("Favorite.csv", ios::in);
	if (file_fav.is_open()) {
		while (file_fav.peek() != EOF) {
			getline(file_fav, ID, ',');
			getline(file_fav, name, ',');
			getline(file_fav, institution, '\n');
			fav->insertToFavorite(ID, name, institution);
		}

	}
	file_fav.close();

	menu(univ, regis, feed, fav);
	exit_file(regis, feed, fav);
}
