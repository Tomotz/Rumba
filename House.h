#pragma once
#include <string>
using namespace std;


class House
{
public:
	string name;
	string desc; //house description
	int R, C;
	string *matrix;

	House() :matrix(NULL){}
	~House()
	{
		if (matrix != NULL)
		{
			delete[] matrix;
			matrix = NULL;
		}
	}
};

