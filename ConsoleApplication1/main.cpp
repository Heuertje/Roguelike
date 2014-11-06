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



int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 800 width, 100 height

	//vector<Level> mazeDungeons;


	std::srand((unsigned int)time(NULL));


	Level firstlevel;
	Level secondLevel;
	Level thirdLevel;

	int selectedLevel = firstlevel.SetCurrentLevel(1);
	

	//Prepare all levels first:

	firstlevel.SetLevelNumber(1);
	firstlevel.FillLevel();
	firstlevel.GenerateRandomPitFall();
	firstlevel.GenerateRandomStartLocation();
	firstlevel.GenerateRandomRandomStairs();
	

	secondLevel.SetLevelNumber(2);
	secondLevel.FillLevel();
	secondLevel.GenerateRandomPitFall();
	secondLevel.GenerateRandomStartLocation();
	secondLevel.GenerateRandomRandomStairs();

	thirdLevel.SetLevelNumber(3);
	thirdLevel.FillLevel();
	thirdLevel.GenerateRandomPitFall();
	thirdLevel.GenerateRandomStartLocation();
	thirdLevel.GenerateRandomRandomStairs();

	switch (selectedLevel)
	{
	case 1:
		firstlevel.PrintLevelNumber();
		firstlevel.PrintLevelDescription();
		firstlevel.PrintLevel();
		firstlevel.PrintLegend();
		firstlevel.PrintStartPosition();

		break;


	case 2:

		secondLevel.PrintLevelNumber();
		secondLevel.PrintLevelDescription();
		secondLevel.PrintLevel();
		secondLevel.PrintLegend();
		secondLevel.PrintStartPosition();

		break;

	case 3:


		thirdLevel.PrintLevelNumber();
		thirdLevel.PrintLevelDescription();
		thirdLevel.PrintLevel();
		thirdLevel.PrintLegend();
		thirdLevel.PrintStartPosition();

		break;
	}




	CheckInput::Instance().CheckingInput(firstlevel);
	Character::Instance().setstats();
	while (gameloop){

		switch (selectedLevel)
		{
		case 1: {
			CheckInput::Instance().CheckingInput(firstlevel);
			break;
		}
		case 2:
		{
			CheckInput::Instance().CheckingInput(secondLevel);
			break;
		}
		case 3: {
			CheckInput::Instance().CheckingInput(thirdLevel);
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
