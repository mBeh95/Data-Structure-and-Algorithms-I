// TheGreedyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Robot.h"
#include <iostream>

using namespace std;


int main()
{
	Robot robot;
	cin >> robot;
	cout << robot;
	
	//Getters test
	cout << "Robot position at (" << robot.getRobotXCoordinates() << ", " << robot.getRobotYCoordinates() << ") " << endl;
	cout << "While the Treasure position is at (" << robot.getTreasureXCoordinate() << ", " << robot.getTreasureYCoordinate() << ") " << endl;


	//New outPut after the first output to see if it will start from scratch
	cin >> robot;
	cout << robot;

	cout << "Robot position at (" << robot.getRobotXCoordinates() << ", " << robot.getRobotYCoordinates() << ") " << endl;
	cout << "While the Treasure position is at (" << robot.getTreasureXCoordinate() << ", " << robot.getTreasureYCoordinate() << ") " << endl;



	system("pause");
	return 0;
}

