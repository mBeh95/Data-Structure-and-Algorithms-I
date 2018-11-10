#include "stdafx.h"
#include "Fund.h"


Fund::Fund()
{
	money = 0;
}

Fund::~Fund()
{

}

int Fund::getMoney()
{
	return money;
}

string Fund::setFundName(string name)
{
	this->name = name;
	return name;
}

string Fund::getFundName()
{
	return name;
}


bool Fund::RecordTransaction(Transactions copy)
{
	Transactions temp = copy;
	history.push_back(temp);
	return true;
}


void Fund::PrintHistory()
{

	if (history.size() == 0)
	{
		return;
	}
	else
	{
		cout << getFundName() << ": $" << getMoney() << endl;
		for (int i = 0; i < history.size(); i++)
		{
			cout << " " << history[i];
		}
	}


}

void Fund::PrintHistoryOfFund()
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << " " << history[i];
	}
}

bool Fund::Withdraw(int amount)
{
	money -= amount;
	return true;
}
bool Fund::Deposit(int amount)
{
	money += amount;
	return true;
}

