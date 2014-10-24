#include "stdafx.h"
#include "Enemy.h"

#include "Description.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::setEnemyType(int type)
{
	switch (type)
	{
	case 0: descriptioninfo = "A shiny monster"; break;
	case 1: descriptioninfo = "A stupid dwarf"; break;
	case 2: descriptioninfo = "A holy but useless magician"; break;
	case 3: descriptioninfo = "A stinky fart"; break;
	case 4: descriptioninfo = "Sauron, but smaller"; break;
	case 5: descriptioninfo = "Gandalf, but bigger, shaven, has better sense of fashion, with a walking stick in a wheelchair."; break;
	case 6: descriptioninfo = "Evil Harry Potter"; break;
	}
}
