#include "balrog.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature {
	Balrog::Balrog()
		: Demon()
	{
	}






	Balrog::Balrog(int newStrength, int newHitpoints)
		: Demon(newStrength, newHitpoints)
	{
	}






	int Balrog::getDamage() const {
		//cout << "The Balrog";
		int damage = Demon::getDamage();
		int damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage += damage2;
		return damage;
	}






	string Balrog::getSpecies() const {
		return "Balrog";
	}
}