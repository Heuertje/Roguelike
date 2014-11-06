#include "stdafx.h"
#include "checkinput.h"
//#include <conio.h>
//#include <stdlib.h>
#include "character.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Randomizer.h"
CheckInput::CheckInput()
{

}
CheckInput::~CheckInput(){}

CheckInput::CheckInput(Level& lvl)
{
	level = lvl;
	input = "";
	gameloop = true;
	// Left = 0, Right = 1, Down = 2, Up = 3
	string input; 
	


		cout << "What do you want to be your next action? " << endl;
		getline(cin, input);

		for (int i = 0; i < input.length(); i++){ // input.length() gets the length of the string
			// convert every character of input to lowercase ( I think there are other methods to do this)
			input[i] = tolower(input[i]);
		}



		if (input == "up" || input == "u" || input == "north" || input == "n"){
			CheckInput::Walk(3);
		}
		else if (input == "down" || input == "d" || input == "south" || input == "s")
		{
			CheckInput::Walk(2);

		}
		else if (input == "left" || input == "l" || input == "west" || input == "w")
		{
			CheckInput::Walk(0);

		}
		else if (input == "right" || input == "r" || input == "east" || input == "e")
		{
			CheckInput::Walk(1);
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
		else if (input == "quit" || input == "q" ){
			gameloop = false;
		}
		else if (input == "showmap" || input == "level"){
			level.PrintLevel();
			level.PrintLegend();
			level.PrintStartPosition();
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
// Left = 0, Right = 1, Down = 2, Up = 3
void CheckInput::Walk(int direction)
{
	switch (direction)
	{
	case 0: //LEFT



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


		startPosition.y--;
		level.CheckWhetherHeroReachedStairs();
		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';

		//currentPosition is newly manipulated startPosition
		level.currentPosition = startPosition;

		// Limit Player from walking away from map
		if (startPosition.y <= 1)
		{
			startPosition.y = 1;
		}
		cout << "CASE 0: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
		level.PrintLevel();
		level.PrintLegend();
		level.PrintStartPosition();
		level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		break;

	case 1:  //RIGHT

		system("CLS");
		level.PrintLevelNumber();

		if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
		{
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
		}
		else
		{

			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
		}

		startPosition.y++;
		level.CheckWhetherHeroReachedStairs();

		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
		level.currentPosition = startPosition;
		if (startPosition.y >= 19 - 1)
		{
			startPosition.y = 19 - 1;
		}
		cout << "CASE 1: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
		level.PrintLevel();
		level.PrintLegend();
		level.PrintStartPosition();
		level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();

		break;

	case 2: //DOWN
		system("CLS");
		level.PrintLevelNumber();

		if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
		{
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
		}
		else
		{

			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
		}

		startPosition.x++;
		level.CheckWhetherHeroReachedStairs();
		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
		level.currentPosition = startPosition;
		if (startPosition.x >= 19 - 1)
		{
			startPosition.x = 19 - 1;
		}
		cout << "CASE 2: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
		level.PrintLevel();
		level.PrintLegend();
		level.PrintStartPosition();
		level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
		break;

	case 3: //UP

		system("CLS");
		level.PrintLevelNumber();

		if (level.levelMap[startPosition.x][startPosition.y].chamberSymbol == 'S')
		{
			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'S';
		}
		else
		{

			level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'o';
		}
		startPosition.x--;
		level.CheckWhetherHeroReachedStairs();

		level.levelMap[startPosition.x][startPosition.y].chamberSymbol = 'x';
		level.currentPosition = startPosition;
		if (startPosition.x <= 1)
		{
			startPosition.x = 1;
		}
		cout << " CASE 3: Coordinates: " << startPosition.x << "," << startPosition.y << endl;
		level.PrintLevel();
		level.PrintLegend();
		level.PrintStartPosition();
		level.levelMap[startPosition.x][startPosition.y].PrintChamberDescription();
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

