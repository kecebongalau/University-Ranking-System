#include <iostream>
#include <fstream>
#include <string>
#include "SingleLinkedList.h"
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
	
	University(string rank, string instituion, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled) {

		this->rank = rank;
		this->institution = instituion;
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



	void insertToEndList(string rank, string instituion, string LocationCode, string Location, string ArScore, string ArRank,
		string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
		string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled);
	void search();
	void displayUniversityInfo();
	void display();
};

void University::insertToEndList(string rank, string instituion, string LocationCode, string Location, string ArScore, string ArRank,
	string ErScore, string ErRank, string FsrScore, string FsrRank, string CpfScore, string CpfRank, string IfrScore, string IfrRank, string IsrScore,
	string IsrRank, string IrnSCore, string IrnRank, string GerScore, string GerRank, string ScoreScaled) 
{
	University* newnode = new University(rank, instituion, LocationCode, Location, ArScore, ArRank, ErScore, ErRank,
		FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnSCore, IrnRank, GerScore, GerRank,
		ScoreScaled);
	if (head == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->nextAdd= newnode;
		newnode->prevAdd = tail;
		tail = newnode;
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
	University* current = head;
	while (current!=NULL) //means still not the end of the list
	{
		cout << "Rank: " << current->rank << endl;
		cout << "Institution: " << current->institution << endl;
		cout << "Location Code: " << current->LocationCode << endl;
		cout << "Location: " << current->Location << endl;
		cout << "Academic Reputation Score: " << current->ArScore << endl;
		cout << "Academic Reputation Rank: " << current->ArRank << endl;
		cout << "Employer Reputation Score: " << current->ErScore << endl;
		cout << "Employer Reputation Rank: " << current->ErRank << endl;
		cout << "Academic Reputation Rank: " << current->ErRank << endl;
		cout << "Faculty/student ratio Score: " << current->FsrScore << endl;
		cout << "Faculty/student ratio Rank: " << current->FsrRank << endl;
		cout << "Citations per faculty Score: " << current->CpfScore << endl;
		cout << "Citations per faculty Rank: " << current->CpfRank << endl;
		cout << "International faculty ratio Score: " << current->IfrScore << endl;
		cout << "International faculty ratio Rank: " << current->IfrRank << endl;
		cout << "International student ratio Score: " << current->IsrScore << endl;
		cout << "International student ratio Rank: " << current->IsrRank << endl;
		cout << "International research network Score: " << current->IrnScore << endl;
		cout << "International research network Rank: " << current->IrnRank << endl;
		cout << "Employment Outcome Score: " << current->GerScore << endl;
		cout << "Employment Outcome Rank: " << current->GerRank << endl;
		cout << "Score Scaled: " << current->ScoreScaled << endl <<endl;
		current = current->nextAdd; //if you forgot this, will become a infinity loop
	}
	cout << "List is ended here! " << endl;
}


class RegisteredUsers {
public:
	string ID;
	string name;
	string password;
	string lastActiveDate;
	RegisteredUsers* nextAdd;
	RegisteredUsers* prevAdd;
	RegisteredUsers(string ID, string name, string password, string lastActiveDate) {
		this->ID = ID;
		this->name = name;
		this->password = password;
		this->lastActiveDate = lastActiveDate;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	bool login();
	void logout();
	void insertToEndList(string ID, string name, string password, string lastActiveDate);
	void deleteFromList(string ID, int position);
	void search(string ID);
	void feedback();
};

int menu(University* univ)
{
	int opt;
	do
	{
		cout << "WELCOME TO UNIVERSITY RANK SYSTEM" << endl;
		cout << "Select the option below: " << endl;
		cout << " 1. Register" << endl;
		cout << " 2. Login" << endl;
		cout << " 3. Show University List" << endl;
		cout << " 4. Exit" << endl;
		cin >> opt;
		
		switch(opt)
		{
			case 1:
				//register();
				break;
			case 2:
				//login();
				break;
			case 3:
				univ->displayUniversityInfo();
				break;
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
		ifstream file("2023 QS World University Rankings.csv");
		string rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore,
			CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled;
		University *univ = new University();
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

		// univ->displayUniversityInfo();

		menu(univ);
}


