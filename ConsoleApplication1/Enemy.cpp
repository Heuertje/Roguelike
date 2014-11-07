#include "stdafx.h"
#include "Enemy.h"

#include "Description.h"
#include "character.h"
#include "Randomizer.h"


Enemy::~Enemy()
{

}

void Enemy::newEnemy(){
	dead = false;
	gotxp = false;
	Enemy::Instance().setEnemyStats();
	Enemy::Instance().setEnemyType(Randomizer::Instance().generateRandomNumber(30));
	Enemy::Instance().setEnemyLevel();
	//cout << "Enemy HP: " << Enemy::Instance().getEnemyHP() << endl;
	Enemy::Instance().EnemyData();
}
void Enemy::resetEnemy(){
	dead = false;
	isBoss = false;
	Enemy::setEnemyStats();
	descriptioninfo = Enemy::Instance().setEnemyType(Randomizer::Instance().generateRandomNumber(30));

}
bool Enemy::isdead(){
	if (enemyHealth < 1){
		dead = true;
		if (!gotxp){
			Character::Instance().increasexp(enemyMaxHealth);
			gotxp = true;
		}
	}
	return dead;
}

//TODO put in combat
void Enemy::attackMe(){
	int attdefdiff = Character::Instance().getDef() - enemyAttack;
	int damage = 2+ Randomizer::Instance().generateRandomNumber(Character::Instance().getAttack() + Character::Instance().getStrength()) + Character::Instance().getAttack();
	damage = (damage / Character::Instance().getDef());
	if (damage > 0){
		cout << endl << "I just got hit " << damage << " by a " << Enemy::Instance().getEnemyName() << endl;
	}
	Character::Instance().decreasehealth(damage);
}
void Enemy::Iattack(){
	int attdefdiff = enemyDefense - Character::Instance().getAttack();
	int damage = Randomizer::Instance().generateRandomNumber(enemyAttack + enemyStrength) + enemyAttack;
	damage = (damage * 2 - (Character::Instance().getDef() / 10))/2;
	cout << "You just hit " << Enemy::Instance().getEnemyName() << " and you did " << damage << " damage." << endl;
	Enemy::Instance().decreaseEnemyHP(damage);
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
		Enemy::Instance().increaseEnemyLevel();
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
	cout << "The " << Enemy::Instance().getEnemyName() << " now has " << enemyHealth << " HP left." << endl;
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
	case 7: descriptioninfo = "shiny monster"; break;
	case 8: descriptioninfo = "stupid dwarf"; break;
	case 9: descriptioninfo = "holy but useless magician"; break;
	case 10: descriptioninfo = "dirty pikachu"; break;
	case 11: descriptioninfo = "aggressive looking flatscreen computer"; break;
	case 12: descriptioninfo = "coca cola bottle"; break;
	case 13: descriptioninfo = "snake"; break;
	case 14: descriptioninfo = "dirty dog"; break;
	case 15: descriptioninfo = "dirty traveler"; break;
	case 16: descriptioninfo = "clean backpacker"; break;
	case 17: descriptioninfo = "dirty backpacker"; break;
	case 18: descriptioninfo = "imaginary but dangerous girlfriend"; break;
	case 19: descriptioninfo = "Angry Andrew"; break;
	case 20: descriptioninfo = "Pissed off Andrew"; break;
	case 21: descriptioninfo = "living pen"; break;
	case 22: descriptioninfo = "charizard"; break;
	case 23: descriptioninfo = "shark on dry land"; break;
	case 24: descriptioninfo = "magician"; break;
	case 25: descriptioninfo = "Gandalf but young"; break;
	case 26: descriptioninfo = "squirtle on fire"; break;
	case 27: descriptioninfo = "swimming charmander"; break;
	case 28: descriptioninfo = "tall Hobbit"; break;
	case 29: descriptioninfo = "angry Hobbit"; break;
	case 30: descriptioninfo = "a skinny goat"; break;

	default: descriptioninfo = "Unknown Enemy";
	}
	return descriptioninfo;
}
