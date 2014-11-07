#pragma once
#include "Enemy.h"
using namespace std;

class Combat
{
public:
	Combat();
	~Combat();
	void Attack();
	void RunAway(string direction);
	void drinkPotion();
	void useGrenade();
};

