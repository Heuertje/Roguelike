#pragma once

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Gear.h"
using namespace std;

class Character
{

public:
	int level;
	int health;
	int maxhealth;
	int xp;
	int attack;
	int strength;
	int awareness;
	int defense;
	~Character();
	static Character& Instance()
	{
		static Character    mInstance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return mInstance;
	}

	void checkstats();
	int checkxp();
	int checkHP();
	
	int getDef();
	int getAttack();
	int getlevel();
	int getHealth();
	int getStrength();
	int getXp();
	void setstats();

	int increasexp(int x);
	int increaselevel();
	int increaseattack(int x);
	int increasedefense(int x);
	int increasestrength(int x);
	int increasemaxhealth(int x);
	int increasehealth(int x);
	int increaseawareness(int x);

	int decreasehealth(int x);
	
	bool isAlive();
	Item getItemFromInventory(int itemLocation);

private:
	string name;
	Inventory inventory;
	Gear* gear;
	Character() {}                   // Constructor? (the {} brackets) are needed here.
	// Dont forget to declare these two. You want to make sure they
	// are unaccessable otherwise you may accidently get copies of
	// your singleton appearing.
	Character(Character const&);              // Don't Implement
	void operator=(Character const&); // Don't implement


};


