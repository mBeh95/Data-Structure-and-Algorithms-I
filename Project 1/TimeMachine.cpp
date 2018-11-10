// TimeMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TimeSpan.h"
#include <iostream>

using namespace std;

int main()
{

	int waitVar;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8(1.5,4,-10), dur9;

	//My blank Test objects
	TimeSpan dur10, dur11, dur12, dur13;

	//+ and - operators testing
	dur7 = dur1 + dur3;
	dur9 = dur1 - dur2;
	//Unary Duration operator testing
	dur10 = -dur2;
	dur11 = -dur6;
	//istream testing
	cin >> dur12;
	cin >> dur13;

	//ostream testing
	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	cout << dur8 << endl;
	cout << dur9 << endl;
	cout << dur10 << endl;
	cout << dur11 << endl;
	cout << dur12<< endl;
	cout << dur13 << endl;
	

	// += operator testing
	dur7 += dur3;
	cout << dur3 << endl;
	cout << dur7 << endl;

	
	// -= operator testing
	dur9 -= dur6;
	cout << dur6 << endl;
	cout << dur9 << endl;

	// != testing
	if (dur3 != dur6)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}
	// == testing
	if (dur3 == dur6)
	{
		cout << "Durations are the same" << endl;
	}
	else
	{
		cout << "Durations are different." << endl;
	}

	system("pause");
	return 0;
}