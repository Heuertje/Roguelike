#pragma once

#include "Description.h"
//TODO: Requirement: 30 opponents of which 2 are enemies


class Enemy : Description
{
public:
	static Enemy& Instance(){
		static Enemy mInstance;
		return mInstance;
	}
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
	bool gotxp;
	string descriptioninfo;
	void newEnemy();
	void resetEnemy();
	void setEnemyStats();
	void setEnemyLevel();
	void increaseEnemyLevel();
	void generateEnemyStats();
	
	bool isdead();
	void attackMe();
	void Iattack();


	string getEnemyName();
	int getEnemyHP();
	int getEnemyLevel();
	int getEnemyDef();
	int getEnemyAttack();
	int getEnemyStrength();
	void EnemyData();
	
	int decreaseEnemyHP(int x);
	~Enemy();
	string setEnemyType(int type);
	void CreateEnemyAmount();

	
private:
	Enemy(){}
	Enemy(Enemy const&);
	void operator=(Enemy const&);
};

