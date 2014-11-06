#include "stdafx.h"
#include "Chamber.h"

#include "Randomizer.h"

//TODO: Requirement: 2000 Random chambers
Chamber::Chamber()
{
	
}



Chamber::~Chamber()
{

	// DisposeObject();
//	delete item;
//	delete enemy;
}

void Chamber::DisposeObject()
{
	delete this;
//	delete[] description;

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

bool Chamber::GetHeroStartPositionState()
{
	return dungeonHeroStartState;
}

void Chamber::PutStuffRandomlyInChamber()
{
	//TODO: Implement random chairs, tables, candles, in a chamber
	GenerateRandomPickUp();
	GenerateRandomEnemyInChamber();
	GenerateRandomChamberDecorativeItems();
	GenerateRandomDescription();
}

void Chamber::GenerateRandomPickUp()
{
	//TODO: Generate random pick-up items for Hero
	//Memory leak line below

//	int type = Randomizer::Instance().generateRandomNumber(3);

//	Item::setItemType(type);
	

	//TODO: Generate random pick-up items for Hero
//	item->setItemType(Randomizer::Instance().generateRandomNumber(3));
//	delete item;
}

void Chamber::GenerateRandomEnemyInChamber()
{
	//Memory leak line below
	enemy = new Enemy();
	//TODO: Do I have to make a new object of a enemy?? IMPORTANT!
	enemy->setEnemyType(Randomizer::Instance().generateRandomNumber(7));

	delete enemy;
}

void Chamber::GenerateRandomChamberDecorativeItems()
{
	//TODO: Implement random chairs and tables
	int a = Randomizer::Instance().generateRandomNumber(3);
	switch (a)
	{
	case 0: fourChairsExists = true; break;
	case 1: tableExists = true;
	case 2: fourChairsExists = true; tableExists = true;
	default:
		//nothing as default at the moment
		break;
	}
}

void Chamber::GenerateRandomDescription()
{
	//Memory leak line below
	description = Description::GenerateDescription();
} 

void Chamber::AssignDungeonAsHeroStartPosition()
{
	dungeonHeroStartState = true;
	heroStartDungeon = 'S';
	chamberSymbol = 'S';
	
}

void Chamber::PrintChamberDescription()
{
//	cout << description->descriptioninfo << endl;
	cout << description << endl;

}
