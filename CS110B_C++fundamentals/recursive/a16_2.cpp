/*
Jesse E Rodarte
12/12/17
110B
Dave Harden
a16_2.cpp

This program has one function called isAPalindrome. It's a recursive bool 
function that returns true if the MyString is a palindrome (ignoring
punctuation, spaces, and capitalization). The driver program will prompt the 
user for a string input, which will be stored in a MyString. The isAPalindrome
function is called on this MyString and the program will print out if its a 
palindrome or not. It will then prompt again for another string. The user can 
enter 'quit' to end the program.
*/

#include "mystring.h"
#include <cctype>
#include <iostream>


using namespace cs_mystring;
using namespace std;

bool isAPalindrome(MyString str, int beg, int end);



int main()
{
	MyString test;
	while (test != "quit") {
		cout << "Enter a string: ";
		test.read(cin, '\n');
		if (test != "quit") {
			if (isAPalindrome(test, 0, test.length() - 1)) {
				cout << test << " is a palindrome!!" << endl;
			}
			else {
				cout << test << " is not a palindrome" << endl;
			}
		}
	}
}






/*
The isAPalindrome takes 3 parameters. A MyString called str and 2 beg/end ints.
First the function checks the 2 bounds' values and checks if they're either a
space or punctuation mark. In either case it'll skip that value and either 
increment or decrement its approriate bound value. Once the subscript values
are confirmed to not be spaces or punctuation it will compare the 2 subscript
values. The function ignores capitalization by calling "toupper()" at the 
moment of comparison. If the values match, the function will increment and 
decrement the beg and end values repectively and then call itself using these
2 values. When the end parameter is greater than or equal to the beg parameter
it will return the 2 parameters subscript values equality. If at any point the 
2 subscript values don't match when compared, the function will return false.

pre: beg < end < str length
post: Will return  true if str is a palindrome, false otherwise 
*/

bool isAPalindrome(MyString str, int beg, int end) {
	while (beg < end) {
		while (ispunct(str[beg]) || isspace(str[beg])) {
			beg++;
		}
		while (ispunct(str[end]) || isspace(str[end])) {
			end--;
		}

		if (toupper(str[beg]) == toupper(str[end])) {
			beg++;
			end--;
			return isAPalindrome(str, beg, end);
		}
		else return false;
	}

	if (end >= beg) {
		return toupper(str[beg]) == toupper(str[end]);
	}
}




/*

Enter a string: hello
hello is not a palindrome
Enter a string: Able was I,  ere I saw Elba
Able was I,  ere I saw Elba is a palindrome!!
Enter a string: aaa.,.,,bbb  . ,., aaa
aaa.,.,,bbb  . ,., aaa is a palindrome!!
Enter a string: aaabbbbcaaa
aaabbbbcaaa is not a palindrome
Enter a string: quit

*/