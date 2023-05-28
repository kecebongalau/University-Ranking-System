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
class Feedback {
public:
	string feedbackID;
	string userID;
	string userName;
	string institution;
	string feedback;
	string feedbackDate;
	string reply; // for admin
	string replyDate;
	Feedback* nextAdd;
	Feedback* prevAdd;
	DoubleLinkedList<Feedback> feedDLL;

	Feedback() {
		this->feedbackID = "";
		this->userID = "";
		this->userName = "";
		this->institution = "";
		this->feedback = "";
		this->feedbackDate = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
		this->reply = "";
		this->replyDate = "";

	}
	Feedback(string feedbackID, string userID, string userName, string institution, string feedback, string feedbackDate, string reply, string replyDate) {
		this->feedbackID = feedbackID;
		this->userID = userID;
		this->userName = userName;
		this->institution = institution;
		this->feedback = feedback;
		this->feedbackDate = feedbackDate;
		this->nextAdd = NULL;
		this->prevAdd = NULL;
		this->reply = "N/A";
		this->replyDate = "N/A";

	}
	string generateID() {
		if (feedDLL.head == NULL) {
			string newID = "FE0001";
			return newID;
		}
		else if (feedDLL.head != NULL) {

			string lastID = feedDLL.tail->feedbackID.substr(2, 4);
			int lastDigit = stoi(lastID);
			std::stringstream buffer;
			buffer << "FE" << setw(4) << setfill('0') << lastDigit + 1;
			string newID = buffer.str();
			return newID;

		}
	}
	void setReplyDate(string replyDate) {
		this->replyDate = replyDate;
	}

	string getReplyDate() {
		return this->replyDate;
	}
	void setReply(string reply) {
		this->reply = reply;
	}
	string getReply() {
		return this->reply;
	}
	void InsertFeedback(string userID, string userName, string institution, string feedback) {
		string feedbackID = generateID();
		// current date/time based on current system
		time_t now = time(NULL);
		tm* ltm = localtime(&now);

		std::stringstream buffer;
		buffer << 1900 + ltm->tm_year << '/' << setw(2) << setfill('0') << ltm->tm_mon + 1 << '/' <<
			setw(2) << setfill('0') << ltm->tm_mday << ' ' << setw(2) << setfill('0') << ltm->tm_hour << ':' <<
			setw(2) << setfill('0') << ltm->tm_min << ':' << setw(2) << setfill('0') << ltm->tm_sec;
		string feedbackDate = buffer.str();
		InsertToList(feedbackID, userID, userName, institution, feedback, feedbackDate, this->reply, this->replyDate);

	}
	void InsertToList(string feedbackID, string userID, string userName, string institution, string feedback, string feedbackDate, string reply, string replyDate) {

		Feedback* newnode = new Feedback(feedbackID, userID, userName, institution, feedback, feedbackDate, reply, replyDate);
		feedDLL.insertEnd(newnode);
		cout << "This id ID: " << feedDLL.head->feedbackID << endl;
		cout << "Thid is feedback: " << feedDLL.head->feedback << endl;

	}
	void InsertToFile() {
		ofstream file("Feedback.csv");
		cout << "Feedback: " << feedDLL.head->feedback << endl;
		if (file.is_open()) {
			Feedback* current = feedDLL.head;
			cout << current->feedback << endl;
			while (current != NULL) //means still not the end of the list
			{
				cout << "Feedback ID: " << current->feedbackID << endl;
				cout << "User ID: " << current->userID << endl;
				cout << "User Name: " << current->userName << endl;
				cout << "Institution: " << current->institution << endl;
				cout << "Feedback: " << current->feedback << endl;
				cout << "Feedback Date: " << current->feedbackDate << endl;
				cout << "Reply: " << current->reply << endl;
				cout << "Reply Date: " << current->replyDate << endl << endl;

				file << current->feedbackID << ',';
				file << current->userID << ',';
				file << current->userName << ',';
				file << current->institution << ',';
				file << current->feedback << ',';
				file << current->feedbackDate << ',';
				file << current->reply << ',';
				file << current->replyDate << endl;

				current = current->nextAdd; //if you forgot this, will become a infinity loop
			}
			cout << "List is ended here! " << endl;
		}
		file.close();
	}
	bool compareAttributes(Feedback * otherFeedback, string attribute) {
		if (attribute == "feedbackDate")
		{
			return (feedbackDate.compare(otherFeedback->feedbackDate) <= 0);
		}
		return false;
	}
	void mergeSort(string attribute) {
		auto start = high_resolution_clock::now();

		MergedSort<Feedback> mergeSortClass;
		mergeSortClass.mergeSort(&(feedDLL.head), attribute);

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by merge sort algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
	}
	void display() {
		cout << this->feedbackID << " " <<  this->feedbackDate << endl;
	}
	void displayAll() {
		feedDLL.displayAll();
	}
	string getValueOf(string input) {
		if (input == "feedbackId")
		{
			return this->feedbackID;
		}
	}
};