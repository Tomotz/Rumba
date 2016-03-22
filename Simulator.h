#pragma once
#include <vector>
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
	void simulate(char *config_file, char *houses_path);
	void print_house(House& h);
	static ConfigInfo config;
private:
	vector<std::string> split(const std::string &s, char delim);
	void processLine(const string& line);
	void oneHouseHandler(char *house_file); //runs all robots' simulations on a single house
	class Robot *bots;
};