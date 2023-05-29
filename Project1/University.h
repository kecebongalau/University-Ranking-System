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
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace std::chrono;
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
	void Cust_LinSearch();
	void Univ_InsertionSort(string data);
	void Univ_MergedSort(string attribute);
	void displayUniversityInfo();
	// Needed for display
	void display();

	// Needed for sort
	bool compareAttributes(University* otherUniversity, string attribute);

	// Needed for search
	string getValueOf(string input);

	// Need for search (double)
	double getDoubleValueOf(string input);
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
	mergeSortClass.mergeSort(&(univDLL.head), attribute, false);
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
		new_CpfScore = stod(CpfScore);
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
		return (ArScore <= otheruniversity->ArScore);
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
		return (CpfRank <= otheruniversity->CpfRank);
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
	else if (input == "Location")
	{
		return this->Location;
	}
	else if (input == "Location_Code")
	{
		return this->LocationCode;
	}
}

double University::getDoubleValueOf(string input) {
	if (input == "ArScore") {
		cout << this->ArScore << endl;
		return this->ArScore;
	}
	else if (input == "ErScore") {
		return this->ErScore;
	}
	else if (input == "FsrScore") {
		return this->FsrScore;
	}
	else if (input == "CpfScore") {
		return this->CpfScore;
	}
	else if (input == "IfrScore") {
		return this->IfrScore;
	}
	else if (input == "IsrScore") {
		return this->IsrScore;
	}
	else if (input == "IrnScore") {
		return this->IrnScore;
	}
	else if (input == "GerScore") {
		return this->GerScore;
	}
	else if (input == "ScoreScaled") {
		return this->ScoreScaled;
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

void University::Bin_Search() {
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

	string input, attribute;
	int option;
	cout << "Binary Search Option: " << endl;
	cout << " 1. Rank " << endl;
	cout << " 2. Institution " << endl;
	cout << "Option: ";
	cin >> option;
	cin.clear();
	if (option == 1) {
		attribute = 'rank';
		cout << "Enter what to search: ";
		cin >> input;
		/*getline(cin, input);*/
		MergedSort<University> mergeSortClass;
		mergeSortClass.mergeSort(&(univDLL.head), attribute);
		auto start = high_resolution_clock::now();
		University* found = binarySearch(univDLL.head, input, "rank");
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by binary search algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
		
		if (found != NULL) {
			cout << "Rank: " << found->rank << endl;
			cout << "Univ: " << found->institution << endl;
			cout << "Loct: " << found->Location << endl;
		}
	}
	else if (option == 2) {
		string attribute, name;
		attribute = "institution";
		cout << "Enter what to search: ";
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		getline(cin, name);
		
		//cin.ignore();
		
		//cin.getline(nama,50);

		//cin >> input;
		cout << name << endl;

		MergedSort<University> mergeSortClass;
		mergeSortClass.mergeSort(&(univDLL.head), attribute);
		auto start = high_resolution_clock::now();
		University* found = binarySearch(univDLL.head, name, "institution");
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by binary search algorithm: ";
		cout << duration.count() << " microseconds. " << endl;

		/*cout << left << setw(10) << "Rank"
			<< setw(50) << "Institution"
			<< setw(10) << "Location" << endl;*/
		if (found != NULL) {
			cout << "Rank: " << found->rank << endl;
			cout << "Univ: " << found->institution << endl;
			cout << "Loct: " << found->Location << endl;
		}
		else {
			cout << "ERROR" << endl;
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

	string data, input;
	int opt;
	cout << "Enter what to search: " << endl;
	cout << "1. Rank" << endl;
	cout << "2. Institution" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
		input = "rank";
		break;
	case 2:
		input = "institution";
		break;
	default:
		break;
	}
	LinearSearch<University> linearSearchClass;
	cout << "Enter what to search: " << endl;
	cin.ignore();
	getline(cin, data);
	auto start = high_resolution_clock::now();
	linearSearchClass.linearSearch(univDLL.head, data, input);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds> (stop - start);
	cout << "Time taken by linear search algorithm: ";
	cout << duration.count() << " microseconds. " << endl;
}

void University::Cust_LinSearch() {
	string data, input;
	int opt;
	double lowerRange, upperRange;
	cout << "Enter what to search: " << endl;
	cout << "1. Rank" << endl;
	cout << "2. Institution" << endl;
	cout << "3. Location" << endl;
	cout << "4. Location Code" << endl;
	cout << "5. Academic Reputation Score" << endl;
	cout << "6. Employer Reputation Score" << endl;
	cout << "7. Faculty/Student Ratio Score" << endl;
	cout << "8. Citation per Faculty Score" << endl;
	cout << "9. International Faculty Ratio Score" << endl;
	cout << "10. International Student Ratio Score" << endl;
	cout << "11. International Research Network Score" << endl;
	cout << "12. Employment Outcome Score" << endl;
	cout << "13. Score Scaled" << endl;
	cin >> opt;
	LinearSearch<University> linearSearchClass;
	if (opt <= 4) {
		switch (opt)
		{
		case 1:
			input = "rank";
			break;
		case 2:
			input = "institution";
			break;
		case 3:
			input = "Location";
			break;
		case 4:
			input = "Location_Code";
		default:
			break;
		}
		cout << "Enter what to search: " << endl;
		cin.ignore();
		getline(cin, data);
		auto start = high_resolution_clock::now();
		linearSearchClass.linearSearch(univDLL.head, data, input);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by linear search algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
	}

	else if (5 <= opt  && opt<= 13) {
		switch (opt)
		{
		case 5:
			input = "ArScore";
			break;
		case 6:
			input = "ErScore";
			break;
		case 7:
			input = "FsrScore";
			break;
		case 8:
			input = "CpfScore";
			break;
		case 9:
			input = "IfrScore";
			break;
		case 10:
			input = "IsrScore";
			break;
		case 11:
			input = "IrnScore";
			break;
		case 12:
			input = "GerScore";
			break;
		case 13:
			input = "ScoreScaled";
			break;
		default:
			break;
		}
		cout << "Enter Minimal value: " << endl;
		cin >> lowerRange;
		cout << "Enter Maximal value: " << endl;
		cin >> upperRange;
		cout << "Input: " << input << endl;
		auto startScore = high_resolution_clock::now();
		linearSearchClass.linearSearchScore(univDLL.head, lowerRange, upperRange, input);
		auto stopScore = high_resolution_clock::now();
		auto durationScore = duration_cast<microseconds> (stopScore - startScore);
		cout << "Time taken by linear search algorithm: ";
		cout << durationScore.count() << " microseconds. " << endl;
	}
}