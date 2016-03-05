#pragma once
#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"

struct Battery {
	int capacity;
	int consumprionRate;
	int rechargeRate;
	int battaryLeft;
};
struct Position {
	int x;
	int y;
};
struct stepData{
	int dustLeft;
	bool isInDock;
};
typedef struct Battery Battery;
typedef struct stepData stepData;
typedef struct Position Position;

class Robot{
public:
	struct stepData step(bool is_winner, int steps_left);
private:
	AbstractAlgorithm *algo;
	AbstractSensor *sensor;
	int dustLeft;
	int countSteps; //the number of steps done so far
	int maxSteps;
	int maxStepsAfterWinner;
	struct Battery battery;
	Position robotPos;
};