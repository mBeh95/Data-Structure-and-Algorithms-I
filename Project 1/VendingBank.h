#pragma once
#include <string>
#include <math.h> //used for calculating the change
using namespace std;


class VendingBank
{
public:
	VendingBank();
	VendingBank(int id);
	~VendingBank();
	int getVendingBankID() const;

	//Money
	double vendingCost(int itemNum);//Give the cost of item.
	double bankInsertCash(); // Take in the money and calculates it
	double returnChangeInCoin(double totalAmount); //Takes in total money put in and returns leftover change
	double returnAllMoney(); // return money if theres no item in the machine.
	

	//Inventory
	bool noItem(); // if true, start function returnAllMoney


private:
	int itemNum;
	int id;
	double cost;
	double totalAmount;
	
};

