#pragma once
#include "AbstractAlgorithm.h"
#include "House.h"
#include "Robot.h"


class StupidAlgorithm : public AbstractAlgorithm {
public:

	// setConfiguration is called once when the Algorithm is initialized - see below 
	void setConfiguration(map<string, int> config);


	StupidAlgorithm();
	// setSensor is called once when the Algorithm is initialized
	void setSensor(const AbstractSensor& sensor);
	// step is called by the simulation for each time unit
	Direction step();
	// this method is called by the simulation either when there is a winner or
	// when steps == MaxSteps - MaxStepsAfterWinner
	// parameter stepsTillFinishing == MaxStepsAfterWinner
	void aboutToFinish(int stepsTillFinishing) {  };
	AbstractSensor const *m_sensor;
};