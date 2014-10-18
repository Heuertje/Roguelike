#pragma once
class Action
{
public:
	Action();
	~Action();
	
	void Search();
	void UseItem();
	void PickUPItem();
	void DropItem();
	void checkInventory();
	void Rest();
	void ShowCharacterStatistics();

	//OPTIONAL-NOT A REQUIREMENT:Save/Load
	void SaveGame();
	//OPTIONAL-NOT A REQUIREMENT:Save/Load
	void LoadGame();

	void ShowMap();
};

