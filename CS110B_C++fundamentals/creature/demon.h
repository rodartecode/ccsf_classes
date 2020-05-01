#ifndef DEMON_H
#define DEMON_H

#include "creature.h"
#include <string>
using namespace std;

namespace cs_creature {
	class Demon : public Creature {
	public: 
		Demon();
		Demon(int newStrength, int newHitpoints);
		int getDamage() const;
		string getSpecies() const;
	};
}

#endif