#pragma once

#include "Position.h"
#include "Chamber.h"
class Level
{
private:
	Chamber* newStairs;
	Chamber* newPitFall;
	Chamber* newStartChamber;
	Chamber* newChamber;

public:

	 static const int row = 20;
	 static const int collumn = 20;

	 Position startPosition;
	 Position currentPosition;

	 Chamber levelMap[20][20];
	 int levelNumber;

	 Level();
	 Level(int levelNumber);
	~Level();
	 void FillLevel();
	 void PrintLevel();
	 void  PrintLegend();
	 Position  GenerateRandomStartLocation();
	 void GenerateRandomPitFall();
	 void GenerateRandomRandomStairs();
	 void FillAFullRow(int rowToFill);
	 void FillAFullCollumn(int collumnToFill);
	 void FillSpecificPositionInDungeon(Position Positie);
	 void FillSpecificPositionInDungeon(int x, int y);
	 int  GetStartRuimteXPositie();
	 int  GetStartRuimteYPositie();
	 void PrintStartPosition();
	 void SetLevelNumber(int lvl);
	 void PrintLevelNumber();
	 void CheckWhetherHeroReachedStairs();
	 void PrintLevelDescription();
	 bool LevelSelected(bool isSelected);
	 void SetHeroCurrentPosition(Position currentPosition);
	
};

