#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "SingleLinkedList.h"
#include "InsertionSort.h"
#include "DoubleLinkedList.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

class University
{
	University* head; University* tail;
public:
	string rank;
	string institution;
	string LocationCode;
	string Location;
	string ArScore;
	string ArRank;
	string ErScore;
	string ErRank;
	string FsrScore;
	string FsrRank;
	string CpfScore;
	string CpfRank;
	string IfrScore;
	string IfrRank;
	string IsrScore;
	string IsrRank;
	string IrnScore;
	string IrnRank;
	string GerScore;
	string GerRank;
	string ScoreScaled;
	University* nextAdd;
	University* prevAdd;
	SingleLinkedList<University> univSLL;

	University(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled) {

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
		this->rank = "";
		this->institution = "";
		this->LocationCode = "";
		this->Location = "";
		this->ArScore = "";
		this->ArRank = "";
		this->ErScore = "";
		this->ErRank = "";
		this->FsrScore = "";
		this->FsrRank = "";
		this->CpfScore = "";
		this->CpfRank = "";
		this->IfrScore = "";
		this->IfrRank = "";
		this->IsrScore = "";
		this->IsrRank = "";
		this->IrnScore = "";
		this->IrnRank = "";
		this->GerScore = "";
		this->GerRank = "";
		this->ScoreScaled = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}



	void insertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled);
	void search();
	void Univ_InsertionSort();
	void displayUniversityInfo();
	void display();
};

void University::Univ_InsertionSort() {
	univSLL.head = insertionSort(univSLL.head, "institution");
}

void University::insertToEndList(string rank, string institution, string LocationCode, string Location, string ArScore, string ArRank,
	string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
	string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled) 
{
	
	University* newnode = new University(rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank,
		FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnSCore, IrnRank, GerScore, GerRank,
		ScoreScaled);
	/*if (head == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->nextAdd= newnode;
		newnode->prevAdd = tail;
		tail = newnode;
	}*/
	univSLL.insertEnd(newnode);

	
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
	cout << univSLL.head->institution << endl;
	univSLL.displayAll();
}

class Users {
public:
	string ID;
	string name;
	string password;
};


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
	void menu(Admin* admin, DoubleLinkedList<RegisteredUsers> regisDLL) {
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
};
void RegisteredUsers::insertToList(string ID, string name, string password, string lastactivedate) {
	RegisteredUsers* newnode = new RegisteredUsers(ID, name, password, lastactivedate);
	regisDLL.insertEnd(newnode);
}
void RegisteredUsers::writeData(RegisteredUsers* users) {
	FILE* fp = fopen("Users.csv", "w");
	
}
void RegisteredUsers::menu(RegisteredUsers* users, University* univ) {
	int opt;
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
			univ->Univ_InsertionSort();
			univ->displayUniversityInfo();
			break;
		case 3:
			cout << "This will be feedback" << endl;

			break;
		case 4:
			break;

		case 5:
			exit(0);
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
		cout << regisDLL.tail->ID << endl; // ini masi error
		try {
			string lastID = regisDLL.tail->ID.substr(2, 4); // ini juga masi (prev add works some times)
			int lastDigit = stoi(lastID);
			std::stringstream buffer;
			buffer << "US" << setw(4) << setfill('0') << lastDigit + 1;
			string newID = buffer.str();
			return newID;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid argument: " << e.what() << std::endl;
			// handle the error, e.g. return an error code or throw an exception
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Out of range: " << e.what() << std::endl;

			// handle the error, e.g. return an error code or throw an exception
		}
	}
	

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

	ofstream file_new("RegisUsers.csv", std::ios::app);
	RegisteredUsers* newnode = new RegisteredUsers(ID, name, password, lastActiveDate);
	regisDLL.insertEnd(newnode);
	cout << regisDLL.tail->ID << endl;

	if (file_new.is_open()) {
		RegisteredUsers* current = regisDLL.tail;
		while (current != NULL) //means still not the end of the list
		{
			cout << "id: " << current->ID << endl;
			cout << "name: " << current->name << endl;
			cout << "password: " << current->password << endl;
			cout << "last activity date: " << current->lastActiveDate << endl << endl;

			file_new <<  current->ID << ',';
			file_new << current->name << ',';
			file_new << current->password << ',';
			file_new << current->lastActiveDate << endl;

			current = current->nextAdd; //if you forgot this, will become a infinity loop
		}
		cout << "List is ended here! " << endl;
	}
	file_new.close();
	

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
int menu(University* univ, RegisteredUsers* regis)
{
	int opt;
	string ID, password;
	RegisteredUsers* Log_User;
	do
	{
		cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
		cout << "Select the option below: " << endl;
		cout << " 1. Register" << endl;
		cout << " 2. Login" << endl;
		cout << " 3. Show University List" << endl;
		cout << " 4. Exit" << endl;
		cin >> opt;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch(opt)
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
				break;
			case 3:
				univ->displayUniversityInfo();
				break;
			case 4:
				cout << "Thank you for using this program!" << endl;
				exit(0);
			default:
				cout << "Invalid input, please try again" << endl;
				break;
		}
	}

	while(opt != 4);
  
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
		

	int main()
	{
		
		string rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore,
			CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled;
		string ID, name, password, lastactivedate;
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


				univ->insertToEndList(rank, institution, LocationCode, Location, ArScore, ArRank,
					ErScore, ErRank, FsrScore, FsrRank, CpfScore,
					CpfRank, IfrScore, IfrRank, IsrScore,
					IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);
			}
		}
		
		
		file.close();

		ifstream file_regis("RegisUsers.csv", ios::in);
		if (file_regis.is_open()) {
			while (file_regis.good() && !file_regis == NULL) {
				getline(file_regis, ID, ',');
				getline(file_regis, name, ',');
				getline(file_regis, password, ',');
				getline(file_regis, lastactivedate, '\n');
				regis->insertToList(ID, name, password, lastactivedate);
				
			}
			
		}
		file_regis.close();
		
		
		menu(univ, regis);
}


