#pragma once
#include <string>

// Just to make the intellisense work for template

class HelperNode
{
public:
	HelperNode* nextAdd;
	HelperNode* prevAdd;
	bool compareAttributes(HelperNode * otherNode, string attribute);
	string getValueOf(string attributes) {
	}
	HelperNode() {
	};
	~HelperNode() {
	};

private:
	void display() {
	};
};
