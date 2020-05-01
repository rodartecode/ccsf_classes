#pragma once

#ifndef _BIRTHDAY
#define _BIRTHDAY

#include <string>

class Birthday
{
private:
	int month;
	int day;
	int year;

public:
	Birthday();

	Birthday(int newMonth, int newDay, int newYear);

	Birthday(const Birthday &birthday);

	~Birthday();

	const int getMonth();

	const int getDay();

	const int getYear();

	void setBirthday(int newMonth, int newDay, int newYear);

	std::string birthdayString();

	const Birthday operator=(const Birthday &right);
};

#endif