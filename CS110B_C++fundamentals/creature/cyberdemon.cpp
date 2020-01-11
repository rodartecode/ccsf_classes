#include "cyberdemon.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature {
	Cyberdemon::Cyberdemon()
		: Demon() 
	{
	}






	Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
		: Demon(newStrength, newHitpoints)
	{
	}












	string Cyberdemon::getSpecies() const {
		return "Cyberdemon";
	}
}
