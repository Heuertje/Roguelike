#pragma once

#include "Position.h"
#include "Chamber.h"
class Level
{

public:

	//  int x = 10;
	//  int y = 10;

	 static const int row = 20;
	 static const int collumn = 20;
	
	 Position startPosition;
	 Position currentPosition;
	// static const int dungeonRowSize = 20;
	// static const int dungeonCollumnSize = 20;

	// char dungeon[dungeonRowSize][dungeonCollumnSize];
	 //char rooms[row][collumn];
	   Chamber levelMap[20][20];

	// char rooms[10][10];
	// char dungeonHallways[row][collumn];
	   int levelNumber = 0;

	 Level();
	~Level();
	 void FillLevel();
	 void PrintLevel();
	 void  PrintLegend();
	 Position  GenerateRandomStartLocation();
	 void GenerateRandomPitFall();
	 void GenerateRandomRandomStairs();
	 void  FillAFullRow(int rowToFill);
	 void  FillAFullCollumn(int collumnToFill);
	 void  FillSpecificPositionInDungeon(Position Positie);
	 void  FillSpecificPositionInDungeon(int x, int y);
	 int  GetStartRuimteXPositie();
	 int  GetStartRuimteYPositie();
	 void PrintStartPosition();
	 void SetLevelNumber(int lvl);
	 void PrintLevelNumber();
	 void CheckWhetherHeroReachedStairs();
	 void PrintLevelDescription();
	
};

