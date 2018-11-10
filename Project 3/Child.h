#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List342.h"
using namespace std;
class Child
{
public:
	Child();
	Child(string lName, string fName, int age);
	~Child();

	string getLastName() const;
	bool operator==(const Child &rhs) const;
	bool operator!=(const Child &rhs) const;
	bool operator<(const Child &rhs) const;

	friend ostream& operator<<(ostream &outStream, const Child &rhs);

private:
	string lastName;
	string firstName;
	int age;

};

