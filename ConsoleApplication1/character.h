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


	~Character();


	static Character& Instance()
	{
		static Character    mInstance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return mInstance;
	}
	//static Character* mInstance;
	//static Character *Instance()
	//{
	//	if (mInstance == 0)
	//	{
	//		mInstance = new Character();
	//	}
	//	return mInstance;
	//}
	int checkxp();
	int checkHP();
	int increaselevel();
	int increaseattack(int x);
	int increasestrength(int x);
	int increasemaxhealth(int x);
	int increaseawareness(int x);
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


