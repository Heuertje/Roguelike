#pragma once
#include "Description.h"
#include "Enemy.h"
#include "Item.h"
using namespace std;

class Chamber : Description
{
public:

	
	string chamberType;
	unsigned char chamberSymbol;
	char heroStartDungeon;

	bool dungeonHeroStartState = false;

	//Stochastic Chamber Elements:
	Description* description;
	Enemy* enemy;
	Item* item; // sword, potion, holy grenade)
	bool fourChairsExists = false;
	bool tableExists = false;




	Chamber();
	~Chamber();
	void DisposeObject();
	void SetChamberType(int type);
	string GetChamberType();

	bool GetHeroStartPositionState();

	void PutStuffRandomlyInChamber();
	void GenerateRandomPickUp();
	void GenerateRandomEnemyInChamber();
	void GenerateRandomChamberDecorativeItems();
	void GenerateRandomDescription();
	void AssignDungeonAsHeroStartPosition();
	void PrintChamberDescription();
};

