/*
Jesse E Rodarte
12/12/17
110B
Dave Harden
a16_1.cpp

This program contains 2 functions "reverseWithinBounds" and "reverseCString".
reverseWithinBounds takes a char array parameter and 2 beginning/end ints. The
recursive function will reverse all the chars between those 2 bounds. The 
reverseCString function takes a single C-String parameter. It calls the 
reverseWithinBounds functions to reverse every char in the C-string. The driver
function simply tests these 2 functions. First it initializes a char array and 
calls reverseWithinBounds on a section of it and then prints the result. Then 
it tests the reverseCString function. Similarly it initializes a C-String and
then calls reverseCString on it. Finally it prints the result.
*/

#include <algorithm>
#include <iostream>

using namespace std;

void reverseWithinBounds(char array[], int beg, int end);
void reverseCstring(char* string);

const int LENGTH = 8;


int main()
{
	char t[LENGTH] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	

	for (int i = 0; i < LENGTH; i++){
		cout << t[i];
	}
	cout << endl;

	reverseWithinBounds(t, 0, 3);

	for (int i = 0; i < LENGTH; i++) {
		cout << t[i];
	}
	cout << endl;

	char a[] = "hello";

	cout << a << endl;
	reverseCstring(a);
	cout << a << endl;


	return 0;
}






/*
The reverseWithinBounds function requires 3 parameters. A char array, and 2 
beginning/end ints to represent the subscript bounds to reverse. The function
will not do anything if the 'beg' parameter is bigger than the 'end' parameter.
Otherwise the function will swap the 'beg' and 'end' values, increment and 
decrement the 2 parameters respectively and then calls itself with the adjusted
beg and int parameters. Once the parameters are equal or the 'beg' is greater
than the 'end' the function returns.

pre: beg < end < array size
post: the char values between the beg and end values are reversed
*/

void reverseWithinBounds(char array[], int beg, int end) {
	if (beg >= end) {
		return;
	}

	swap(array[beg], array[end]);
	beg++;
	end--;
	reverseWithinBounds(array, beg, end);
}






/*
The reverseCString functions accepts a single C-string 'string' paramater. It
simply reverses the C-string using the reverseWithinBounds recursive function.
It does not include the null terminator in the reversal.

pre: string is a valid C-string
post: the C-string values will be reversed, except for the null terminator.
*/

void reverseCstring(char* string) {
	int len = strlen(string) - 1;
	reverseWithinBounds(string, 0, len);
}


/*

abcdefgh
dcbaefgh
hello
olleh
Press any key to continue . . .

*/