#include "stdafx.h"
#include "Enemy.h"

#include "Description.h"
#include "character.h"
#include "Randomizer.h"
Enemy::Enemy()
{
	dead = false;
	isBoss = false;
	Enemy::setEnemyStats();
	descriptioninfo = Enemy::setEnemyType(Randomizer::Instance().generateRandomNumber(6));

}



Enemy::~Enemy()
{

}

bool Enemy::isdead(){
	if (enemyHealth < 1){
		dead = true;
		Character::Instance().increasexp(enemyMaxHealth);
	}
	return dead;
}
void Enemy::attackme(){
	int attdefdiff = Character::Instance().getDef() - enemyAttack;
	int damage = Randomizer::Instance().generateRandomNumber(Character::Instance().getAttack() + Character::Instance().getStrength()) + Character::Instance().getAttack();
	damage = damage * (enemyDefense / 10);
	Character::Instance().decreasehealth(damage);
}
void Enemy::meattack(){
	int attdefdiff = enemyDefense - Character::Instance().getAttack();
	int damage = Randomizer::Instance().generateRandomNumber(enemyAttack + enemyStrength) + enemyAttack;
	damage = damage * 2 - (Character::Instance().getDef() / 10);
	Enemy::decreaseEnemyHP(damage);
	cout << "You just hit " << Enemy::getEnemyName() << " and you did " << damage << " damage." << endl;
}

void Enemy::setEnemyStats(){
	enemyLevel = 0;
	enemyMaxHealth = 5;
	enemyHealth = enemyMaxHealth;
	enemyAttack = 2;
	enemyDefense = 2;
	enemyStrength = 1;
}
void Enemy::setEnemyLevel(){
	int charlevel = Character::Instance().getlevel();
	if (isBoss){
		charlevel += (charlevel / 2);
	}
	for (int i = 0; i <= charlevel; i++){
		Enemy::increaseEnemyLevel();
	}
}

void Enemy::EnemyData(){
	cout << endl <<"You are Facing a " << descriptioninfo << endl
		<< "This badass got the following stats:" << endl
		<< "Level " << enemyLevel << ", Health" << enemyHealth << endl;
}

string Enemy::getEnemyName(){
	return descriptioninfo;
}
int Enemy::decreaseEnemyHP(int x){
	enemyHealth -= x;
	cout << "The enemy now has " << enemyHealth << " left." << endl;
	Enemy::isdead();
	return enemyHealth;
}
int Enemy::getEnemyHP(){
	return enemyHealth;
}
int Enemy::getEnemyLevel(){
	return enemyLevel;
}

int Enemy::getEnemyDef(){
	return enemyDefense;
}
int Enemy::getEnemyAttack(){
	return enemyAttack;
}
int Enemy::getEnemyStrength(){
	return enemyStrength;
}

void Enemy::increaseEnemyLevel(){
	enemyLevel += 1;
	int increasehealth = Randomizer::Instance().generateRandomNumber(8)+1;
	enemyMaxHealth += increasehealth;
	
	enemyHealth += increasehealth;
	enemyAttack = Randomizer::Instance().generateRandomNumber(3)+1;
	enemyDefense = Randomizer::Instance().generateRandomNumber(3)+1;
	enemyStrength = Randomizer::Instance().generateRandomNumber(3)+1;
}

string Enemy::setEnemyType(int type)
{
	switch (type)
	{
	case 0: descriptioninfo = "shiny monster"; break;
	case 1: descriptioninfo = "stupid dwarf"; break;
	case 2: descriptioninfo = "holy but useless magician"; break;
	case 3: descriptioninfo = "stinky fart"; break;
	case 4: descriptioninfo = "small, tiny living rock"; break;
	case 5: descriptioninfo = "living smartphone"; break;
	case 6: descriptioninfo = "Evil Harry Potter"; break;
	default: descriptioninfo = "Unknown Enemy";
	}
	return descriptioninfo;
}
