#include "stdafx.h"
#include "Child.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



Child::Child()
{
}

Child::Child(string fName, string lName, int age)
{
	this->lastName = lName;
	this->firstName = fName;
	this->age = age;
}

Child::~Child()
{
}

string Child::getLastName() const
{
	return lastName;
}

bool Child::operator==(const Child &rhs) const
{
	return (rhs.lastName == lastName) && (rhs.firstName == firstName) && (rhs.age == age);
}

bool Child::operator!=(const Child &rhs) const
{
	return (rhs.lastName != lastName) || (rhs.firstName != firstName) || (rhs.age != age);
}

bool Child::operator<(const Child &rhs) const
{
	return (this->lastName < rhs.lastName);
}
ostream& operator<<(ostream &outStream, const Child &rhs)
{
	outStream << rhs.firstName << rhs.lastName << rhs.age;
	return outStream;
}