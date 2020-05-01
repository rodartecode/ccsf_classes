#include "elf.h"
#include <string>
#include <iostream>
using namespace std;

namespace cs_creature {
	Elf::Elf()
		: Creature()
	{
	}






	Elf::Elf(int newStrength, int newHitpoints)
		: Creature(newStrength, newHitpoints) 
	{
	}






	int Elf::getDamage() const {
		int damage = Creature::getDamage();
		//cout << "The Elf attacks for " << damage << " points!!" << endl;

		if (rand() % 2 == 0) {
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage *= 2;
		}

		return damage;
	}






	string Elf::getSpecies() const {
		return "Elf";
	}

}