#include "stdafx.h"
#include "Account.h"


Account::Account()
{
	
}

Account::Account(string firstName, string lastName, int id)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->id = id;

	fund[0].setFundName("Money Market");
	fund[1].setFundName("Prime Money Market");
	fund[2].setFundName("Long-Term Bond");
	fund[3].setFundName("Short-Term Bond");
	fund[4].setFundName("500 Index Fund");
	fund[5].setFundName("Capital Value Fund");
	fund[6].setFundName("Growth Equity Fund");
	fund[7].setFundName("Growth Index Fund");
	fund[8].setFundName("Value Fund");
	fund[9].setFundName("Value Stock Index");


}

Account::~Account()
{
}

string Account::getLastName()
{
	return lastName;
}
string Account::getFirstName()
{
	return firstName;
}
int Account::getId()
{
	return id;
}
bool Account::operator<(const Account& rhs) const
{
	return this->id<rhs.id;
}
bool Account::Withdraw(int fundType, int amount)
{
	int alternateAmount;
	if (fund[fundType].getMoney() < amount)
	{
		if (fundType == 0)
		{
			
			if ((fund[1].getMoney() + fund[fundType].getMoney()) < amount)
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << endl;
				
				return false;
			}
			else
			{
				alternateAmount = amount - fund[fundType].getMoney();


				fund[fundType].Withdraw(fund[fundType].getMoney());
				fund[1].Withdraw(alternateAmount);

				Transactions extra;
				extra.setTransType('T');
				extra.setAmount(alternateAmount);
				extra.setId(getId() * 10 + fundType+1);
				extra.setId2(getId() * 10 + fundType);
				extra.setSuccess(true);

				RecordTransHistory(extra, fundType);
				RecordTransHistory(extra, fundType + 1);
		
				
			}
		
		}
		else if (fundType == 1)
		{
			if ((fund[0].getMoney() + fund[fundType].getMoney()) < amount)
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << endl;
				return false;
			}
			else
			{
				alternateAmount = amount - fund[fundType].getMoney();

				fund[fundType].Withdraw(fund[fundType].getMoney());
				fund[0].Withdraw(alternateAmount);

				Transactions extra;
				extra.setTransType('T');
				extra.setAmount(alternateAmount);
				extra.setId(getId()*10 + fundType-1);
				extra.setId2(getId() * 10 + fundType);
				extra.setSuccess(true);

				RecordTransHistory(extra, fundType);
				RecordTransHistory(extra, fundType-1);
				
			}
		}
		if (fundType == 2)
		{
			if ((fund[3].getMoney() + fund[fundType].getMoney()) < amount)
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << endl;
				return false;
			}
			else
			{
				alternateAmount = amount - fund[fundType].getMoney();


				fund[fundType].Withdraw(fund[fundType].getMoney());
				fund[3].Withdraw(alternateAmount);
				Transactions extra;
				extra.setTransType('T');
				extra.setAmount(alternateAmount);
				extra.setId(getId() * 10 + fundType+1);
				extra.setId2(getId() * 10 + fundType);
				extra.setSuccess(true);

				RecordTransHistory(extra, fundType);
				RecordTransHistory(extra, fundType + 1);

				
			}
		}
		else if (fundType == 3)
		{
			if ((fund[2].getMoney() + fund[fundType].getMoney()) < amount)
			{
				cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << endl;
				
				return false;
			}
			else
			{
				alternateAmount = amount - fund[fundType].getMoney();


				fund[fundType].Withdraw(fund[fundType].getMoney());
				fund[2].Withdraw(alternateAmount);

				Transactions extra;
				extra.setTransType('T');
				extra.setAmount(alternateAmount);
				extra.setId(getId() * 10 + fundType-1);
				extra.setId2(getId() * 10 + fundType);
				extra.setSuccess(true);

				RecordTransHistory(extra, fundType);
				RecordTransHistory(extra, fundType - 1);
				
			}
		}
		else
		{
			cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << endl;
			return false;
		}
	}
	else
	{
		fund[fundType].Withdraw(amount);
		return true;
	}
	return true;
}


void Account::RecordTransHistory(Transactions copy, int fundType)
{
	Transactions temp = copy;
	fund[fundType].RecordTransaction(temp);
}

void Account::AccountHistory(int id)
{
	string s = to_string(id);
	int fundType = id % 10;
	
	if (s.size() == 5)
	{
		cout << "Transaction History for " << getFirstName() << " " << getLastName() << " " << fund[fundType].getFundName() << ": $" << fund[fundType].getMoney() << endl;
		fund[fundType].PrintHistoryOfFund();
	}
	else if (s.size() == 4)
	{
		cout << "Transaction History for " << getFirstName() << " " << getLastName() << " " << "by fund." << endl;
		for (int i = 0; i < 10; i++)
		{
			fund[i].PrintHistory();
		}
	}
}

bool Account::Deposit(int fundType, int amount)
{

	fund[fundType].Deposit(amount);
	
	return true;
}

bool Account::isEmpty(int fundType)
{
	if (fund[fundType].getMoney() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Account::Print()
{
	cout << getFirstName() <<" "<<  getLastName() << " Account ID: " << getId() << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << fund[i].getFundName() << ": $" << fund[i].getMoney() << endl;
	}
	cout << endl;
}