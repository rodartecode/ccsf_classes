/*
Jesse E Rodarte
11/27/17
CS 110B
Dave Harden
Assignment 14
mystring.cpp

CLASS INVARIANT:

There is only one data member in this class. It's a char array saved as a 
c-string and labeled 'mstring'. The c-string is always dynamically allocated
and stored using the minimum amount of memory. If the string is changed, the
string will be temporarily stored in a non-dynamic array, previous memory 
deallocated, and new memory allocated to fit the string exactly. Empty MyStrings
are always initialized as a null string.

*/

#pragma warning(disable:4996)
#include "mystring.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

namespace cs_mystring {
	MyString::MyString() {
		mstring = new char[1];
		strcpy(mstring, "");

	}






	MyString::MyString(const char *right) {
		mstring = new char[strlen(right) + 1];
		strcpy(mstring, right);
	}






	MyString::MyString(const MyString& right) {
		mstring = new char[strlen(right.mstring) + 1];
		strcpy(mstring, right.mstring);
	}






	MyString::~MyString() {
		delete[] mstring;
	}






	MyString MyString::operator=(const MyString& right) {
		if (this != &right) {
			delete[] mstring;
			mstring = new char[strlen(right.mstring) + 1];
			strcpy(mstring, right.mstring);
		}
		return *this;
	}






	char MyString::operator[](int index) const {
		assert(index >= 0 && index < strlen(mstring));
		return mstring[index];
	}






	char& MyString::operator[](int index) {
		assert(index >= 0 && index < strlen(mstring));
		return mstring[index];
	}






	int MyString::length() const {
		int len = strlen(mstring);
		return len;
	}






	ostream& operator<<(ostream& out, const MyString &right) {
		out << right.mstring;
		return out;
	}






	istream& operator>>(istream& in, MyString &right) {
		while (isspace(in.peek())) {
			in.ignore();
		}

		char temp[128];
		in.getline(temp, 127, ' ');
		delete[] right.mstring;
		right.mstring = new char[strlen(temp) + 1];
		strcpy(right.mstring, temp);

		return in;
	}






	void MyString::read(std::istream& in, char delim) {
		char temp[128];
		in.getline(temp, 127, delim);
		mstring = new char[strlen(temp) + 1];
		strcpy(mstring, temp);
	}






	bool operator<(const MyString &left, const MyString &right) {
		return strcmp(left.mstring, right.mstring) < 0;
	}






	bool operator<=(const MyString &left, const MyString &right) {
		return strcmp(left.mstring, right.mstring) <= 0;
	}






	bool operator>(const MyString &left, const MyString &right) {
		return strcmp(left.mstring, right.mstring) > 0;
	}






	bool operator>=(const MyString &left, const MyString &right) {
		return strcmp(left.mstring, right.mstring) >= 0;
	}






	bool operator==(const MyString &left, const MyString &right) {
		return !strcmp(left.mstring, right.mstring);
	}






	bool operator!=(const MyString &left, const MyString &right) {
		return strcmp(left.mstring, right.mstring);
	}






	MyString operator+(const MyString &left, const MyString &right) {
		MyString temp;
		delete[] temp.mstring;
		temp.mstring = new char[strlen(left.mstring) + strlen(right.mstring) + 1];
		strcpy(temp.mstring, left.mstring);
		strcat(temp.mstring, right.mstring);
		return temp;
	}






	MyString MyString::operator+=(const MyString &right) {
		*this = *this + right;
		return *this;
	}
}