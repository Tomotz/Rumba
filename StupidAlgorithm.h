#pragma once
#include "AbstractAlgorithm.h"


class StupidAlgorithm : public AbstractAlgorithm {
public:
	// setSensor is called once when the Algorithm is initialized
	void setSensor(AbstractSensor& sensor);
	// step is called by the simulation for each time unit
	Direction step();
	// this method is called by the simulation either when there is a winner or
	// when steps == MaxSteps - MaxStepsAfterWinner
	// parameter stepsTillFinishing == MaxStepsAfterWinner
	void aboutToFinish(int stepsTillFinishing) {  };
};