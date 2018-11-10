#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List342.h"
using namespace std;
class Bird
{
public:
	Bird();
	~Bird();

	string getName() const;
	bool operator==(const Bird &rhs) const;
	bool operator!=(const Bird &rhs) const;
	bool operator<(const Bird &rhs) const;

	friend ostream& operator<<(ostream &outStream, const Bird &rhs);
private:
	string name;
	int id;
};

