#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace std::chrono;

class Users {
public:
	string ID;
	string name;
	string password;
};