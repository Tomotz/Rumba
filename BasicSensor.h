#pragma once
#include "AbstractSensor.h"
#include "House.h"
#include "Robot.h"
#include "Simulator.h"

struct Position {
	int row;
	int col;
};
typedef struct Position Position;

class BasicSensor : public AbstractSensor {
public:
	struct SensorInformation sense() const;
	bool move(Direction direction);
	BasicSensor(House &i_house, Robot &i_robot);
private:
	House *house;
	Position robot_pos;
	Robot *robot;

};