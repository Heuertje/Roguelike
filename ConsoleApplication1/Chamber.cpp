#include "stdafx.h"
#include "Chamber.h"
#include <ctime>
#include "Randomizer.h"

//TODO: Requirement: 2000 Random chambers
Chamber::Chamber()
{
	item = new Item();
}

Chamber::~Chamber()
{

	// DisposeObject();
	
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
		//	chamberSymbol = 177;
			chamberSymbol = 'N';
			//  block symbol Dungeon
			break;
		case 1:	
			chamberType = "Vertical Hallway";
			chamberSymbol = 197;
		//	chamberSymbol = '|';
			// cross symbol Hallway
			break;
		case 2:
			chamberType = "Pitfall";
			chamberSymbol = ' ';
			// dark is pitfall
			break;
		case 3:
			chamberType = "Stairs Down";
	    //	chamberSymbol = 92;
			chamberSymbol = 'L';

			break;
			//  \ is stairs
		case 4:
			chamberType = "Stairs Up";
		//	chamberSymbol = 47;
			chamberSymbol = 'H';
			break;
			
		case 5:
			chamberType = "Horizontal Hallway";
			chamberSymbol = '-';
		//	chamberSymbol = 100;
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
	//GenerateRandomEnemyInChamber();
	GenerateRandomChamberDecorativeItems();
	GenerateRandomDescription();
}

void Chamber::GenerateRandomPickUp()
{
	//TODO: Generate random pick-up items for Hero
	//Memory leak line below


	item->setItemType(Randomizer::Instance().generateRandomNumber(50));

	//delete item;
	//TODO: Generate random pick-up items for Hero
}

void Chamber::GenerateRandomEnemyInChamber()
{
	//Memory leak line below
	enemy = new Enemy();
	//TODO: Do I have to make a new object of a enemy?? IMPORTANT!
	enemy->setEnemyType(Randomizer::Instance().generateRandomNumber(7));

	//move to destructor
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

void Chamber::PrintChamberItemDescription()
{
	cout << item->itemtype << endl;
}