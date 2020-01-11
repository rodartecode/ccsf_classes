#ifndef BALROG_H
#define BALROG_H

#include "demon.h"
#include <string>
using namespace std;

namespace cs_creature {
	class Balrog : public Demon {
	public:
		Balrog();
		Balrog(int newStrength, int newHitpoints);
		int getDamage() const;
		string getSpecies() const;
	};
}


#endif 
