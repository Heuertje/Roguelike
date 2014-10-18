#include "stdafx.h"
#include "Chamber.h"

//TODO: Requirement: 2000 Random chambers
Chamber::Chamber()
{
	
}


Chamber::~Chamber()
{
	DisposeObject();
}

void Chamber::DisposeObject()
{
	delete this;
}
void Chamber::SetChamberType(int type)
{
	switch (type)
	{
		case 0:	
			chamberType = "Dungeon";	
			chamberSymbol = 177;
			break;
		case 1:	
			chamberType = "Hallway";
			chamberSymbol = 197;
			break;
		case 2:
			chamberType = "Pitfall";
			chamberSymbol = ' ';
			break;
		case 3:
			chamberType = "Stairs";
	     	chamberSymbol = 92;
			break;
			
		default:
			//Nothing as default type
		break;
	}
}

string Chamber::GetChamberType()
{
	return chamberType;
}

void Chamber::PutStuffRandomlyInChamber()
{
	//TODO: Implement random chairs, tables, candles, in a chamber
}

void Chamber::GenerateRandomPickUp()
{
	//TODO: Generate random pick-up items for Hero
}

void Chamber::GenerateRandomEnemiesInChamber()
{
	//TODO:Generate random enemies in a chamber
}

void Chamber::AssignDungeonAsHeroStartPosition()
{
	dungeonHeroStartState = true;
	heroStartDungeon = 'S';
	chamberSymbol = 'S';
	
}

bool Chamber::GetHeroStartPositionState()
{
	return dungeonHeroStartState;
}