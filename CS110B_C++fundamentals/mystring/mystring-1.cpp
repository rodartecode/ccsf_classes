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
}