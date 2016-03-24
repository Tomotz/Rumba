#pragma once
#include "Robot.h"
#include "House.h"

using namespace std;

struct ConfigInfo {
	int maxSteps;
	int maxStepsAfterWinner;
	int batteryCapacity;
	int batteryConsumprionRate;
	int batteryRechargeRate;
};
typedef struct ConfigInfo ConfigInfo;


class Simulator{
public:
	void simulate(string config_file, string houses_path);
	void print_house(House& h);
private:
	void oneHouseHandler(string house_file); //runs all robots' simulations on a single house
	int calc_score(struct stepData &data);

	ConfigInfo config;
	int simulationStep;
	int winnerNumSteps;
	int curPositionInCompetition;
};