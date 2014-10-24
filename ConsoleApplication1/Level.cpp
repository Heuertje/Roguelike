#include "stdafx.h"
#include "Level.h"
#include <ctime>
#include "Chamber.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Level::Level()
{
	levelNumber = 0;

}

Level::~Level()
{
	delete newStairs;
	delete newStartChamber;
	delete newPitFall;
	delete newStairs;
	delete newChamber;
}

void Level::FillLevel()
{

	for (int n = 0; n < row; n++)
	{

		for (int m = 0; m < collumn; m++)
		{
			//	 world[n][m] = (n + 1)*(m + 1);
			// save hallways of dungeons in a array as well
			newChamber = new Chamber();
			newChamber->SetChamberType(0);
			levelMap[n][m] = *newChamber;

			//levelMap[n][m] = '.';


			//dungeonHallways[n][m] = ' ';
			free(newChamber);
		}
	}
}

void Level::PrintLevel()
{
	// Iterate through 2 dimensional array
	for (int n = 0; n < row; n++)
	{
		for (int m = 0; m < collumn; m++)
		{
			cout << levelMap[n][m].chamberSymbol;

			// Begin on new line if arrayLine has been reached
			//cout << ' ';
			if (m == collumn - 1)
			{
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

Position Level::GenerateRandomStartLocation()
{
	int a = std::rand() % row;
	int b = std::rand() % collumn;	
	newStartChamber = new Chamber();
	newStartChamber->AssignDungeonAsHeroStartPosition();
	levelMap[a][b] = *newStartChamber;
	//levelMap[a][b] = '.';
	//delete newStartChamber;
	startPosition = Position(a, b);
	free(newStartChamber);

	return startPosition;
}

void Level::GenerateRandomPitFall()
{
	 
	int a = std::rand() % row;
	int b = std::rand() % collumn;
	newPitFall = new Chamber();

	newPitFall->SetChamberType(2);
	levelMap[a][b] = *newPitFall;

	//levelMap[a][b] = ' ';

	free(newPitFall);
}

void Level::GenerateRandomRandomStairs()
{
	int a = std::rand() % row;
	int b = std::rand() % collumn;
	newStairs = new Chamber();

	newStairs->SetChamberType(3);
	levelMap[a][b] = *newStairs;

	free(newStairs);
}

void Level::FillAFullRow(int rowToFill)
{
	for (int i = 0; i < row; i++)
	{
	//	levelMap[rowToFill][i] = 'x';
	}
}

void Level::FillAFullCollumn(int collumnToFill)
{
	for (int i = 0; i < row; i++)
	{
	//	levelMap[i][collumnToFill] = 'y';
	}
}

void Level::FillSpecificPositionInDungeon(Position positie)
{
	levelMap[positie.x][positie.y];
}

void Level::FillSpecificPositionInDungeon(int x, int y)
{
	levelMap[x][y];
}

int Level::GetStartRuimteXPositie()
{
	return startPosition.x;
}

int Level::GetStartRuimteYPositie()
{
	return startPosition.y;
}

void Level::PrintStartPosition()
{
//	cout << "Start Position: " << startPosition.x << "," << startPosition.y << endl;
}

void Level::SetLevelNumber(int lvl)
{
	levelNumber = lvl;
}

void Level::PrintLevelNumber()
{
	//Memory leak below
//	cout << "Level: " << levelNumber << endl;
	cout << "Test" << endl;
}

void Level::CheckWhetherHeroReachedStairs()
{
	// If Hero position has reached the stairs:
	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 92)
	{
		cout << "Stairs Reached!" << endl;
	}
}

