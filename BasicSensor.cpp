#include <string>
#include "BasicSensor.h"
using namespace std;


BasicSensor::BasicSensor(House &i_house, Robot &i_robot)
{
	robot = &i_robot;
	house = &i_house; //should deep copy the house. In next excercises.
	robot->data.dustLeft = 0;
	robot->data.dustCollected = 0;
	robot->data.isInDock = true;
	//find robot position and count dust
	for (int i = 0; i < house->R; i++)
	{
		for (int j = 0; j < house->C; ++j)
		{
			if (house->matrix[i][j] > '0' && house->matrix[i][j] <= '9')
			{
				robot->data.dustLeft += house->matrix[i][j] - '0';
			}

		}
		int col = house->matrix[i].find("D");
		if (col == string::npos)
			continue;
		robot_pos.row = i;
		robot_pos.col = col;
	}
	robot->data.sumDirtInHouse = robot->data.dustLeft;
}

struct SensorInformation BasicSensor::sense() const
{
	SensorInformation out;
	out.dirtLevel = 0;
	//check dirt level
	char cur_pos = house->matrix[robot_pos.row][robot_pos.col];
	if (cur_pos > '0' && cur_pos <= '9')
	{
		out.dirtLevel = cur_pos - '0';
	}

	//handle walls
	out.isWall[(int)Direction::North] = house->matrix[robot_pos.row - 1][robot_pos.col] == 'W';
	out.isWall[(int)Direction::South] = house->matrix[robot_pos.row + 1][robot_pos.col] == 'W';
	out.isWall[(int)Direction::East] = house->matrix[robot_pos.row][robot_pos.col+1] == 'W';
	out.isWall[(int)Direction::West] = house->matrix[robot_pos.row][robot_pos.col-1] == 'W';
	return out;

}

//moves the robot position in the given direction.
//does not check the direction validity.
//returns true if move was legal. otherwise returns false
bool BasicSensor::move(Direction direction)
{
	switch (direction)
	{
	case Direction::North:
		robot_pos.row -= 1;
		break;
	case Direction::South:
		robot_pos.row += 1;
		break;
	case Direction::East:
		robot_pos.col += 1;
		break;
	case Direction::West:
		robot_pos.col -= 1;
		break;
	}
	char place = house->matrix[robot_pos.row][robot_pos.col];
	if ('W' == place) //illegal move. moved into a wall
		return false;
	if (place == 'D') //in docking station
	{
		robot->data.isInDock = true;
		robot->data.battaryLeft += robot->conf.batteryRechargeRate;
		if (robot->data.battaryLeft > robot->conf.batteryCapacity)
		{
			robot->data.battaryLeft = robot->conf.batteryCapacity;
		}
		return true;
	}
	//not in docking station
	robot->data.isInDock = false;
	robot->data.battaryLeft -= robot->conf.batteryConsumprionRate;
	if (place > '0' && place <= '9')
	{
		house->matrix[robot_pos.row][robot_pos.col] = place - 1;
		robot->data.dustLeft--;
		robot->data.dustCollected++;
		
	}
	return true;

}

