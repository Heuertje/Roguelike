#include "stdafx.h"
#include "character.h"




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
		return health;
	}
	int Character::increaselevel(){
		if (level < 10){
			level += 1;
			int attstr = 2;
			int randy = rand() % attstr +1;
			increaseattack(randy);
			int randys = rand() % attstr +1;
			increasestrength(randys);
			int health = rand() % 7 +1;
			increasemaxhealth(health);

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
	int Character::increasemaxhealth(int x){
		health += x;
		return health;
	};
	int Character::increaseawareness(int x)
	{
		 awareness += x;
		 return awareness;
	}
	Item Character::getItemFromInventory(int itemLocation)
	{
		return inventory.getItem(itemLocation);
	}