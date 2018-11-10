#include "stdafx.h"
#include "Transactions.h"


Transactions::Transactions()
{

}

Transactions::~Transactions()
{
}


char Transactions::getTransType()
{
	return transType;
}

string Transactions::getLastName()
{
	return lastName;
}
string Transactions::getFirstName()
{
	return firstName;
}

bool Transactions::getSuccess()
{
	return success;
}

void Transactions::setSuccess(bool success)
{
	this->success = success;
}
void Transactions::setId(int id)
{
	this->id = id;
}
void Transactions::setId2(int id2)
{
	this->id2 = id2;
}
void Transactions::setTransType(char transType)
{
	this->transType = transType;
}
void Transactions::setAmount(int amount)
{
	this->amount = amount;
}
int Transactions::getId()
{
	return id;
}

int Transactions::getId2()
{
	return id2;
}

int Transactions::getAmount()
{
	return amount;
}



istream& operator>>(istream &inStream, Transactions &rhs)
{
	char transType;
	string lastName;
	string firstName;
	int amount;
	int id;
	int id2;

	inStream >> rhs.transType;

	if (rhs.transType == 'O')
	{
		inStream >> rhs.lastName >> rhs.firstName >> rhs.id;
		return inStream;
		
	}
	else if (rhs.transType == 'D')
	{
		inStream >> rhs.id >> rhs.amount;
		return inStream;
	}
	else if (rhs.transType == 'T')
	{
		inStream >> rhs.id >> rhs.amount >> rhs.id2;
		return inStream;
	}
	else if (rhs.transType == 'W')
	{
		inStream >> rhs.id >> rhs.amount;
		return inStream;
	}
	else if (rhs.transType == 'H')
	{
		inStream >> rhs.id;
		return inStream;
	}

}

ostream& operator<<(ostream &outStream, Transactions &rhs)
{
	char transType;

	if (rhs.getTransType() == 'O')
	{

	}
	else if (rhs.getTransType() == 'D')
	{
		outStream << "D " << rhs.getId() << " " << rhs.getAmount();
	}
	else if (rhs.getTransType() == 'T')
	{
		outStream << "T " << rhs.getId() << " " << rhs.getAmount() << " " << rhs.getId2();
	}
	else if (rhs.getTransType() == 'W')
	{
		outStream << "W " << rhs.getId() << " " << rhs.getAmount();
	
	}
	else if (rhs.getTransType() == 'H')
	{
		
	}
	if (!(rhs.getSuccess()))
	{
		outStream << " (Failed)";
	}
	
	return outStream << endl;
}
