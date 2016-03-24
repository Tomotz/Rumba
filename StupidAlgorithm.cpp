#include "StupidAlgorithm.h"
#include "BasicSensor.h"
#include <ctime>


StupidAlgorithm::StupidAlgorithm()
{
	srand(time(0));
	m_sensor = NULL;
}

void StupidAlgorithm::setSensor(const AbstractSensor& sensor)
{
	m_sensor = &sensor;
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
	return (Direction)move_dir;
}

void StupidAlgorithm::setConfiguration(map<string, int> config)
{
	//left empty on perpose. We put configuration inside the robot.
}