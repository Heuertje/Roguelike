#pragma once
#include "Description.h"
using namespace std;

class Chamber
{
public:

	Description description;
	string chamberType;
	unsigned char chamberSymbol;
	char heroStartDungeon;
	bool dungeonHeroStartState = false;



	Chamber();
	~Chamber();
	void DisposeObject();
	void SetChamberType(int type);
	string GetChamberType();
	void PutStuffRandomlyInChamber();
	void GenerateRandomPickUp();
	void GenerateRandomEnemiesInChamber();

	void AssignDungeonAsHeroStartPosition();
	bool GetHeroStartPositionState();
};

