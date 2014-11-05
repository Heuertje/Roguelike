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

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); // 800 width, 100 height

	//Memory leak: the [10] makes it have a multiplied amount of memory leaks
	vector<Level> mazeDungeons;


	Level firstlevel;

	firstlevel.SetLevelNumber(1);
	firstlevel.FillLevel();


	if (firstlevel.levelNumber == 1)
	{
		firstlevel.GenerateRandomPitFall();
		firstlevel.GenerateRandomStartLocation();
		firstlevel.GenerateRandomRandomStairs();
	}

	firstlevel.PrintLevelNumber();
	firstlevel.PrintLevel();
	firstlevel.PrintLevelDescription();
	firstlevel.PrintLegend();
	firstlevel.PrintStartPosition();
	

	std::srand((unsigned int)time(NULL));


	//Character Bas = Character();
	//Bas.increaselevel();
	//Bas.increaselevel();
	//Bas.increaselevel();
	CheckInput keyboard = CheckInput(firstlevel);

	

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
