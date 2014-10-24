#pragma once
#include "Description.h"
//TODO: Requirement: 30 opponents of which 2 are enemies


class Enemy : Description
{
public:

//	std::string enemyType;

	Enemy();
	~Enemy();
	void setEnemyType(int type);
};

