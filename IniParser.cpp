#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

string configPath = "config.ini";

class SimpleIniFileParser
{
public:
	SimpleIniFileParser() { }
	SimpleIniFileParser(const string& iniPath)
	{
		this->loadFromFile(iniPath);
	}

	void loadFromFile(const string& iniPath)
	{
		this->parameters.clear();
		ifstream fin(iniPath.c_str());
		string line;
		while (getline(fin, line))
		{
			this->processLine(line);
		}
	}

	string toString()
	{
		string out;
		for (map<string, int>::const_iterator itr = this->parameters.begin();
			itr != this->parameters.end();
			++itr)
		{
			if (itr != this->parameters.begin())
			{
				out += "\n";
			}
			out += "parameters[" + itr->first + "] = " + to_string(itr->second);
		}
		return out;
	}

private:
	map<string, int> parameters;

	static std::vector<std::string> split(const std::string &s, char delim) {
		std::vector<std::string> elems;
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	static std::string trim(std::string& str)
	{
		str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
		str.erase(str.find_last_not_of(' ') + 1);         //surfixing spaces
		return str;
	}

	void processLine(const string& line)
	{
		vector<string> tokens = split(line, '=');
		if (tokens.size() != 2)
		{
			return;
		}
		this->parameters[trim(tokens[0])] = stoi(tokens[1]);
	}
};


void writeConfigFile(const string &iniPath)
{
	ofstream fout(iniPath.c_str());
	fout << "BatteryConsumptionRate  =    1" << endl;
	fout << "MaxSteps   = 1200" << endl;
	fout << "MaxStepsAfterWinner=200" << endl;
	fout << "BatteryCapacity=400" << endl;
	fout << "BatteryRachargeRate=20" << endl;
	fout.close();

	ifstream fin(iniPath.c_str());
	string line;
	cout << "Original config ini file: " << endl;
	while (getline(fin, line))
	{
		cout << line << endl;
	}
}

int run()
{
	SimpleIniFileParser iniParser(iniPath);
	cout << endl << endl << "Parameters read:" << endl;
	cout << iniParser.toString() << endl;
	return 0;
}
