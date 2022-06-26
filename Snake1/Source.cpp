#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;
void ShiftRight(int arr[], int size)
{
	for(int i = size - 2; i >=0; i--)
		arr[i + 1] = arr[i];
}
struct Map
{
	int width, Height, fruitx, fruity;
};
struct Player
{
	int Score;
	bool lose;
};
enum Direction
{
	Top = 1, Down, Right, Left
};
struct Snake
{
	int Headx, Heady, Tail_n , TailX[50] , TailY[50]; Direction dir;
};
Map m;  Player p; Snake s;
void Generate_fruits()
{
	m.fruitx = rand() % (m.width - 2) + 1;
	m.fruity = rand() % (m.Height - 2) + 1;
}
void Setup()
{
	srand(time(NULL));
	m.width = 40;
	m.Height = 20;
	Generate_fruits();
	s.Headx = m.width / 2;
	s.Heady = m.Height / 2;
	s.Tail_n = 0;

	p.lose = false;
	p.Score = 0;
}
void input()
{
	if (_kbhit())
	{
		char c = _getch();
		switch (c)
		{
		case'w': s.dir = Top; break;
		case's': s.dir = Down; break;
		case'd': s.dir = Right; break;
		case'a': s.dir = Left; break;
		case'x': exit(0); break;
		}
	}
}
void Move()
{
	ShiftRight(s.TailX, 5);
	ShiftRight(s.TailY, 5);
	s.TailX[0] = s.Headx;
	s.TailY[0] = s.Heady;

	switch (s.dir)
	{
	case Top: s.Heady--;
		break;
	case Down: s.Heady++;
		break;
	case Right:s.Headx++;
		break;
	case Left: s.Headx--;
		break;
	}

	if (s.Heady >= m.Height || s.Heady <= 0 || s.Headx >= m.width || s.Headx <= 0)
		p.lose = true;
	if (s.Headx == m.fruitx && s.Heady == m.fruity)
	{
		Generate_fruits();
		p.Score += 1;
		s.Tail_n++;
	}
}   
void draw()
{
	system("cls");
	for (int i = 0; i < m.Height; i++)
	{
		for (int j = 0; j < m.width; j++)
		{
			if (i == 0 || i == m.Height - 1)
				cout << "*";
			else if (j == 0 || j == m.width - 1)
				cout << "*";
			else if (i == s.Heady && j == s.Headx)
				cout << "O";
			else if (i == m.fruity && j == m.fruitx)
				cout << "$";
			else
			{
				bool printed = false;
				for (size_t z = 0; z < s.Tail_n; z++)
				{
					if (s.TailX[z] == j && s.TailY[z] == i)
					{
						cout << "o";
						printed = true;
						break;
					}
				}
				if (!printed)
					cout << " ";
			}
		}
		cout << endl;

	}
	cout << "PLayer Score : " << p.Score << endl;
}
void main()
{
	Setup();
	while (!p.lose)
	{
		draw();
		input();
		Move();
		Sleep(100);
	}
	system("Pause");
}