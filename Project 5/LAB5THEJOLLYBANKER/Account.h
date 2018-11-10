#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Fund.h"
#include "Transactions.h"
using namespace std;

class Account
{
public:
	Account();
	Account(string firstName, string lastName, int id);
	~Account();


	string getLastName();
	string getFirstName();
	int getId();

	void Print();

	void RecordTransHistory(Transactions copy, int fundType);

	void AccountHistory(int id);

	bool Withdraw(int fundType, int amount);
	bool Deposit(int fundType, int amount);
	bool isEmpty(int fundType);

	bool operator<(const Account& rhs) const;

private:
	vector <string> transHistory;
	string firstName;
	string lastName;
	Fund fund[10];
	int amount;
	int id;

};

