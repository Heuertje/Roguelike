// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <crtdbg.h>
#include "stdafx.h"
#include "Level.h"
#include "CheckInput.h"
#include <ctime>
#include "character.h"
#include "windows.h"
#include "LevelManager.h"
using namespace std;

bool gameloop = true;
bool isLevelOneCreated = false;
bool isLevelTwoCreated = false;
bool isLevelThreeCreated = false;

Level firstlevel;
Level secondLevel;
Level thirdLevel;
bool createLevelOne()
{
	
	firstlevel.SetCurrentLevel(1);
	firstlevel.SetLevelNumber(1);
	firstlevel.FillLevel();
	firstlevel.GenerateRandomPitFall();
	firstlevel.GenerateRandomStartLocation();
	firstlevel.GenerateRandomRandomStairs();

	firstlevel.PrintLevelNumber();
	firstlevel.PrintLevelDescription();
	firstlevel.PrintLevel();
	firstlevel.PrintLegend();
	firstlevel.PrintStartPosition();

	CheckInput::Instance().ChecksInput(firstlevel);
	Character::Instance().setstats();
	return true;
}

bool createLevelTwo()
{
	
	secondLevel.SetCurrentLevel(2);
	secondLevel.SetLevelNumber(2);
	secondLevel.FillLevel();
	secondLevel.GenerateRandomPitFall();
	secondLevel.GenerateRandomStartLocation();
	secondLevel.GenerateRandomRandomStairs();

	secondLevel.PrintLevelNumber();
	secondLevel.PrintLevelDescription();
	secondLevel.PrintLevel();
	secondLevel.PrintLegend();
	secondLevel.PrintStartPosition();


	CheckInput::Instance().ChecksInput(secondLevel);
	Character::Instance().setstats();
	return true;
}

bool createLevelThree()
{

	
	thirdLevel.SetCurrentLevel(3);
	thirdLevel.SetLevelNumber(3);
	thirdLevel.FillLevel();
	thirdLevel.GenerateRandomPitFall();
	thirdLevel.GenerateRandomStartLocation();
	thirdLevel.GenerateRandomRandomStairs();

	thirdLevel.PrintLevelNumber();
	thirdLevel.PrintLevelDescription();
	thirdLevel.PrintLevel();
	thirdLevel.PrintLegend();
	thirdLevel.PrintStartPosition();

	CheckInput::Instance().ChecksInput(thirdLevel);
	Character::Instance().setstats();
	return true;
}



int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 800 width, 100 height

	//vector<Level> mazeDungeons;

	std::srand((unsigned int)time(NULL));

	int selectedLevel = 1;


	cout << "WELCOME TO THE ROGUELIKE: 'MONSTER MAZE OF DIZZINESS' " << endl << endl 
		<< "Your great text-based adventure starts here! " << endl
		<< "You will encounter many hardships along your journey" << endl
		<< "Defeat the enemies and all two bosses in all three levels \n and honor glory shall be granted to you" << endl
		<< " The developing lords wish you lots of luck! " << endl
		<< " May the odds be with you!" << endl << endl;

	cout << " Press enter to continue! " << endl;
	
	cin.get();
	system("CLS");

	while (gameloop){


		switch (selectedLevel)
		{
		case 1: {
					if (isLevelOneCreated == false)
					{
						isLevelOneCreated = createLevelOne();
					}
					selectedLevel = firstlevel.CheckWhetherHeroReachedStairs();
			CheckInput::Instance().CheckingInput();
		
			break;
		}
		case 2:
		{
				  if (isLevelTwoCreated == false)
				  {
					  isLevelTwoCreated = createLevelTwo();
				  }
				  selectedLevel = secondLevel.CheckWhetherHeroReachedStairs();
			CheckInput::Instance().CheckingInput();
		
			break;
		}
		case 3: {
					if (isLevelThreeCreated == false)
					{
						isLevelThreeCreated = createLevelThree();
					}

			selectedLevel = thirdLevel.CheckWhetherHeroReachedStairs();
			CheckInput::Instance().CheckingInput();
			break;
		}

		}

		if (CheckInput::Instance().gameloop == false){
			return 0;
		}

		if (!Character::Instance().isAlive()){
			system("CLS");
			break;
		}
	}
	
	cout << "Game Over" << endl;
	main();
	return 0;
}
