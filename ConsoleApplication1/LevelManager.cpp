#include "stdafx.h"
#include "LevelManager.h"



LevelManager::~LevelManager()
{
}

int LevelManager::GetCurrentLevel()
{
	return currentLevel;
}

void LevelManager::SetCurrentLevel(int newLevel)
{
	currentLevel = newLevel;
}
