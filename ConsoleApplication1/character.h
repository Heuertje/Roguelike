#pragma once

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Gear.h"
using namespace std;

class Character
{

	private:
	string name;
	int level = 1;
	int health = 30;
	int xp = 0;
	int attack = 3;
	int strength = 3;
	int awareness = 0;
	Inventory inventory;
	Gear* gear;
	
	

	public:
		Character();
		~Character();
		int checkxp();
	int checkxp();
	int checkHP();
	int increaselevel();
	int increaseattack(int x);
	int increasestrength(int x);
	int increasemaxhealth(int x);
	int increaseawareness(int x);
	Item getItemFromInventory(int itemLocation);
};


