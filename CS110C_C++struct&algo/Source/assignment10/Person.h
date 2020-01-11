#pragma once

#ifndef _PERSON
#define _PERSON

#include "Birthday.h"
#include <string>

class Person
{
private:
	std::string name;
	Birthday bday;
public:

	Person();
	Person(std::string newName, Birthday birthday);
	Person(std::string newName, int newMonth, int newDay, int newYear);
	Person(const Person &newPerson);
	~Person();

	std::string getName();
	int getMonth();
	std::string birthdayString();


	bool operator==(const Person &right);
	bool operator<(const Person &right);
	bool operator>(const Person &right);
	
};

#endif