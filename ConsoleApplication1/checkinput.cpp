#include "stdafx.h"
#include "checkinput.h"
#include <conio.h>
#include <stdlib.h>
#include "character.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Randomizer.h"
#include "Combat.h"
#include "Chamber.h"
CheckInput::~CheckInput(){
//	for (int i = 0; i < )
//	delete rat;

}

void CheckInput::ChecksInput(Level& lvl){
	level = lvl;
	lvl = lvl;
}
void CheckInput::CheckingInput()
{
	//while gameloop
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
			level.PrintLevel();
			level.PrintLegend();
			level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		}
		else if (input == "hpup"){
			Character::Instance().increasehealth(10);

		}
		else if (input == "hpdown"){
			Character::Instance().decreasehealth(10);

		}
		else if (input == "xp"){
			Character::Instance().getXp();

		}
		else if (input == "h" || input == "help"){
			cout << "The commands for this game are as following:" << endl 
				<< "Move trough rooms: [N]orth, [S]outh, [E]ast, [W]est " << endl
				<< "To show the world: [S]howmap" <<endl
				<< "To check your own stats: [Check]Stats " <<endl
				<< "Leaving the game [Q]uit" << endl;

		}
		else if (input == "attack"){
			system("CLS");

			if (!Enemy::Instance().isdead()){
				Enemy::Instance().attackMe();
				Enemy::Instance().Iattack();
				if (Enemy::Instance().isdead()){
					cout << "You just killed a " << Enemy::Instance().getEnemyName() << endl;
				}
			}
			
			else{
				cout << "There is no enemy to attack. Please use another command " << endl;
				cout << "Type: [H]elp for more commands. " << endl;

			}
		}
		else{
			cout << "Sorry, I didn't catch that command. Please try again. " <<endl;
			cout << "Type: [H]elp for more commands. " << endl;

		}
	}

}

//		




// Left = 0, Right = 1, Down = 2, Up = 3
void CheckInput::Walk(int direction)
{
	system("CLS");
	level.PrintLevelNumber();
	//indicate current location
	if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
	{
		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
	}
	else
	{
		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
	}
		switch (direction)
		{
		case 0: //LEFT
			startPosition.y--;
			level.CheckWhetherHeroReachedStairs();
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'X';
			//currentPosition is newly manipulated startPosition
			level.currentPosition = startPosition;
			// Limit Player from walking away from map
			if (startPosition.y <= 1)
			{
				startPosition.y = 1;
			}
			//			level.levelMap[startPosition.x][startPosition.y].PrintChamberItemDescription();
			break;
		case 1: //RIGHT
			startPosition.y++;
			level.CheckWhetherHeroReachedStairs();
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'X';
			level.currentPosition = startPosition;
			if (startPosition.y >= 19 - 1)
			{
				startPosition.y = 19 - 1;
			}
			//			level.levelMap[startPosition.x][startPosition.y].PrintChamberItemDescription();
			break;
		case 2: //DOWN
			startPosition.x++;
			level.CheckWhetherHeroReachedStairs();
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'X';
			level.currentPosition = startPosition;
			if (startPosition.x >= 19 - 1)
			{
				startPosition.x = 19 - 1;
			}
			//			level.levelMap[startPosition.x][startPosition.y].PrintChamberItemDescription();
			break;
		case 3: //UP
			startPosition.x--;
			level.CheckWhetherHeroReachedStairs();
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'X';
			level.currentPosition = startPosition;
			if (startPosition.x <= 1)
			{
				startPosition.x = 1;
			}
			//			level.levelMap[startPosition.x][startPosition.y].PrintChamberItemDescription();
			break;
		default:
			//Nothing implemented at the moment
			break;
		}
	
		cout << " You are now at location " << startPosition.x << "," << startPosition.y << endl;
		level.PrintLevel();
		level.PrintLegend();
		level.PrintStartPosition();

		level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		Enemy::Instance().newEnemy();
	
}


void CheckInput::SetStartPosition(Position value)
{
	startPosition = value;
}