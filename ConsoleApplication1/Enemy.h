#pragma once

#include "Description.h"
//TODO: Requirement: 30 opponents of which 2 are enemies


class Enemy : Description
{
public:

	int Health;
	int Power;
	int AttackPoints;
	bool dead;
//	std::string enemyType;
	bool isBoss;
	int enemyMaxHealth;
	int enemyHealth;
	int enemyAttack;
	int enemyDefense;
	int enemyLevel;
	int enemyStrength;
	string descriptioninfo;
	void setEnemyStats();
	void setEnemyLevel();
	void increaseEnemyLevel();
	void generateEnemyStats();
	
	bool isdead();
	void attackme();
	void meattack();


	string getEnemyName();
	int getEnemyHP();
	int getEnemyLevel();
	int getEnemyDef();
	int getEnemyAttack();
	int getEnemyStrength();
	void EnemyData();
	
	int decreaseEnemyHP(int x);
	Enemy();
	~Enemy();
	string setEnemyType(int type);
	void CreateEnemyAmount();
};

