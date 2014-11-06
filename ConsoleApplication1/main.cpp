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
#include "LevelManager.h"
using namespace std;

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 800 width, 100 height

	//Memory leak: the [10] makes it have a multiplied amount of memory leaks
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


	

	//Character Bas = Character();
	//Bas.increaselevel();
	//Bas.increaselevel();
	//Bas.increaselevel();
	CheckInput*keyboard = new CheckInput(firstlevel);

	

	//int x;
	//cin >> x;
	//cout << "you entered" << x << endl;
	//cin.clear();
	//cin.ignore(255, '\n');
	//cin.get();
	//while (true){
	//	
	//}

	return 0;
}
