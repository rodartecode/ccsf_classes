#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void writeBackwards(string s);

int main()
{
	string hello = "hello";
	writeBackwards(hello);
}

void writeBackwards(string s) {
	if (s.size() != 0){
		int len = s.size() - 1;
		writeBackwards(s.substr(1, len));
		cout << s[0];
	}
}