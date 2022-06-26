#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class Map
{

public:
	int width, Height, fruitx, fruity;

	Map()
	{
		srand(time(NULL));
		width = 40;
		Height = 20;
		fruitx = rand() % (width - 2) + 1;
		fruity = rand() % (Height - 2) + 1;
	}
};

