// TheJollyBanker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"
using namespace std;


int main()
{
	Bank bank;

	bank.ReadTransactionFromFile("BankTransIn.txt");

	return 0;
}

