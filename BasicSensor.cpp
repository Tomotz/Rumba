#include <string>
#include "BasicSensor.h"
using namespace std;


BasicSensor::BasicSensor(House &i_house, Robot &i_robot)
{
	robot = &i_robot;
	house = &i_house; //should deep copy the house. In next excercises.
	
	//find robot position
	for (int i = 0; i < i_house.R; i++)
	{
		int col = house->matrix[i].find("D");
		if (col == string::npos)
			continue;
		robot_pos.row = i;
		robot_pos.col = col;
	}
}

struct SensorInformation BasicSensor::sense() const
{
	SensorInformation out;
	out.dirtLevel = 0;
	char cur_pos = house->matrix[robot_pos.row][robot_pos.col];
	if (cur_pos > '0' && cur_pos <= '9')
	{
		out.dirtLevel = cur_pos - '0';
	}
	int dir = Direction::North;
	out.isWall[] = house->matrix[robot_pos.row - 1][robot_pos.col];


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
		robot->isInDoc = true;
		robot->battaryLeft += Simulator::config.batteryRechargeRate;
		if (robot->battaryLeft > Simulator::config.batteryCapacity)
		{
			robot->battaryLeft = Simulator::config.batteryCapacity;
		}
		return true;
	}
	//not in docking station
	robot->isInDoc = false;
	robot->battaryLeft += Simulator::config.batteryConsumprionRate;
	if (place > '0' && place <= '9')
	{
		house->matrix[robot_pos.row][robot_pos.col] = place - 1;
		robot->dustLeft--;
		robot->dustCollected++;
		
	}
	return true;

}

