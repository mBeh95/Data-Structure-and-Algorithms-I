#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include "BSTree.h"
#include "Transactions.h"
#include "Fund.h"
#include "Account.h"
using namespace std;
class Bank
{
public:
	Bank();
	~Bank();

	void ReadTransactionFromFile(string filename);
	void ExecuteTransactions();
	void Display();

	bool Withdraw(int id, int amount);
	bool Open(string firstName, string lastName, int id);
	bool Deposit(int id, int amount);
	bool Transfer(int sId, int dId, int amount);
	void History(int Id);

private:
	queue <Transactions> fileTransactions;

	BSTree client;
	
	int id;
	int sId; //The id thats transfering
	int dId; // the id recieving the tranfer
};