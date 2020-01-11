#include "creature.h"
#include <iostream>

using namespace std;


namespace cs_creature {

	Creature::Creature() {
		strength = 10;
		hitpoints = 10;
	}




	Creature::Creature(int newStrength, int newHitpoints) {
		strength = newStrength;
		hitpoints = newHitpoints;
	}




	int Creature::getStrength() const {
		return strength;
	}




	int Creature::getHitpoints() const {
		return hitpoints;
	}




	void Creature::setHitpoints(int newHitpoints) {
		hitpoints = newHitpoints;
	}




	void Creature::setStrength(int newStrength) {
		strength = newStrength;
	}




	int Creature::getDamage() const {
		int damage;

		damage = (rand() % strength) + 1;
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		return damage;
	}


}

