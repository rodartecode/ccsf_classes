// Exercise2B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int rabbit(int rab);
int irabbit(int rab);

int main()
{
	int rr;
	char again = 'y';
	while (toupper(again) != 'N') {
		cout << "How many rabbits? ";
		cin >> rr;
		cout << "rabbits = " << rabbit(rr) << endl << "Again? ";
		cin >> again;
	}
}

int rabbit(int rab) {
	if (rab == 1 || rab == 2) {
		return 1;
	}
	else {
		return rabbit(rab - 1) + rabbit(rab - 2);
	}
}

//45 = 56s
//38 ~= 2s
//

int irabbit(int rab) {
	int current = 1, next = 1, previous = 1;

	for (int i = 3; i < rab; i++) {
		next = current + previous;
		previous = current;
		current = next;
	}
	return next;
}

//They're all instant