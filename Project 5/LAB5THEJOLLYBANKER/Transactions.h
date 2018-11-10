#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transactions
{
	friend istream& operator>>(istream &inStream, Transactions &rhs);
	friend ostream& operator<<(ostream &outStream, Transactions &rhs);

public:
	Transactions();
	~Transactions();

	char getTransType();

	string getLastName();
	string getFirstName();
	bool getSuccess();
	void setSuccess(bool success);
	
	int getId();
	int getId2();
	int getAmount();

	void setId(int id);
	void setId2(int id2);
	void setTransType(char transType);
	void setAmount(int amount);

	
private:
	char transType;
	string firstName;
	string lastName;
	bool success;
	int id;
	int id2;
	int amount;
};

