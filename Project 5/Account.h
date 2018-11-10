#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Account
{
public:
	Account();
	Account(string firstName, string lastName, int id);
	~Account();

	void setWithdraw(int fund[], int amount);
	void setDeposit(int fund[], int amount);
	void setTransfer(int fund[], int amount);
	void setHistory(int fund[], int amount);

	void getWithdraw(int fund[]);
	void getDeposit(int fund[]);
	void getTransfer(int fund[]);
	void getHistory(int fund[]);

private:
	string firstName;
	string lastName;
	int amount;
	int id;
	int fund[10];
	
};

