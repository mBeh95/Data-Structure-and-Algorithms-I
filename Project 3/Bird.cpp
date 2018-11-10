#include "stdafx.h"
#include "Bird.h"


Bird::Bird()
{
}


Bird::~Bird()
{
}
string Bird::getName() const
{
	return this->name;
}
bool Bird:: operator==(const Bird &rhs) const
{
	return (this->name == rhs.name) && (this->id == rhs.id);
}
bool Bird::operator!=(const Bird &rhs) const
{
	return (this->name != rhs.name) || (this->id != rhs.id);
}
bool Bird::operator<(const Bird &rhs) const
{
	return (this->id < rhs.id);
}

ostream& operator<<(ostream &outStream, const Bird &rhs)
{
	outStream << rhs.name << rhs.id;
	return outStream;
}
