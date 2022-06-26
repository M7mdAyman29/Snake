#include <iostream>
#include "Snake.h"
#include "Map.h"

using namespace std;


inline  Snake::Snake()
{
	Headx = m.width / 2;
	Heady = m.Height / 2;
	Tail_n = 0;
}

inline void Snake::input()
{
	if (_kbhit())
	{
		char c = _getch();
		switch (c)
		{
		case'w': dir = Top; break;
		case's': dir = Down; break;
		case'd': dir = Right; break;
		case'a': dir = Left; break;
		case'x': exit(0); break;
		}
	}
}

void Snake::Move()
{
	switch (dir)
	{
	case Top: Heady--;
		break;
	case Down: Heady++;
		break;
	case Right:Headx++;
		break;
	case Left: Headx--;
		break;
	}
	
	if (Heady >= m.Height || Heady <= 0 || Headx >= m.width || Headx <= 0)
		p.lose = true;
}
