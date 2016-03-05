#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"

struct Battary {
	int capacity;
	int consumprionRate;
	int rechargeRate;
	int battaryLeft;
};

class Robot{
public:
	
private:
	AbstractAlgorithm *algo;
	AbstractSensor *sensor;
	int dustLeft;
	int countSteps; //the number of steps done so far
	int maxSteps;
	int maxStepsAfterWinner;
	struct Battary battary;
};