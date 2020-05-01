#ifndef CREATURE_H
#define CREATURE_H

#include <string>
using namespace std;

namespace cs_creature {
	class Creature {
	private:
		int strength;
		int hitpoints;

	public:
		Creature();
		Creature(int newStrength, int newHitpoints);
		int getStrength() const;
		int getHitpoints() const;
		void setStrength(int newStrength);
		void setHitpoints(int newHitpoints);
		virtual int getDamage() const;
		virtual string getSpecies() const = 0;
	};
}

#endif