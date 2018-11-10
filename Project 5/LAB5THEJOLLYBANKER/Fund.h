#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transactions.h"
using namespace std;
class Fund
{
	
public:
	Fund();
	~Fund();

	
	int getMoney();


	bool RecordTransaction(Transactions copy);
	void PrintHistoryOfFund();
	void PrintHistory();
	

	bool Withdraw(int amount);
	bool Deposit(int amount);
	bool isEmpty(int fundType);

	string setFundName(string name);
	string getFundName();

private:
	vector<Transactions> history;
	string name;
	int money;

};

