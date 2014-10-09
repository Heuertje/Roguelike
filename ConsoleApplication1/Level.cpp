#include "stdafx.h"
#include "Level.h"
#include <time.h>

using namespace std;

Level::Level()
{
	for (int n = 0; n < x; n++)
	{

		for (int m = 0; m < y; m++)
		{
			//	 world[n][m] = (n + 1)*(m + 1);
			world[n][m] = '.';

		}
	}
}


Level::~Level()
{
}

void Level::PrintLevel()
{
	// Iterate through 2 dimension array
	for (int n = 0; n < x; n++)
	{
		for (int m = 0; m < y; m++)
		{
			cout << world[n][m];


			// Begin on new line if arrayLine has been reached
			cout << ' ';
			if (m == y - 1)
			{
				cout << endl;
				cout << endl;
			}
		}
	}
}

void Level::PrintLegend()
{
	cout << "Legenda:" << endl;
	cout << "| : Gangen" << endl;
	cout << "S : Start Locatie" << endl;
	cout << "E : Eind vijand" << endl;
	cout << "N : Normale Ruimte" << endl;
	cout << "L : Trap Omlaag" << endl;
	cout << "H : Trap Omhoog" << endl;
	cout << ". : Niet bezocht" << endl;
}

void Level::GenerateRandomStartLocation()
{
	std::srand((unsigned int)time(0)); // use current time as seed for random generator
	int a = std::rand() % x;
	int b = std::rand() % y;


	world[a][b] = 'S';
	startRuimte = Positie(a, b);
}

void Level::FillAFullRow(int rowToFill)
{
	for (int i = 0; i < row; i++)
	{
		world[rowToFill][i] = 'x';
	}
}
void Level::FillAFullCollumn(int collumnToFill)
{
	for (int i = 0; i < row; i++)
	{
		world[i][collumnToFill] = 'y';
	}
}

void Level::FillSpecificPositionInDungeon(Positie positie)
{
	world[positie.x][positie.y];
}

void Level::FillSpecificPositionInDungeon(int x, int y)
{
	world[x][y];
}

