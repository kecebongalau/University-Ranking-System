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
		ofstream file("Favorite.csv", std::ios::app);
		if (file.is_open()) {
			Favorite* current = favDLL.tail;
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


class Feedback {
public:
	string userID;
	string userName;
	string institution;
	string feedback;
	string reply; // for admin
	Feedback* nextAdd;
	Feedback* prevAdd;
	DoubleLinkedList<Feedback> feedDLL;

	Feedback() {
		this->userID = "";
		this->userName = "";
		this->institution = "";
		this->feedback = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
		this->reply = "";

	}
	Feedback(string userID, string userName, string institution, string feedback) {
		this->userID = userID;
		this->userName = userName;
		this->institution = institution;
		this->feedback = feedback;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
		this->reply = "";

	}
	void setReply(string reply) {
		this->reply = reply;
	}
	string getReply() {
		return this->reply;
	}
	void InsertFeedback(string userID, string userName, string institution, string feedback) {
		Feedback* newnode = new Feedback(userID, userName, institution, feedback);
		feedDLL.insertEnd(newnode);

		
	}
	void InsertToFile() {
		ofstream file("Feedback.csv", std::ios::app);
		if (file.is_open()) {
			Feedback* current = feedDLL.tail;
			cout << current->feedback << endl;
			while (current != NULL) //means still not the end of the list
			{
				cout << "User ID: " << current->userID << endl;
				cout << "User Name: " << current->userName << endl;
				cout << "Institution: " << current->institution << endl;
				cout << "Feedback: " << current->feedback << endl;

				file << current->userID << ',';
				file << current->userName << ',';
				file << current->institution << ',';
				file << current->feedback << endl;

				current = current->nextAdd; //if you forgot this, will become a infinity loop
			}
			cout << "List is ended here! " << endl;
		}
		file.close();
	}
};
class University
{
	University* head; University* tail;
public:
	int rank;
	string institution;
	string LocationCode;
	string Location;
	double ArScore;
	int ArRank;
	double ErScore;
	int ErRank;
	double FsrScore;
	int FsrRank;
	double CpfScore;
	int CpfRank;
	double IfrScore;
	int IfrRank;
	double IsrScore;
	int IsrRank;
	double IrnScore;
	int IrnRank;
	double GerScore;
	int GerRank;
	double ScoreScaled;
	University* nextAdd;
	University* prevAdd;
	//SingleLinkedList<University> univDLL;
	DoubleLinkedList<University> univDLL;

	University(int rank, string institution, string LocationCode, string Location, double ArScore, int ArRank,
		double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore,
		int IsrRank, double IrnSCore, int IrnRank, double GerScore, int GerRank, double ScoreScaled) {

		this->rank = rank;
		this->institution = institution;
		this->LocationCode = LocationCode;
		this->Location = Location;
		this->ArScore = ArScore;
		this->ArRank = ArRank;
		this->ErScore = ErScore;
		this->ErRank = ErRank;
		this->FsrScore = FsrScore;
		this->FsrRank = FsrRank;
		this->CpfScore = CpfScore;
		this->CpfRank = CpfRank;
		this->IfrScore = IfrScore;
		this->IfrRank = IfrRank;
		this->IsrScore = IsrScore;
		this->IsrRank = IsrRank;
		this->IrnScore = IrnSCore;
		this->IrnRank = IrnRank;
		this->GerScore = GerScore;
		this->GerRank = GerRank;
		this->ScoreScaled = ScoreScaled;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	University() {
		this->rank = NULL;
		this->institution = "";
		this->LocationCode = "";
		this->Location = "";
		this->ArScore = NULL;
		this->ArRank = NULL;
		this->ErScore = NULL;
		this->ErRank = NULL;
		this->FsrScore = NULL;
		this->FsrRank = NULL;
		this->CpfScore = NULL;
		this->CpfRank = NULL;
		this->IfrScore = NULL;
		this->IfrRank = NULL;
		this->IsrScore = NULL;
		this->IsrRank = NULL;
		this->IrnScore = NULL;
		this->IrnRank = NULL;
		this->GerScore = NULL;
		this->GerRank = NULL;
		this->ScoreScaled = NULL;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	void insertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled);
	void Bin_Search();
	void Lin_Search();

	void Univ_InsertionSort(string data);
	void Univ_MergedSort(string attribute);
	void displayUniversityInfo();

	// Needed for display
	void display();

	// Needed for sort
	bool compareAttributes(University * otherUniversity, string attribute);

	// Needed for search
	string getValueOf(string input);
};

void University::Univ_InsertionSort(string data) {
	auto start = high_resolution_clock::now();
	univDLL.head = insertionSort(univDLL.head, data);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by insertion sort algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}

void University::Univ_MergedSort(string attribute) {
	auto start = high_resolution_clock::now();
	MergedSort<University> mergeSortClass;
	mergeSortClass.mergeSort(&(univDLL.head), attribute);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by merge sort algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}

void University::insertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
	string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
	string IsrRank, string IrnScore, string IrnRank, string GerScore, string GerRank, string ScoreScaled) 
{	
	int new_rank, new_ArRank, new_ErRank, new_FsrRank, new_CpfRank, new_IfrRank, new_IsrRank, new_IrnRank, new_GerRank;
	double new_ArScore, new_ErScore, new_FsrScore, new_CpfScore, new_IfrScore, new_IsrScore, new_IrnScore, new_GerScore, new_Score;
	try {
		new_rank = stoi(rank);
	}
	catch (...) {
		new_rank = -1;
	}
	try {
		new_ArScore = stod(ArScore);
	}
	catch (...) {
		new_ArScore = -1;
	}
	try {
		new_ArRank = stoi(ArRank);
	}
	catch (...) {
		new_rank = -1;
	}
	try {
		new_ErScore = stod(ErScore);
	}
	catch (...) {
		new_ErScore = -1;
	}
	try {
		new_ErRank = stoi(ErRank);
	}
	catch (...) {
		new_ErRank = -1;

	}

	try {
		new_FsrScore = stod(FsrScore);
	}
	catch (...) {
		new_FsrScore = -1;

	}

	try {
		new_FsrRank = stoi(ErRank);
	}
	catch (...) {
		new_FsrRank = -1;

	}

	try {
		new_CpfScore= stod(CpfScore);
	}
	catch (...) {
		new_CpfScore = -1;

	}

	try {
		new_CpfRank = stoi(CpfRank);
	}
	catch (...) {
		new_CpfRank = -1;

	}
	try {
		new_IfrScore = stod(IfrScore);
	}
	catch (...) {
		new_IfrScore = -1;

	}

	try {
		new_IfrRank = stoi(IfrRank);
	}
	catch (...) {
		new_IfrRank = -1;

	}

	try {
		new_IsrScore = stod(IsrScore);
	}
	catch (...) {
		new_IsrScore = -1;

	}

	try {
		new_IsrRank = stoi(IsrRank);
	}
	catch (...) {
		new_IsrRank = -1;

	}

	try {
		new_IrnScore = stod(IrnScore);
	}
	catch (...) {
		new_IrnScore = -1;

	}

	try {
		new_IrnRank = stoi(IrnRank);
	}
	catch (...) {
		new_IrnRank = -1;

	}

	try {
		new_GerScore = stod(GerScore);
	}
	catch (...) {
		new_GerScore = -1;

	}

	try {
		new_GerRank = stoi(GerRank);
	}
	catch (...) {
		new_GerRank = -1;

	}

	try {
		new_Score = stod(ScoreScaled);
	}
	catch (...) {
		new_Score = -1;

	}

	University* newnode = new University(new_rank, institution, LocationCode, Location, new_ArScore, new_ArRank, new_ErScore, 
		new_ErRank, new_FsrScore, new_FsrRank, new_CpfScore, new_CpfRank, new_IfrScore, new_IfrRank, new_IsrScore, 
		new_IsrRank, new_IrnScore, new_IrnRank, new_GerScore, new_GerRank, new_Score);
	univDLL.insertEnd(newnode);

	
}

bool University::compareAttributes(University* otheruniversity, string attribute) {
	if (attribute == "institution")
	{
		return (institution.compare(otheruniversity->institution) <= 0);
	}
	else if (attribute == "rank")
	{
		return (rank <= otheruniversity->rank);
	}
	else if (attribute == "location code")
	{
		return (LocationCode.compare(otheruniversity->LocationCode) <= 0);
	}
	else if (attribute == "location")
	{
		return (Location.compare(otheruniversity->Location) <= 0);
	}
	else if (attribute == "arrank")
	{
		return (ArRank <= otheruniversity->ArRank);
	}
	else if (attribute == "arscore")
	{
		return (ArScore<= otheruniversity->ArScore);
	}
	else if (attribute == "errank")
	{
		return (ErRank <= otheruniversity->ErRank);
	}
	else if (attribute == "erscore")
	{
		return (ErScore <= otheruniversity->ErScore);
	}
	else if (attribute == "fsrrank")
	{
		return (FsrRank <= otheruniversity->FsrRank);
	}
	else if (attribute == "fsrscore")
	{
		return (FsrScore <= otheruniversity->FsrScore);
	}
	else if (attribute == "cpfrank")
	{
		return (CpfRank	<= otheruniversity->CpfRank);
	}
	else if (attribute == "cpfscore")
	{
		return (CpfScore <= otheruniversity->CpfScore);
	}
	else if (attribute == "ifrrank")
	{
		return (IfrRank <= otheruniversity->IfrRank);
	}
	else if (attribute == "ifrscore")
	{
		return (IfrScore <= otheruniversity->IfrScore);
	}
	else if (attribute == "isrrank")
	{
		return (IsrRank <= otheruniversity->IsrRank);
	}
	else if (attribute == "isrscore")
	{
		return (IsrScore <= otheruniversity->IsrScore);
	}
	else if (attribute == "gerrank")
	{
		return (GerRank <= otheruniversity->GerRank);
	}
	else if (attribute == "gerscore")
	{
		return (GerScore <= otheruniversity->GerScore);
	}
	else if (attribute == "score scaled")
	{
		return (ScoreScaled <= otheruniversity->ScoreScaled);
	}
}

string University::getValueOf(string input) {
	if (input == "rank") {
		return to_string(this->rank);
	}
	else if (input == "institution")
	{
		return this->institution;
	}
}

void University::display() {
	cout << "Rank: " << rank << endl;
	cout << "Institution: " << institution << endl;
	cout << "Location Code: " << LocationCode << endl;
	cout << "Location: " << Location << endl;
	cout << "Academic Reputation Score: " << ArScore << endl;
	cout << "Academic Reputation Rank: " << ArRank << endl;
	cout << "Employer Reputation Score: " << ErScore << endl;
	cout << "Employer Reputation Rank: " << ErRank << endl;
	cout << "Academic Reputation Rank: " << ErRank << endl;
	cout << "Faculty/student ratio Score: " << FsrScore << endl;
	cout << "Faculty/student ratio Rank: " << FsrRank << endl;
	cout << "Citations per faculty Score: " << CpfScore << endl;
	cout << "Citations per faculty Rank: " << CpfRank << endl;
	cout << "International faculty ratio Score: " << IfrScore << endl;
	cout << "International faculty ratio Rank: " << IfrRank << endl;
	cout << "International student ratio Score: " << IsrScore << endl;
	cout << "International student ratio Rank: " << IsrRank << endl;
	cout << "International research network Score: " << IrnScore << endl;
	cout << "International research network Rank: " << IrnRank << endl;
	cout << "Employment Outcome Score: " << GerScore << endl;
	cout << "Employment Outcome Rank: " << GerRank << endl;
	cout << "Score Scaled: " << ScoreScaled << endl;
}

void University::displayUniversityInfo() //Big O - O(n)
{
	univDLL.displayAll();
}

void University::Bin_Search(){
	//string rank;
	//cout << "Enter what to search: ";
	//getline(cin, rank);
	////univDLL.head = insertionSort(univDLL.head, rank);
	//University* found = binarySearch(univDLL.head, rank);
	//if (found != NULL) {
	//	cout << "Rank: " << found->rank << endl;
	//	cout << "Univ: " << found->institution << endl;
	//}
	//else {
	//	cout << "Error" << endl;
	//}

	string input;
	int option;
	cout << "Binary Search Option: " << endl;
	cout << " 1. Rank " << endl;
	cout << " 2. Institution " << endl;
	cout << " 3. Location " << endl;
	cout << "Option: ";
	cin >> option;
	if (option == 1) {
		//attribute == rank;
		cout << "Enter what to search: ";
		cin >> input;
		getline(cin, input);
		/*MergedSort<University> mergeSortClass;
		mergeSortClass.mergeSort(&(univDLL.head), attribute);*/
		University* found = binarySearch(univDLL.head, input);
		/*cout << left << setw(10) << "Rank"
			<< setw(50) << "Institution"
			<< setw(10) << "Location" << endl;*/
		if (found != NULL) {
			cout << "Rank: " << found->rank << endl;
			cout << "Univ: " << found->institution << endl;
			cout << "Loct: " << found->Location << endl;
		}
	}
	else if (option == 2) {
		string attribute;
		attribute == "institution" ;
		cout << "Enter what to search: ";
		cin >> input;
		//getline(cin, input);
		MergedSort<University> mergeSortClass;
		mergeSortClass.mergeSort(&(univDLL.head), attribute);
		University* found = binarySearch(univDLL.head, input);
		/*cout << left << setw(10) << "Rank"
			<< setw(50) << "Institution"
			<< setw(10) << "Location" << endl;*/
		if (found != NULL) {
			cout << "Rank: " << found->rank << endl;
			cout << "Univ: " << found->institution << endl;
			cout << "Loct: " << found->Location << endl;
		}
	}
	else if (option == 3) {
		string attribute;
		attribute = "location" ;
		cout << "Enter what to search: ";
		//getline(cin, input);
		cin >> input;
		MergedSort<University> mergeSortClass;
		mergeSortClass.mergeSort(&(univDLL.head), attribute);
		auto start = high_resolution_clock::now();
		University* found = binarySearch(univDLL.head, input);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by linear search algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
		cout << left << setw(10) << "Rank"
				<< setw(50) << "Institution"
				<< setw(10) << "Location" << endl;
		if (found != NULL) {
			cout << left << setw(10) << found->rank
				<< setw(50) << found->institution
				<< setw(10) << found->Location << endl;

			cout << "Rank: " << found->rank << endl;
			cout << "Univ: " << found->institution << endl;
			cout << "Loct: " << found->Location << endl;
		}
	}
	
	/*cout << "Enter what to search: ";
	getline(cin, input);
	MergedSort<University> mergeSortClass;
	mergeSortClass.mergeSort(&(univDLL.head), input);*/


	
	else {
		cout << "Error" << endl;
	}
}

void University::Lin_Search() {


	string data,input;
	int opt;
	cout << "Enter what to search: " << endl;
	cout << "1. Rank" << endl;
	cout << "2. Institution" << endl;
	cin >> opt;
		cout << "Enter what to search: " << endl;
		cin >> data;
		cout << "disini" << endl;
		auto start = high_resolution_clock::now();

		LinearSearch<University> linearSearchClass;
		// TODO: tolong ganti terniary operatornya jadi input bukan pake opt lagi
		University* found = linearSearchClass.linearSearch(univDLL.head, data, (opt == 1) ? "rank" : "institution");
		// University* found = linearSearch<University>(univDLL.head, data,input);

		found->display();
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by linear search algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
		if (found != NULL) {
			switch (opt)
			{
			case 1:
				cout << "Rank: " << found->rank << endl;
				input == "rank";
				break;
			case 2:
				cout << "Institution " << found->institution << endl;
				input == "instituion";
				break;
			}
		}
		else {
			cout << "Error" << endl;
		}

}

class Users {
public:
	string ID;
	string name;
	string password;
};


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
	void menu(RegisteredUsers* users, University* univ);
	void user_register();
	RegisteredUsers* login(string ID, string password);
	string generateID();
	void insertToList(string ID, string name, string password, string lastactivedate);
	void writeData(RegisteredUsers* users);
	void deleteFromList(string ID, int position);
	void search(string ID);
	void feedback();
	void Regis_InsertionSort(string attribute);
	void Regis_MergeSort(string attribute);
	bool compareAttributes(RegisteredUsers* otherRegisteredUser, string attribute);
	void feedback(string ID, string name, University* univ);
	void favorite(string ID, string name, University* univ);
	void insertToFile();
	string getValueOf(string input);
};

void RegisteredUsers::insertToFile() {
	ofstream file_new("RegisUsers.csv");

	if (file_new.is_open()) {
		RegisteredUsers* current = regisDLL.head;
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
void RegisteredUsers::feedback(string ID, string name, University* univ) {
	int univ_chosen;
	string feedback;
	Feedback* feed = new Feedback();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Choose the university based on the rank number: ";
	cin >> univ_chosen;
	cout << "What's your feedback?";
	getline(cin, feedback);
	University* current = univ->univDLL.head;
	
	while (current != NULL) {
		if (univ_chosen==current->ArRank) {
			cout << "TES" << endl;
			cout << current->institution << endl;
			feed->InsertFeedback(ID, name, current->institution, feedback);
		}
		current = current->nextAdd;
	}
}
void RegisteredUsers::favorite(string ID, string name, University* univ) {

	int univ_chosen;
	Favorite* fav = new Favorite();

	cout << "Choose the university based on the rank number: ";
	cin >> univ_chosen;
	University* current = univ->univDLL.head;
	while (current != NULL) {
		if (univ_chosen == current->ArRank) {
			fav->insertToFavorite(ID, name, current->institution);
		}
		current = current->nextAdd;
	}


}
void RegisteredUsers::insertToList(string ID, string name, string password, string lastactivedate) {
	RegisteredUsers* newnode = new RegisteredUsers(ID, name, password, lastactivedate);
	regisDLL.insertEnd(newnode);
}
void RegisteredUsers::writeData(RegisteredUsers* users) {
	FILE* fp = fopen("Users.csv", "w");
	
}
void RegisteredUsers::menu(RegisteredUsers* users, University* univ) {
	int opt;
	bool is_sort, is_chosen;
	do
	{
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
			cout << "This is search" <<endl;
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
							univ->displayUniversityInfo();
							is_chosen = true;
							break;
						case 2:
							univ->Univ_InsertionSort("ArScore");
							univ->displayUniversityInfo();
							is_chosen = true;
							break;
						case 3:
							univ->Univ_InsertionSort("FsrScore");
							univ->displayUniversityInfo();
							is_chosen = true;
							break;
						case 4:
							univ->Univ_InsertionSort("ErScore");
							univ->displayUniversityInfo();
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
				favorite(users->ID, users->name, univ);
				break;
			case 3:
				feedback(users->ID, users->name, univ);
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
	else if(regisDLL.head != NULL) {
		
			string lastID = regisDLL.tail->ID.substr(2, 4); 
			int lastDigit = stoi(lastID);
			std::stringstream buffer;
			buffer << "US" << setw(4) << setfill('0') << lastDigit + 1;
			string newID = buffer.str();
			return newID;
		
	}
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
}

string RegisteredUsers::getValueOf(string input) {
	if (input == "userId") {
		return this->ID;
	}
}

void RegisteredUsers::Regis_InsertionSort(string attribute) {
	// regisDLL.head = insertionSort(regisDLL.head, attribute);
}
void RegisteredUsers::Regis_MergeSort(string attribute) {
	auto start = high_resolution_clock::now();

	MergedSort<RegisteredUsers> mergeSortClass;
	mergeSortClass.mergeSort(&(regisDLL.head), attribute);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by merge sort algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}

void RegisteredUsers::user_register() {
	//cout << regisDLL.tail->ID << endl;
	string ID = generateID();
	string name, password, lastActiveDate;
	// current date/time based on current system
	time_t now = time(NULL);

	// convert now to string form
	char* dt = ctime(&now);
	dt[strlen(dt) - 1] = '\0';
	lastActiveDate = dt;
	cout << "Enter your name: ";
	getline(cin, name);

	cout << "Enter your password: ";
	getline(cin, password);
	//std::ios::app
	
	RegisteredUsers* newnode = new RegisteredUsers(ID, name, password, lastActiveDate);
	regisDLL.insertEnd(newnode);
}


RegisteredUsers* RegisteredUsers::login(string ID, string password) {
	RegisteredUsers* current = regisDLL.head;
	while (current != NULL) {
		if (ID == current->ID && password == current->password) {
			cout << "Hello " << current->name << endl;
			// current date/time based on current system
			time_t now = time(NULL);

			// convert now to string form
			char* dt = ctime(&now);
			current->lastActiveDate = dt;

			return current;
		}
		current = current->nextAdd;
	}
	cout << "User not found!" << endl;
	return NULL;
}

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
	void menu(Admin* admin, RegisteredUsers* regis) {
		int opt;
		do
		{
			cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
			cout << "Select the option below: " << endl;
			cout << " 1. Manage Users" << endl;
			cout << " 2. Manage Feedback" << endl;
			cout << " 3. Reply to Feedback" << endl;
			cout << " 4. Generate Report" << endl;
			cout << " 5. Logout" << endl;
			cout << " 6. Exit" << endl;
			cin >> opt;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (opt)
			{
			case 1:
				cout << "Manage User Menu" << endl;
				break;
			case 2:
				cout << "Manage Feedback Menu" << endl;
				break;
			case 3:
				cout << "Reply to Feedback Menu" << endl;
				break;
			case 4:
				cout << "Generate Report" << endl;
				break;
			case 5:
				cout << "Logout" << endl;
				break;
			case 6:
				exit(0);
			default:
				cout << "Invalid input, please try again" << endl;
				break;
			}
		}

		while (opt != 4);
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

		while (is_sort)
		{
			cout << "Which sorting algorithm will you choose?" << endl;
			cout << "1. Insertion Sort" << endl;
			cout << "2. Merge Sort" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				regis;
				cout << "This is insertion sort" << endl;
				is_sort = true;
			case 2:
				regis;
				cout << "This is merge sort" << endl;
				is_sort = true;
			default:
				break;
			}
		}
		regis;
	}
	// delete user
	void deleteRegisUser(string ID, RegisteredUsers* regis) {

		LinearSearch<RegisteredUsers> linearSearchClass;
		RegisteredUsers* users = linearSearchClass.linearSearch(regis->head, ID, "userId");
		// RegisteredUsers* users = linearSearch<RegisteredUsers>(regis->head, ID, "userId");

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
	void modifyUsers() {
	}
};

int menu(University* univ, RegisteredUsers* regis)
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
			regis->user_register();
			regis->menu(regis, univ);
			break;
		case 2:
			cout << "Enter your ID: ";
			getline(cin, ID);
			cout << "Enter your password: ";
			getline(cin, password);
			Log_User = regis->login(ID, password);
			if (Log_User != NULL) {
				regis->menu(Log_User, univ);
			}
			return 0;
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
				cout << "ini lin " << endl;
				univ->Lin_Search();
				cout << "ini 2lin " << endl;
				//stat = true;
				break;
			default:
				cout << "Invalid Option" << endl;
				break;
			}
	

		case 5:
			cout << "Thank you for using this program!" << endl;
			regis->insertToFile();
			exit(0);
		default:
			cout << "Invalid input, please try again" << endl;
			break;
		}
	}
	while(opt != 5);
  
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
		
	void exit_file() {
		RegisteredUsers* current = new RegisteredUsers();
		Feedback* feed = new Feedback();
		Favorite* fav = new Favorite();
		current->insertToFile();
		feed->InsertToFile();
		fav->insertToFile();

	}
	int main()
	{
		
		string rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore,
			CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled;
		string ID, name, password, lastactivedate;
		int counter = 0;
		University *univ = new University();
		RegisteredUsers* regis = new RegisteredUsers();
		fstream file("2023 QS World University Rankings.csv",ios::in);
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
		
		
		menu(univ, regis);
		exit_file();
}


