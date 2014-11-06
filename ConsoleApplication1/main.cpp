// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "stdafx.h"
#include "Level.h"
#include "CheckInput.h"
#include <ctime>
#include "character.h"
#include "windows.h"

using namespace std;

#include <windows.h> 
#include <stdio.h> 

bool gameloop = true;



int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); // 800 width, 100 height

	//Memory leak: the [10] makes it have a multiplied amount of memory leaks
	//	Level MazeOfDungeons[10];



	std::srand((unsigned int)time(NULL));

	Level firstLevel;

	firstLevel.SetLevelNumber(1);
	firstLevel.PrintLevelDescription();
	firstLevel.FillLevel();
	firstLevel.GenerateRandomStartLocation();
	firstLevel.GenerateRandomPitFall();
	firstLevel.GenerateRandomRandomStairs();
	firstLevel.PrintLevelNumber();
	firstLevel.PrintLevel();
	firstLevel.PrintLegend();
	firstLevel.PrintStartPosition();

	Character::Instance().setstats();
	
	while (gameloop){
		CheckInput keyboard = CheckInput(firstLevel);
		if (keyboard.gameloop == false){
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
