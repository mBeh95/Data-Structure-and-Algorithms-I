#include "stdafx.h"
#include "Robot.h"


Robot::Robot()
{

}

Robot::Robot(int xRobot, int yRobot, int xTreasure, int yTreasure)
{
	this->xRobot = xRobot;
	this->xTreasure = yTreasure;
	this->yRobot = yRobot;
	this->yTreasure = yTreasure;
	setAllCoordinates(xRobot, yRobot, xTreasure, yTreasure);
}

Robot::~Robot()
{
}

void Robot::setAllCoordinates(int xRobot, int yRobot, int xTreasure, int yTreasure)
{
	this->xRobot = xRobot;
	this->xTreasure = xTreasure;
	this->yRobot = yRobot;
	this->yTreasure = yTreasure;
	numPaths = 0;
	map(xRobot, yRobot, xTreasure, yTreasure, compass);
	
}

int Robot::getTreasureXCoordinate() const
{
	return xTreasure;
}
int Robot::getTreasureYCoordinate() const
{
	return yTreasure;
}
int Robot::getRobotXCoordinates() const
{
	return xRobot;
}
int Robot::getRobotYCoordinates() const
{
	return yRobot;
}

int Robot::map(int xRobot, int yRobot, int xTreasure, int yTreasure, string compass)
{
	//Base Case, Note if Robot position and treasure position are the same, there will no paths
	if (xRobot == xTreasure && yRobot == yTreasure)
	{
		printf("%s\n", compass.c_str());
		numPaths += 1;
	}
	//Moving North, East, West, or South recursively
	else
	{
		if (yRobot < yTreasure)
		{
			map(xRobot, yRobot + 1, xTreasure, yTreasure, compass + "N");
		}
		if (xRobot < xTreasure)
		{
			map(xRobot + 1, yRobot, xTreasure, yTreasure, compass + "E");
		}


		if (xRobot > xTreasure)
		{
			map(xRobot - 1, yRobot, xTreasure, yTreasure, compass + "W");
		}


		if (yRobot > yTreasure)
		{
			map(xRobot, yRobot - 1, xTreasure, yTreasure, compass + "S");
		}



	}
	return numPaths;
}



//Operators
ostream& operator<<(ostream &outStream, const Robot &rhs)
{
	outStream << "Number of paths found: " << rhs.numPaths << endl;
	return outStream;
}

istream& operator>>(istream &inStream, Robot &rhs)
{
	int xRobot;
	int yRobot;
	int xTreasure;
	int yTreasure;
	cout << "Insert x and Y for Robot, then x and y for the treasure " << endl;
	inStream >> xRobot;
	inStream >> yRobot;
	inStream >> xTreasure;
	inStream >> yTreasure;
	rhs.setAllCoordinates(xRobot, yRobot, xTreasure, yTreasure);
	return inStream;
}
