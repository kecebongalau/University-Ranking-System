#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class University
{
	University* head; University* tail;
public:
	int rank;
	string institution;
	string LocationCode;
	string Location;
	int ArScore;
	int ArRank;
	int ErScore;
	int ErRank;
	int FsrScore;
	int FsrRank;
	int CpfScore;
	int CpfRank;
	int IfrScore;
	int IfrRank;
	int IsrScore;
	int IsrRank;
	int IrnScore;
	int IrnRank;
	int GerScore;
	int GerRank;
	int ScoreScaled;
	University* nextAdd;
	University* prevAdd;
	
	University(int rank, string instituion, string LocationCode, string Location, int ArScore, int ArRank,
		int ErScore, int ErRank, int FsrScore, int FsrRank, int CpfScore, int CpfRank, int IfrScore, int IfrRank, int IsrScore,
		int IsrRank, int IrnSCore, int IrnRank, int GerScore, int GerRank, int ScoreScaled) {

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



	void insertToEndList(int rank, string instituion, string LocationCode, string Location, int ArScore, int ArRank,
		int ErScore, int ErRank, int FsrScore, int FsrRank, int CpfScore, int CpfRank, int IfrScore, int IfrRank, int IsrScore,
		int IsrRank, int IrnSCore, int IrnRank, int GerScore, int GerRank, int ScoreScaled);
	void search();
};

void University::insertToEndList(int rank, string instituion, string LocationCode, string Location, int ArScore, int ArRank,
	int ErScore, int ErRank, int FsrScore, int FsrRank, int CpfScore, int CpfRank, int IfrScore, int IfrRank, int IsrScore,
	int IsrRank, int IrnSCore, int IrnRank, int GerScore, int GerRank, int ScoreScaled) 
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

class Admin : public RegisteredUsers {
public: 
	Admin(string ID, string name, string password) {
		this->ID = ID;
		this->name = name;
		this->password = password;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
	}

	bool login();
	void logout();
	void insertToEndList(string ID, string name, string password, string lastActiveDate);
	void deleteFromList(string ID, int position);
	void search(string ID);
	void replyFeedback();
	void summarize();
};

int main() {
	ifstream file("2023 QS World University Rankings.csv");
	string rank, institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, 
		CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled;
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
		getline(file, ScoreScaled, ',');
	}
	return 0;
}

//tes tes lagi coba 
