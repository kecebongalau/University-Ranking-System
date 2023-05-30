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
		this->institution = "";
		this->feedback = "";
		this->feedbackDate = "";
		this->nextAdd = NULL;
		this->prevAdd = NULL;
		this->reply = "";
		this->replyDate = "";

	}
	Feedback(string feedbackID, string userID, string institution, string feedback, string feedbackDate, string reply, string replyDate) {
		this->feedbackID = feedbackID;
		this->userID = userID;
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
			feedDLL.head = insertionSort(feedDLL.head, "ID", true);
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
	void InsertFeedback(string userID, string institution, string feedback) {
		string feedbackID = generateID();
		// current date/time based on current system
		time_t now = time(NULL);
		tm* ltm = localtime(&now);

		std::stringstream buffer;
		buffer << 1900 + ltm->tm_year << '/' << setw(2) << setfill('0') << ltm->tm_mon + 1 << '/' <<
			setw(2) << setfill('0') << ltm->tm_mday << ' ' << setw(2) << setfill('0') << ltm->tm_hour << ':' <<
			setw(2) << setfill('0') << ltm->tm_min << ':' << setw(2) << setfill('0') << ltm->tm_sec;
		string feedbackDate = buffer.str();
		InsertToList(feedbackID, userID,institution, feedback, feedbackDate, this->reply, this->replyDate);

	}
	void InsertToList(string feedbackID, string userID, string institution, string feedback, string feedbackDate, string reply, string replyDate) {

		Feedback* newnode = new Feedback(feedbackID, userID, institution, feedback, feedbackDate, reply, replyDate);
		feedDLL.insertEnd(newnode);


	}
	void InsertToFile() {
		ofstream file("Feedback.csv");
		if (file.is_open()) {
			Feedback* current = feedDLL.head;
			while (current != NULL) //means still not the end of the list
			{

				file << current->feedbackID << ',';
				file << current->userID << ',';
				file << current->institution << ',';
				file << current->feedback << ',';
				file << current->feedbackDate << ',';
				file << current->reply << ',';
				file << current->replyDate << endl;

				current = current->nextAdd; //if you forgot this, will become a infinity loop
			}
			cout << "Updating Feedback.csv! " << endl;
		}
		file.close();
	}
	bool compareAttributes(Feedback * otherFeedback, string attribute) {
		if (attribute == "feedbackDate")
		{
			return (feedbackDate.compare(otherFeedback->feedbackDate) <= 0);
		}
		else if (attribute == "ID") {
			return (feedbackID.compare(otherFeedback->feedbackID) <= 0);
		}
		return false;
	}
	void mergeSort(string attribute, bool asc) {
		auto start = high_resolution_clock::now();

		MergedSort<Feedback> mergeSortClass;
		mergeSortClass.mergeSort(&(feedDLL.head), attribute, asc);

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by merge sort algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
	}

	void feed_insertionSort(string attribute, bool asc) {
		auto start = high_resolution_clock::now();
		feedDLL.head = insertionSort(feedDLL.head, attribute, asc);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds> (stop - start);
		cout << "Time taken by insertion sort algorithm: ";
		cout << duration.count() << " microseconds. " << endl;
	}
	void display() {
		cout << left << setw(10) << this->feedbackID << '|';
		cout << setw(10) << this->userID<<'|';
		cout << setw(30) << this->feedback<<'|';
		cout << setw(20) <<this->feedbackDate<< '|';
		cout << setw(30) <<this->reply<<'|';
		cout << setw(20) <<this->replyDate<< '|' << endl;
	}
	void header() {
		cout << left << setw(10) << "Feedback ID" << '|';
		cout << setw(10) << "User ID" << '|';
		cout << setw(30) << "Feedback" << '|';
		cout << setw(20) << "Feedback Date" << '|';
		cout << setw(30) << "Reply" << '|';
		cout << setw(20) << "Reply Date" << '|' << endl;
	}
	void displayAll() {
		feedDLL.displayAll();
	}
	string getValueOf(string input) {
		if (input == "feedbackId")
		{
			return this->feedbackID;
		}
		else if (input == "userID") {
			return this->userID;
		}
	}
};