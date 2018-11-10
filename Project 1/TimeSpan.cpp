#include "stdafx.h"
#include "TimeSpan.h"


TimeSpan::TimeSpan()
{
}


TimeSpan::~TimeSpan()
{
}

TimeSpan::TimeSpan(double sec)
{
	double h = 0;
	double m = 0;
	double s = sec;

	//Catss doubles to ints.
	m += 60 * (h - (int)h);
	s += 60 * (m - (int)m);
	s = round(s);
	setTime(h, m, s);

}
TimeSpan::TimeSpan(double min, double sec)
{

	double h = 0;
	double m = min;
	double s = sec;

	//Used to bring in the decimals over
	m += 60 * (h - (int)h);
	s += 60 * (m - (int)m);
	s = round(s);

	setTime(h, m, s);
	

}

TimeSpan::TimeSpan(double hour, double min, double sec)
{
	double h = hour;
	double m = min;
	double s = sec;

	//Used to bring in the decimals over
	m += 60 * (h - (int)h);
	s += 60 * (m - (int)m);
	s = round(s);

	setTime(h, m, s);

}

int TimeSpan::getHours() const
{
	return (int)hour;
}
int TimeSpan::getMinutes() const
{
	return (int)min;
}
int TimeSpan::getSeconds() const
{
	return (int)sec;
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
	this->hour = hours;
	this->min = minutes;
	this->sec = seconds;
	turnToSeconds();
	return true;
	
}

void TimeSpan::turnToSeconds()
{
	double secondsOnly = hour * 3600 + min * 60 + sec;
	hour = secondsOnly / 3600;
	secondsOnly = fmod(secondsOnly, 3600);
	min = secondsOnly / 60;
	sec = fmod(secondsOnly, 60);
	
}

TimeSpan& TimeSpan:: operator-=(const TimeSpan &rhs)
{
	hour -= rhs.hour;
	min -= rhs.min;
	sec -= rhs.sec;
	turnToSeconds();
	return *this;
}

TimeSpan TimeSpan ::operator-(const TimeSpan &rhs) const
{
	TimeSpan subOp = *this;
	subOp -= rhs;
	return subOp;
}
TimeSpan TimeSpan:: operator-() const
{
	TimeSpan answer;
	answer.hour = -hour;
	answer.min = -min;
	answer.sec = -sec;
	return answer;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &rhs)
{
	hour += rhs.hour;
	min += rhs.min;
	sec += rhs.sec;
	turnToSeconds();
	return *this;
}

TimeSpan TimeSpan:: operator+(const TimeSpan &rhs) const
{
	TimeSpan addOp = *this;
	addOp += rhs;
	return addOp;
}

bool TimeSpan:: operator==(const TimeSpan &rhs) const
{
	return (rhs.hour == hour) && (rhs.min == min) && (rhs.sec == sec);
}
bool TimeSpan:: operator!=(const TimeSpan &rhs) const
{
	return (rhs.hour != hour) && (rhs.min != min) && (rhs.sec != sec);
}
ostream& operator<<(ostream &outStream, const TimeSpan &rhs)
{
	outStream << "Hours: " << rhs.hour << " Minutes: " << rhs.min << " Seconds: " << rhs.sec << endl;
	return outStream;
}
istream& operator>>(istream &inStream, TimeSpan &rhs)
{
	int hour, min, sec;
	cout << "Input in all numbers for the duration." << endl;
	cout << "input Hour: ";
	inStream >> hour;
	cout << "input Minute: ";
	inStream >> min;
	cout << "input Second: ";
	inStream >> sec;
	rhs.setTime(hour, min, sec);
	return inStream;
}
