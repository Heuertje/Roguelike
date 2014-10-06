#include "stdafx.h"
#include "character.h"
#include <cstdlib>



	int character::checkxp(){
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

	int character::increaselevel(){
		if (level < 10){
			level += 1;
			int attstr = 2;
			int randy = rand() % attstr +1;
			increaseattack(randy);
			int randys = rand() % attstr +1;
			increasestrength(randys);
			int health = rand() % 7 +1;
			increasehealth(health);

		}
		return NULL;
	};
	int character::increaseattack(int x){
		attack += x;
		return NULL;
	};
	int character::increasestrength(int x){
		strength += x;
		return NULL;
	};
	int increasehealth();
	int character::increasehealth(int x){
		health += x;
		return NULL;
	};


