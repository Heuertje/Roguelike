#pragma once

#include "Positie.h"

class Level
{

public:

	static const int x = 10;
	static const int y = 10;

	static const int row = 10;
	static const int collumn = 10;

	Positie startRuimte;

	static char world[row][collumn];




	Level();
	~Level();
	void Level::PrintLevel();
	void Level::PrintLegend();
	void Level::GenerateRandomStartLocation();
	void Level::FillAFullRow(int rowToFill);
	void Level::FillAFullCollumn(int collumnToFill);
	static void Level::FillSpecificPositionInDungeon(Positie Positie);
	static void Level::FillSpecificPositionInDungeon(int x, int y);

};

