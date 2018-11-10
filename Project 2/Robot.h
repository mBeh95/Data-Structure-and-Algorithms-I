#pragma once
#include <iostream>

using namespace std;

class Robot
{
public:
	Robot();
	Robot(int xRobot, int yRobot, int xTreasure, int yTreasure);
	~Robot();

	//Setter
	void setAllCoordinates(int xRobot, int yRobot, int xTreasure, int yTreasure);

	// Getters
	int getTreasureXCoordinate() const;
	int getTreasureYCoordinate() const;
	int getRobotXCoordinates() const;
	int getRobotYCoordinates() const;

	//Operators
	friend ostream& operator<<(ostream &outStream, const Robot &rhs);
	friend istream& operator>>(istream &inStream, Robot &rhs);

private:
	int numPaths = 0;
	int xRobot;
	int yRobot;
	int xTreasure;
	int yTreasure;
	string compass;

	//Maps out the shortest paths to the treasure
	int map(int xRobot, int yRobot, int xTreasure, int yTreasure, string compass);

};

