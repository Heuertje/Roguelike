#include "stdafx.h"
#include "character.h"

#include "randomizer.h"

Character::~Character(){}


void Character::checkstats(){
	cout << "You are Level " << level << endl << "You've got " << health << " Health Points" << endl
		<< "Attack: " << attack << ", Strength: " << strength << endl
		<< "You've got " << xp << " Experience" << endl;
}


int Character::checkxp(){
	if (level == 1 && xp > 100){
		increaselevel();
	}
	if (level == 1 && xp > 200){
		increaselevel();
	}
	if (level == 1 && xp > 300){
		increaselevel();
	}
	if (level == 1 && xp > 500){
		increaselevel();
	}
	if (level == 1 && xp > 800){
		increaselevel();
	}
	return xp;
}


int Character::checkHP(){
	cout << "Your Max HP is currently: " << health << endl;
	return health;
}


int Character::getDef(){
	return defense;
}
int Character::getAttack(){
	return attack;
}
int Character::getlevel(){
	return level;
}
int Character::getHealth(){
	return health;
}
int Character::getStrength(){
	return strength;
}




void Character::setstats(){
	level = 1;
	health = 30;
	maxhealth = 30;
	xp = 0;
	attack = 5;
	strength = 5;
	defense = 5;
	awareness = 0;
}

int Character::increasexp(int x){
	xp += x;
	Character::Instance().checkxp();
	return xp;
}

	
int Character::increaselevel(){
	if (level < 10){
		level += 1;
		
		increaseattack(Randomizer::Instance().generateRandomNumber(3) + 1);
		increasestrength(Randomizer::Instance().generateRandomNumber(3) + 1);
		increasemaxhealth(Randomizer::Instance().generateRandomNumber(6) + 1);
		increasedefense(Randomizer::Instance().generateRandomNumber(3) + 1);
		cout << endl << endl << "Congratulations! you are now Level: " 
			<< level << endl
			<< "Your level is: " << level << endl
			<< "Your stats are now:" << endl
			<< "Attack: " << attack 
			<< ", Strength: " << strength 
			<< ", Defense " << defense << endl
			<< "Max Health: " << maxhealth << endl;


		cout << endl << endl;

	}
	return level;
};
	
	int Character::increaseattack(int x){
		attack += x;
		return attack;
	};
	int Character::increasestrength(int x){
		strength += x;
		return strength;
	};
	int Character::increasedefense(int x){
		defense += x;
		return defense;
	}

	int Character::increasemaxhealth(int x){
		maxhealth += x;
		increasehealth(x);
		return maxhealth;
	};
	int Character::increasehealth(int x){
		health += x;
		cout << "You just gained " << x << "HP" << endl << "You've now got " << health << "HP" << endl;
		return health;
	}
	int Character::decreasehealth(int x){
		health -= x;
		cout << "You just lost "<< x << "HP" << endl << "You've now got " << health << "HP" << endl;
		return health;
	}


	bool Character::isAlive(){
		if (health <= 1){
			return false;
		}
		return true;
	}
	int Character::increaseawareness(int x)
	{
		 awareness += x;
		 return awareness;
	}


	Item Character::getItemFromInventory(int itemLocation)
	{
		return inventory.getItem(itemLocation);
	}