#include "stdafx.h"
#include "Level.h"
#include <ctime>
#include "Chamber.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Randomizer.h"
#include "LevelManager.h"

using namespace std;

Level::Level()
{
	currentLevel = 0;
}

Level::~Level()
{
	cout << " test" << endl;
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
			newChamber->SetChamberType(Randomizer::Instance().generateRandomNumber(3));

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

//Generate and Assign Start Position to hero
Position Level::GenerateRandomStartLocation()
{
	
	int x = Randomizer::Instance().generateRandomRow(row);
	int y = Randomizer::Instance().generateRandomRow(collumn);

	Chamber* newStartChamber = new Chamber();

	newStartChamber->AssignDungeonAsHeroStartPosition();
	newStartChamber->PutStuffRandomlyInChamber();

	levelMap[x][y] = *newStartChamber;
	delete newStartChamber;
	
	startPosition.x = x;
	startPosition.y = y;

	return startPosition;
}

void Level::GenerateRandomPitFall()
{
	 

	Chamber* newPitFall = new Chamber();
	int x = Randomizer::Instance().generateRandomRow(row);
	int y = Randomizer::Instance().generateRandomRow(collumn);

	newPitFall->SetChamberType(2);
	newPitFall->PutStuffRandomlyInChamber();
	levelMap[x][y] = *newPitFall;
	delete newPitFall;
}

void Level::GenerateRandomRandomStairs()
{


	int x = Randomizer::Instance().generateRandomRow(row);
	int y = Randomizer::Instance().generateRandomRow(collumn);


	//int x2 = Randomizer::mInstance.generateRandomRow(row);
	//int y2 = Randomizer::mInstance.generateRandomRow(collumn);

	int x2 = 12;
	int y2 = 6;

	Chamber* newStairs = new Chamber();

	switch (levelNumber)
	{

	case 1:
	{
			  //Level 1 Stairs Down ONLY
			  newStairs->SetChamberType(3);
			  newStairs->PutStuffRandomlyInChamber();
			  levelMap[x][y] = *newStairs;
			  delete newStairs;
			  break;
	}

	case 2:
	{
			  //Level 2 Stairs Down and Up
			  newStairs->SetChamberType(3);
			  newStairs->PutStuffRandomlyInChamber();
			  levelMap[x][y] = *newStairs;
			  delete newStairs;

			  Chamber*secondStairs = new Chamber();
			  secondStairs->PutStuffRandomlyInChamber();
			  secondStairs->SetChamberType(4);
			  levelMap[x2][y2] = *secondStairs;
			  delete secondStairs;
	}
		break;


	case 3:
	{
			  //Level 3 Stairs Up
			  newStairs->SetChamberType(4);
			  newStairs->PutStuffRandomlyInChamber();
			  levelMap[5][8] = *newStairs;
			  delete newStairs;
			  break;
	}

		//newStairs.PutStuffRandomlyInChamber();
	}

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
 //levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
}

void Level::SetLevelNumber(int lvl)
{
	levelNumber = lvl;
}

void Level::PrintLevelNumber()
{
	cout << "Level: " << levelNumber << endl;
}

int Level::CheckWhetherHeroReachedStairs()
{
	// If Hero position has reached the (down) stairs:
	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 'L')
	{
		cout << "Stairs Down Reached!" << endl;
		// Level++
		currentLevel++;
		LevelManager::Instance().SetCurrentLevel(currentLevel);
		return currentLevel;
		// Print Current Level
		// Print other descriptions

	}

	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 'H')
	{
		cout << "Stairs UP Reached!" << endl;
		// Level--
		// Print Current Level
		// Print other descriptions
		currentLevel--;
		LevelManager::Instance().SetCurrentLevel(currentLevel);
		return currentLevel;
	}


	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 92)
	{
		cout << "Stairs Down Reached!" << endl;
		currentLevel++;
		// Level++
		// Print Current Level
		// Print other descriptions
		return currentLevel;
	}

	if (levelMap[startPosition.x][startPosition.y].chamberSymbol == 47)
	{
		cout << "Stairs UP Reached!" << endl;
		currentLevel--;
		// Level--
		// Print Current Level
		// Print other descriptions
		return currentLevel;
	}

	return currentLevel;
}

void Level::PrintLevelDescription()
{
	cout << "Welcome to the Level: " << levelNumber << endl;
}

int Level::SetCurrentLevel(int setLevel){

	currentLevel = setLevel;

	return currentLevel;
}

void Level::SetHeroCurrentPosition(Position currentPosition){


}

