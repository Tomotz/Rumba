#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class House
{
public:
	string name;
	string desc;
	int R;
	int C;
	string* matrix;

	House() : matrix(NULL) {}
	~House()
	{
		if (matrix != NULL)
		{
			delete[] matrix;
		}
	}
};

void createSimple1()
{
	cout << "Creating file: simple1.txt" << endl;
	ofstream fout("simple1.txt");
	fout << "Simple1" << endl;
	fout << "2 Bedrooms + Kitchen Isle" << endl;
	fout << 8 << endl;
	fout << 10 << endl;
	fout << "WWWWWWWWWW" << endl;
	fout << "W22  DW59W" << endl;
	fout << "W  W 1119W" << endl;
	fout << "W WWW3WW W" << endl;
	fout << "W6   3W  W" << endl;
	fout << "W78W  W  W" << endl;
	fout << "W99W  W  W" << endl;
	fout << "WWWWWWWWWW" << endl;
	fout.close();
}

void input(House& house)
{
	cout << "Reading house from file: simple1.txt into class House" << endl;
	ifstream fin("simple1.txt");
	getline(fin, house.name);
	std::getline(fin, house.desc);
	fin >> house.R;
	fin >> house.C;
	fin.ignore(); //skip newline and go the begining of matrix
	house.matrix = new string[house.R];
	for (int i = 0; i < house.R; ++i)
	{
		std::getline(fin, house.matrix[i]);
	}
}

void output(const House& house)
{
	cout << "Printing house from instance into standard output" << endl;
	cout << "House name: " << house.name << endl;
	cout << "House description: " << house.desc << endl;
	for (int i = 0; i < house.R; ++i)
	{
		for (int j = 0; j < house.C; ++j)
		{
			cout << house.matrix[i][j];
		}
		cout << endl;
	}
}

int main()
{
	House house;
	createSimple1();
	input(house);
	output(house);
	return 0;
}
