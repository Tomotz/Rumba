#pragma once
#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"
#include "Simulator.h"

struct stepData{
	int dustLeft;
	bool isInDock;
};
typedef struct stepData stepData;

class Robot{
public:
	Robot(struct ConfigInfo &config, House &house);
	struct stepData step(bool is_winner, int steps_left);
	AbstractAlgorithm *algo;
	const struct ConfigInfo &conf;
	int dustLeft;
	int dustCollected;
	int isInDoc;
	int countSteps; //the number of steps done so far
	int battaryLeft;
	ConfigInfo *config;
};