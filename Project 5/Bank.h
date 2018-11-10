#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "BSTree.h"
using namespace std;
class Bank
{
public:
	Bank();
	~Bank();

	void ReadTransactionFromFile(string filename);
	void ExecuteTransactions();
	void Display();

	bool Withdraw(int id, int fund[], int amount);
	bool Open(string firstName, string lastName, int id, int fund[]);
	bool Deposit(int id, int amount, int fund[]);
	bool Transfer(int sId, int dId, int amount, int fund[]);
	void History(int Id);

	void findFund();

private: 
	queue <string> fileTransactions;
	BSTree client;
	int fund[10];
	string firstName;
	string lastName;
	int amount;
	int id;
	int sId; //The id thats transfering
	int dId; // the id recieving the tranfer
};

