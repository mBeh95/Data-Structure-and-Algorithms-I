#include "stdafx.h"
#include "Bank.h"


Bank::Bank()
{
	
}


Bank::~Bank()
{
}

void Bank::ReadTransactionFromFile(string filename)
{
	ifstream input;
	Transactions object;
	input.open(filename);
	while (!input.eof())
	{
		input >> object;
		fileTransactions.push(object);
	}
	ExecuteTransactions();
}
void Bank::ExecuteTransactions()
{
	while (fileTransactions.size() != NULL)
	{
		
		if (fileTransactions.front().getTransType() == 'O')
		{
			Open(fileTransactions.front().getFirstName(), fileTransactions.front().getLastName(), fileTransactions.front().getId());
		}
		else if (fileTransactions.front().getTransType() == 'D')
		{
			Deposit(fileTransactions.front().getId(), fileTransactions.front().getAmount());
		}
		else if (fileTransactions.front().getTransType() == 'T')
		{
			Transfer(fileTransactions.front().getId(), fileTransactions.front().getId2(), fileTransactions.front().getAmount());
		}
		else if (fileTransactions.front().getTransType() == 'W')
		{
			Withdraw(fileTransactions.front().getId(), fileTransactions.front().getAmount());
		}
		else if (fileTransactions.front().getTransType() == 'H')
		{
			History(fileTransactions.front().getId());
		}
		
		
		fileTransactions.pop();
	}
	
	Display();
}
void Bank::Display()
{
	cout << endl << "Processing Done. Final Balances" << endl;
	client.Display();
}

bool Bank::Withdraw(int id, int amount)
{
	Account *temp;

	string sizeNum = to_string(id);

	int accountNumber = id / 10;
	int fundType = id % 10;
	bool aprove = false;

	if (sizeNum.size() == 5)
	{
		if (client.Retrieve(accountNumber, temp))
		{
			if (temp->Withdraw(fundType, amount) == true)
			{
				aprove = true;
				fileTransactions.front().setSuccess(aprove);
				temp->RecordTransHistory(fileTransactions.front(), fundType);
				return true;
			}
			else
			{
				aprove = false;
				fileTransactions.front().setSuccess(aprove);
				temp->RecordTransHistory(fileTransactions.front(), fundType);
				return true;
			}
		}
		else
		{
			cerr << "ERROR: Account " << accountNumber << " not found. Transferal refused." << endl;
			aprove = false;
			fileTransactions.front().setSuccess(aprove);
			temp->RecordTransHistory(fileTransactions.front(), fundType);
			return false;
		}
	}
	else
	{
		cerr << "ERROR: Fund of " << accountNumber << " not found. Transferal refused." << endl;
		return false;
	}

	
	return true;
	
}
bool Bank::Open(string firstName, string lastName, int id)
{

	Account *newClient = new Account(firstName, lastName, id);

	string idCheck = to_string(id);

	if (idCheck.size() == 4)
	{
		if (client.Retrieve(id, newClient))
		{
			cerr << "ERROR: Account " << id << " is already open. Transaction refused." << endl;
			return false;
		}
		else
		{
			client.Insert(newClient);
			return true;
		}
	}
	else
	{
		cerr << "ERROR: Account " << id << " not a 4 digit number. Transaction refused." << endl;
		return false;
	}
}
bool Bank::Deposit(int id, int amount)
{
	Account *temp;
	string sizeNum = to_string(id);
	int accountNumber = id / 10;
	int fundType = id % 10;
	bool aprove = false;

	if (sizeNum.size() == 5)
	{
		if (client.Retrieve(accountNumber, temp))
		{
			temp->Deposit(fundType, amount);
			aprove = true;
			fileTransactions.front().setSuccess(aprove);
			temp->RecordTransHistory(fileTransactions.front(), fundType);
			return true;
		}
		else
		{
			cerr << "ERROR: Account " << id << " not found. Transferal refused." << endl;
			aprove = false;
			fileTransactions.front().setSuccess(aprove);
			temp->RecordTransHistory(fileTransactions.front(), fundType);
			return false;
		}
	}
	else
	{
		cerr << "ERROR: Fund of " << accountNumber << " not found. Transferal refused." << endl;
		return false;
	}

	
	return true;
	
}
bool Bank::Transfer(int sId, int dId, int amount)
{
	Account *giveTemp;
	Account *recieveTemp;
	string sizeNum1 = to_string(sId);
	string sizeNum2 = to_string(dId);
	int giveAccountNumber = sId / 10;
	int recieveAccountNumber = dId / 10;
	int giveFund = sId % 10;
	int recieveFund = dId % 10;
	bool aprove = false;

	if ((sizeNum1.size() == 5) && (sizeNum2.size() == 5))
	{
		if ((client.Retrieve(giveAccountNumber, giveTemp)) && (client.Retrieve(recieveAccountNumber, recieveTemp)))
		{
			if (giveTemp->Withdraw(giveFund, amount) == true)
			{
				recieveTemp->Deposit(recieveFund, amount);
				aprove = true;
				fileTransactions.front().setSuccess(aprove);
				giveTemp->RecordTransHistory(fileTransactions.front(), giveFund);
				recieveTemp->RecordTransHistory(fileTransactions.front(), recieveFund);
				return true;
			}
			else
			{
				cerr << "ERROR: Not enough funds in " << giveAccountNumber << " transferel refused." << endl;
				aprove = false;
				fileTransactions.front().setSuccess(aprove);
				giveTemp->RecordTransHistory(fileTransactions.front(), giveFund);
				recieveTemp->RecordTransHistory(fileTransactions.front(), recieveFund);
				return false;
			}
		}
		else
		{
			cerr << "ERROR: One or more Accounts not found. Transferal refused." << endl;
			return false;
		}
	}
	else
	{
		cerr << "ERROR: Fund of one or more accounts not found. Transferal refused." << endl;
		return false;
	}
}

void Bank::History(int id)
{
	Account *temp;
	string sizeNum = to_string(id);
	int accountNumber = id / 10;
	
	if (sizeNum.size() == 5)
	{
		if (client.Retrieve(accountNumber, temp))
		{
			temp->AccountHistory(id);
		}
	}
	else if (sizeNum.size() == 4)
	{
		if (client.Retrieve(id, temp))
		{
			temp->AccountHistory(id);
		}
	}
	else
	{
		cerr << "ERROR: Account "<< id <<" not found. History is refused." << endl;
	}

}


