#include "StupidAlgorithm.h"
#include "BasicSensor.h"


StupidAlgorithm::StupidAlgorithm(House &house, Robot &robot)
{
	BasicSensor B(house, robot);
	setSensor(B);
}

void StupidAlgorithm::setSensor(const AbstractSensor& sensor)
{
	m_sensor = sensor;
}


Direction StupidAlgorithm::step()
{
	SensorInformation info = m_sensor->sense();
	int move_dir;
	while (true)
	{
		move_dir = rand() % 5; //gets a random number between 0 and 4
		if (move_dir == 4)
			break;
		if (!info.isWall[move_dir])
			break;
	}
	m_sensor->move((Direction)move_dir);
	return (Direction)move_dir;
}

void StupidAlgorithm::setConfiguration(map<string, int> config)
{
	//left empty on perpose. We put configuration inside the robot.
}