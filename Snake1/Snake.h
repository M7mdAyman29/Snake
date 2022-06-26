#pragma once
#include<iostream>
#include<conio.h>
#include "Map.h"
#include "Player.h"
using namespace std;

enum Direction
{
	Top = 1, Down, Right, Left
};
class Snake
{
	Map m;
	Player p;
public:
	
	int Headx, Heady, Tail_n;
	Direction dir;
	Snake();
	void input();
	void Move();
	void draw()
	{
		for (size_t i = 0; i < m.Height; i++)
		{
			for (size_t j = 0; j < m.width; j++)
			{
				if (i == 0 || i == m.Height - 1)
					cout << "*";
				else if (j == 0 || j == m.width - 1)
					cout << "*";
				else if (i == m.fruity || j == m.fruitx)
					cout << "$";
				else if (i == Heady || j == Headx)
					cout << "O";
				else
					cout << " ";
			}
		}
	}
};

