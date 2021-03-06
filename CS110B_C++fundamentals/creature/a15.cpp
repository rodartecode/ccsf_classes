#include "creature.h"
#include "demon.h"
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace cs_creature;
using namespace std;

void battlearena(Creature& left, Creature& right);
bool isDead(Creature& dead);


int main() {
	srand(time(0));

	Human h1;
	Elf e1;
	Cyberdemon c1;
	Balrog b1;

	Human h(20, 30);
	Elf e(40, 50);
	Cyberdemon c(60, 70);
	Balrog b(80, 90);
	Human a(150, 120);
	Cyberdemon d(130, 170);
	Elf f(120, 100);


	battlearena(h1, e1);
	battlearena(b, a);
	battlearena(d, f);
	
}


void battlearena(Creature& left, Creature& right) {
	while (!isDead(left) && !isDead(right)) {

		int daml, damr;
		daml = left.getDamage();
		damr = right.getDamage();

		left.setHitpoints(left.getHitpoints() - damr);
		right.setHitpoints(right.getHitpoints() - daml);

		cout << "The " << left.getSpecies() << " has " << left.getHitpoints()
			<< "HP!" << endl;
		cout << "The " << right.getSpecies() << " has " << right.getHitpoints()
			<< "HP!" << endl;

		if (isDead(left) && isDead(right))
			cout << "They're down!! They're both down!!!" << endl << endl;

		if (isDead(left) && !isDead(right))
			cout << "The " << right.getSpecies() << " wins!!" << endl << endl;

		if (!isDead(left) && isDead(right))
			cout << "The " << left.getSpecies() << " wins!!" << endl << endl;
	}
}

bool isDead(Creature& dead) {
	return dead.getHitpoints() <= 0;
}

/*
The Human attacks for 6 points!
The Elf attacks for 2 points!
Magical attack inflicts 2 additional damage points!
The Human has 6HP!
The Elf has 4HP!
The Human attacks for 4 points!
The Elf attacks for 4 points!
The Human has 2HP!
The Elf has 0HP!
The Human wins!!

The Balrog attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 48 additional damage points!
The Human attacks for 106 points!
The Balrog has -16HP!
The Human has 11HP!
The Human wins!!

The Cyberdemon attacks for 2 points!
The Elf attacks for 27 points!
The Cyberdemon has 143HP!
The Elf has 98HP!
The Cyberdemon attacks for 26 points!
The Elf attacks for 63 points!
Magical attack inflicts 63 additional damage points!
The Cyberdemon has 17HP!
The Elf has 72HP!
The Cyberdemon attacks for 122 points!
The Elf attacks for 28 points!
Magical attack inflicts 28 additional damage points!
The Cyberdemon has -39HP!
The Elf has -50HP!
They're down!! They're both down!!!

*/