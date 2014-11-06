#include "stdafx.h"
#include "checkinput.h"
#include <conio.h>
#include <stdlib.h>
#include "character.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Randomizer.h"


CheckInput::~CheckInput(){
	cout << "dfsg" << endl;
}

void CheckInput::CheckingInput(Level& lvl)
{
	input = "";
	gameloop = true;
	// Left = 0, Right = 1, Down = 2, Up = 3
	string input; 
	




	arrowcontrols = false;

	// Left = 0, Right = 1, Down = 2, Up = 3
	if (arrowcontrols)
	{
		while (1){
			if (_kbhit())
			{
				key_code = _getch();
				switch (key_code)
				{					
					//links 
				case 75: CheckInput::Walk(0);
					break;

					//rechts
				case 77:  CheckInput::Walk(1);
					break;

					//down
				case 80:  CheckInput::Walk(2);
					break;

					//up
				case 72:  CheckInput::Walk(3);
					break;

				}
			}
			// do stuff depending on key_code
			else
			{
				continue;
			}
		}
	}
	else
	{
		cout << "What do you want to be your next action? " << endl;
		getline(cin, input);

		for (int i = 0; i < input.length(); i++){ // input.length() gets the length of the string
			// convert every character of input to lowercase ( I think there are other methods to do this)
			input[i] = tolower(input[i]);
		}



		if (input == "up" || input == "u" || input == "north" || input == "n"){
			CheckInput::Instance().Walk(3);
		}
		else if (input == "down" || input == "d" || input == "south" || input == "s")
		{
			CheckInput::Instance().Walk(2);

		}
		else if (input == "left" || input == "l" || input == "west" || input == "w")
		{
			CheckInput::Instance().Walk(0);

		}
		else if (input == "right" || input == "r" || input == "east" || input == "e")
		{
			CheckInput::Instance().Walk(1);
		}
		else if (input == "mwuahaha")
		{
			Character::Instance().increaselevel();


		}
		else if (input == "checkstats" || input == "stats")
		{
			Character::Instance().checkstats();

		}
		else if (input == "checkhp" || input == "hp")
		{
			Character::Instance().checkHP();

		}
		else if (input == "quit" || input == "q"){
			gameloop = false;
		}
		else if (input == "showmap" || input == "level"){
			lvl.PrintLevel();
			lvl.PrintLegend();
			lvl.PrintStartPosition();
		}
		else if (input == "hpup"){
			Character::Instance().increasehealth(10);

		}
		else if (input == "hpdown"){
			Character::Instance().decreasehealth(10);

		}
		else if (input == "enemytest"){
			Enemy* rat = new Enemy();
			rat->setEnemyLevel();
			cout << "Enemy HP: " << rat->getEnemyHP() << endl;
			rat->EnemyData();
			delete rat;
		}
		else{
			cout << "Sorry, I didn't catch that command. Please try again.";
		}
	}

}
// Left = 0, Right = 1, Down = 2, Up = 3
void CheckInput::Walk(int direction)
{
	system("CLS");
	switch (direction)
	{

		case 0: //LEFT	
			lvl.PrintLevelNumber();
			
			//indicate current location
			if (lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
			{
				lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
			}
			else
			{
				
				lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
			}

			
			startPosition.y--;
			lvl.CheckWhetherHeroReachedStairs();
			lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
			
			//currentPosition is newly manipulated startPosition
			lvl.currentPosition = startPosition;
			
			// Limit Player from walking away from map
			if (startPosition.y <= 1)
			{
				startPosition.y = 1;
			}
			cout << "CASE 0: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
			lvl.PrintLevel();
			lvl.PrintLegend();
			lvl.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
			break;

		case 1:  //RIGHT
				
				lvl.PrintLevelNumber();
				
				if (lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
					
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}

				startPosition.y++;
				lvl.CheckWhetherHeroReachedStairs();
				
				lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				lvl.currentPosition = startPosition;
				if (startPosition.y >= 19-1)
				{
					startPosition.y = 19-1;
				}
				cout << "CASE 1: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				lvl.PrintLevel();
				lvl.PrintLegend();
		//	}
				lvl.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();

			break;

		case 2: //DOWN
				lvl.PrintLevelNumber();
				
				if (lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
				
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}

				startPosition.x++;
				lvl.CheckWhetherHeroReachedStairs();
				lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				lvl.currentPosition = startPosition;
				if (startPosition.x >= 19-1)
				{
					startPosition.x = 19-1;
				}
				cout << "CASE 2: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				lvl.PrintLevel();
				lvl.PrintLegend();
				lvl.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
			break;

		case 3: //UP

				lvl.PrintLevelNumber();
				
				if (lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
				{
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
				}
				else
				{
					
					lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
				}
				startPosition.x--;
				lvl.CheckWhetherHeroReachedStairs();

				lvl.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
				lvl.currentPosition = startPosition;
				if (startPosition.x <= 1)
				{
					startPosition.x = 1;
				}
				cout << " CASE 3: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
				lvl.PrintLevel();
				lvl.PrintLegend();
				lvl.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		//	}

		break;

	default:
		//Nothing implemented at the moment
		break;
	}
}

//void CheckInput::nextaction(){}

void CheckInput::SetStartPosition(Position value)
{
	startPosition = value;
}

