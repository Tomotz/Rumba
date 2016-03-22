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

/*
vector<std::string> Simulator::split(const string &s, char delim) {
	vector<std::string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
void Simulator::processLine(const string& line)
{
	vector<string> tokens = split(line, '=');
	if (tokens.size() != 2)
	{
		return;
	}
	this->parameters[trim(tokens[0])] = stoi(tokens[1]);
}
*/
void Simulator::simulate(char *config_file, char *house_file)
{

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