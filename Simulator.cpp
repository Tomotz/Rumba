#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <stdlib.h>  
#include <vector>
#include <map>

#include "Simulator.h"
using namespace std;
//TODO: add walls around house if non exists

void Simulator::oneHouseHandler(char *house_file)
{
	ifstream fin(house_file);
	House house;
	getline(fin, house.name);
	getline(fin, house.desc);
	fin >> house.R;
	fin >> house.C;
	string temp;
	getline(fin, temp); //skip line feed
	house.matrix = new string[house.R];
	for (int i = 0; i < house.R; i++)
	{
		getline(fin, house.matrix[i]);
	}
	for (int i = 0; i < house.R; i++)
	{
		house.matrix[i][0] = 'W';
		house.matrix[i][house.C-1] = 'W';
	}
	for (int i = 0; i < house.C; i++)
	{
		house.matrix[0][i] = 'W';
		house.matrix[house.R-1][i] = 'W';
	}
	Robot irobot(config, house);
	while (true)
	{
		stepData data = irobot.step(false, 0);
		if (!data.isLegalMove)
		{
			cout << "algorithm made an invalid step" << endl;
			int score = 0;
			cout << "[" << house.name << "]\t" << score << endl;
			break;
		}
		if (data.countSteps == config.maxSteps ||
			(data.dustLeft == 0 && data.isInDock))
		{ //robot finished
			if (winnerNumSteps == 0)
				winnerNumSteps = data.countSteps;
			int score = calc_score(data);
			cout << "[" << house.name << "]\t" << score << endl;
			if (curPositionInCompetition < 4)
				curPositionInCompetition++; //TODO: in ex2 this cannot happen here.
			break;
		}
		if (data.battaryLeft <= 0)
		{
			data.countSteps = simulationStep;
			int score = calc_score(data);
			cout << "[" << house.name << "]\t" << score << endl;
			cout << "no battery left" << endl;
			break;
		}
	}
	print_house(house);
	fin.close();
}

void Simulator::print_house(House& h)
{
	for (int i = 0; i < h.R; i++)
	{
		cout << h.matrix[i];
		cout << endl;

	}
}
int Simulator::calc_score(struct stepData &data)
{
	int score = 2000;
	score -= (curPositionInCompetition - 1) * 50;
	score += winnerNumSteps - data.countSteps;
	score -= (data.sumDirtInHouse - data.dustCollected) * 3;
	score += data.isInDock ? 50 : -200;
	return (score > 0 ? score : 0);
}

void Simulator::simulate(char *config_file, char *house_file)
{
	simulationStep = 0;
	curPositionInCompetition = 1;
	winnerNumSteps = 0;

	string file_content;
	//open the config file
	ifstream conf(config_file);

	//parse the config file
	getline(conf, file_content);
	string s = file_content.substr(file_content.find('=')+1, file_content.length() - file_content.find('='));
	config.maxSteps = stoi(s);

	getline(conf, file_content);
	s = file_content.substr(file_content.find('=')+1, file_content.length() - file_content.find('='));
	config.maxStepsAfterWinner = stoi(s);

	getline(conf, file_content);
	s = file_content.substr(file_content.find('=') + 1, file_content.length() - file_content.find('='));
	config.batteryCapacity = stoi(s);

	getline(conf, file_content);
	s = file_content.substr(file_content.find('=') + 1, file_content.length() - file_content.find('='));
	config.batteryConsumprionRate = stoi(s);

	getline(conf, file_content);
	s = file_content.substr(file_content.find('=') + 1, file_content.length() - file_content.find('='));
	config.batteryRechargeRate = stoi(s);

	conf.close();
	


	//walk over houses directory.
	oneHouseHandler(house_file);


}

int main(int argc, char *argv[])
{
	char *config_file, *houses_path;
	//handle input args. If no args found use CWD as input.
	config_file = "C:\\Users\\tom\\Desktop\\TAU\\solutions\\AdvancedProgramming\\Rumba\\Debug\\config.ini";//"config.ini";
	houses_path = "C:\\Users\\tom\\Desktop\\TAU\\solutions\\AdvancedProgramming\\Rumba\\Debug\\Orenshtein.house";
	if (argc >= 3)
	{ //at least one input arg
		if (strcmp(argv[1], "-config") == 0)
		{
			config_file = argv[2];
		}
		else if (strcmp(argv[1], "-house_path") == 0)
		{
			houses_path = argv[2];
		}
		else
		{
			cout << "bad input" << endl;
			return 0;
		}
		if (argc == 5)
		{ //two input args
			if (strcmp(argv[3], "-config") == 0)
			{
				config_file = argv[4];
			}
			else if (strcmp(argv[3], "-house_path") == 0)
			{
				houses_path = argv[4];
			}
			else
			{
				cout << "bad input" << endl;
				return 0;
			}

		}
	}
	Simulator s;
	//start the simulator
	s.simulate(config_file, houses_path);
	
	//wait for input. Just so that the program won't close in visual studio
	char a[1024];
	cin >> a;
	return 0;
}