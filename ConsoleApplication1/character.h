#pragma once

#include "stdafx.h"
#include "character.h"
#include <cstdlib>

class character
{
public:
	int checkxp();
	int increaselevel();
	int increaseattack(int x);
	int increasestrength(int x);
	int increasehealth(int x);
private:
	int xp = 0;
	int attack = 3;
	int strength = 3;
	int health = 30;
	int level = 1;
};


