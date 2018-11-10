// Catalan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int CatalanNumber(int n);

int main()
{

	int n;
	cout << "Input Catalan nth number: ";
	cin >> n;
	cout << "Output is: " << CatalanNumber(n) << endl;


	system("pause");
	return 0;
}

int CatalanNumber(int n)
{
	//Base case
	if (n < 1)
	{
		return 1;
	}
	int result = 0;
	//Recursion
	for (int i = 0; i < n; i++)
	{
		result += CatalanNumber(i)*CatalanNumber(n - i - 1);
	}
	return result;

}