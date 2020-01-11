#include <string>
#include "Birthday.h"

Birthday::Birthday()
{
	month = 1;
	day = 1;
	year = 1900;
}

Birthday::Birthday(int newMonth, int newDay, int newYear)
{
	if (newMonth <= 1)
		month = 1;
	else if (newMonth >= 12)
		month = 12;
	else
		month = newMonth;

	if (newDay <= 1)
		day = 1;
	else if (newDay >= 31)
		day = 31;
	else
		day = newDay;

	if (newYear <= 1)
		year = 1;
	else if (newYear >= 2018)
		year = 2018;
	else
		year = newYear;
}

Birthday::Birthday(const Birthday &birthday)
{
	month = birthday.month;
	day = birthday.day;
	year = birthday.year;
}

Birthday::~Birthday()
{
}

const int Birthday::getMonth()
{
	return month;
}

const int Birthday::getDay()
{
	return day;
}

const int Birthday::getYear()
{
	return year;
}

void Birthday::setBirthday(int newMonth, int newDay, int newYear)
{
	if (newMonth <= 1)
		month = 1;
	else if (newMonth >= 12)
		month = 12;
	else
		month = newMonth;

	if (newDay <= 1)
		day = 1;
	else if (newDay >= 31)
		day = 31;
	else
		day = newDay;

	if (newYear <= 1)
		year = 1;
	else if (newYear >= 2018)
		year = 2018;
	else
		year = newYear;
}

std::string Birthday::birthdayString()
{
	std::string date = "";

	date.append(std::to_string(getMonth()));
	date.append("/");
	date.append(std::to_string(getDay()));
	date.append("/");
	date.append(std::to_string(getYear()));

	return date;
}

const Birthday Birthday::operator=(const Birthday &right)
{
	month = right.month;
	day = right.day;
	year = right.year;

	return *this;
}