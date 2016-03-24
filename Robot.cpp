
#include "Robot.h"
#include "StupidAlgorithm.h"
#include "BasicSensor.h"


Robot::Robot(struct ConfigInfo &config, House &house) : conf(config)
{
	data.battaryLeft = config.batteryCapacity;
	data.countSteps = 0;
	//init algo
	algo = new StupidAlgorithm();
	m_sensor = new BasicSensor(house, *this);
	algo->setSensor(*m_sensor);

}

Robot::~Robot()
{
	delete algo;
	delete m_sensor;
}

struct stepData Robot::step(bool is_winner, int steps_left)
{
	if (m_sensor->move(algo->step()))
	{
		data.isLegalMove = true;
		data.countSteps++;
		return data;
	}
	else
	{
		data.isLegalMove = false;
		return data;
	}

}