#pragma once

#include "Positie.h"

class Level
{

public:

	static const int x = 10;
	static const int y = 10;

	Positie startRuimte;

	char world[x][y];




	Level();
	~Level();
	void Level::PrintLevel();
	void Level::PrintLegend();
	void Level::GenerateRandomStartLocation();
};

