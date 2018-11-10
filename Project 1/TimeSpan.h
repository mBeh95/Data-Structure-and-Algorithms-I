#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class TimeSpan
{
private:
	int hour;
	int min;
	int sec;
	void turnToSeconds();

public:
	TimeSpan();
	~TimeSpan();


	TimeSpan(double sec);
	TimeSpan(double min, double sec);
	TimeSpan(double hour, double min, double sec);

	
	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	bool setTime(int hours, int minutes, int seconds);


	TimeSpan operator-(const TimeSpan &rhs) const;
	TimeSpan operator-() const; //Unary Negative
	TimeSpan& operator-=(const TimeSpan &rhs);

	TimeSpan operator+(const TimeSpan &rhs) const;
	TimeSpan& operator+=(const TimeSpan &rhs);

	bool operator==(const TimeSpan &rhs) const;
	bool operator!=(const TimeSpan &rhs) const;
	friend ostream& operator<<(ostream &outStream, const TimeSpan &rhs);
	friend istream& operator>>(istream &inStream, TimeSpan &rhs);
};

