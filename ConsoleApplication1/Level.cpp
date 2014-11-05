#include "stdafx.h"
#include "Level.h"
#include <ctime>
#include "Chamber.h"

#include <iostream>
#include <string>
#include <sstream>

#include "Randomizer.h"
using namespace std;

Level::Level()
{
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
			

			Chamber* newChamber = new Chamber();
			newChamber->SetChamberType(0);
			newChamber->PutStuffRandomlyInChamber();
			levelMap[n][m] = *newChamber;
			
			//levelMap[n][m] = '.';
			delete newChamber;

			//dungeonHallways[n][m] = ' ';
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
	
	int x = Randomizer::mInstance->generateRandomRow(row);
	int y = Randomizer::mInstance->generateRandomRow(collumn);

	Chamber* newStartChamber = new Chamber();

	newStartChamber->AssignDungeonAsHeroStartPosition();
	newStartChamber->PutStuffRandomlyInChamber();

	levelMap[x][y] = *newStartChamber;
	delete newStartChamber;
	
	startPosition = Position(x, y);
	return startPosition;
}

void Level::GenerateRandomPitFall()
{
	 

	Chamber* newPitFall = new Chamber();
	int x = Randomizer::mInstance->generateRandomRow(row);
	int y = Randomizer::mInstance->generateRandomRow(collumn);

	newPitFall->SetChamberType(2);
	newPitFall->PutStuffRandomlyInChamber();
	levelMap[x][y] = *newPitFall;
	delete newPitFall;
}

void Level::GenerateRandomRandomStairs()
{
	int x = Randomizer::mInstance->generateRandomRow(row);
	int y = Randomizer::mInstance->generateRandomRow(collumn);

	Chamber* newStairs = new Chamber();

	newStairs->SetChamberType(3);
	newStairs->PutStuffRandomlyInChamber();
	levelMap[x][y] = *newStairs;
	delete newStairs;
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
	cout << "Start Position: " << startPosition.x << "," << startPosition.y << endl;

	//TODO: ALSO print Start position chamber description
 levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
}

void Level::SetLevelNumber(int lvl)
{
	levelNumber = lvl;
}

void Level::PrintLevelNumber()
{
	cout << "Level: " << levelNumber << endl;
}

void Level::CheckWhetherHeroReachedStairs()
{
	// If Hero position has reached the stairs:
	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 92)
	{
		cout << "Stairs Reached!" << endl;
	}
}

void Level::PrintLevelDescription()
{
	cout << "Welcome to the Level 1: Ruins of the Lost" << endl;
}
