#pragma once
#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"
#include "Simulator.h"
#include "House.h"

struct stepData{
	int dustLeft;
	bool isInDock;
	int dustCollected;
	int countSteps; //the number of steps done so far
	bool isLegalMove;
	int battaryLeft;
	int sumDirtInHouse;
};
typedef struct stepData stepData;

class Robot{
public:
	~Robot();
	Robot(struct ConfigInfo &config, House &house);
	struct stepData step(bool is_winner, int steps_left);

	const struct ConfigInfo &conf;
	stepData data;
private:
	AbstractAlgorithm *algo;
	AbstractSensor *m_sensor;
};