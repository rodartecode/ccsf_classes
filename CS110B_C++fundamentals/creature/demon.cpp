#include "demon.h"
#include <string>
#include <iostream>
using namespace std;

namespace cs_creature {
	Demon::Demon()
	: Creature() 
	{
	}

	Demon::Demon(int newStrength, int newHitpoints)
		: Creature(newStrength, newHitpoints) 
	{
	}

	int Demon::getDamage() const {
		int damage = Creature::getDamage();

		//cout <<" attacks for " << damage << " points!!" << endl;

		if (rand() % 4 == 0) {
			damage += 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}

		return damage;
	}

	string Demon::getSpecies() const {
		return "Demon";
	}
}