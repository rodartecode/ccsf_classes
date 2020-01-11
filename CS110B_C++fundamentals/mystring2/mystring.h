/*
Jesse E Rodarte
11/27/17
CS 110B
Dave Harden
Assignment 14
mystring.h

The MyString class is a string class that provides bounds checking and dynamic
memory allocation. It has one private variable which stores a c-string. Memory
is allocated and deallocated according the the string sizes. It includes a 
default and copy constructor, as well as a normal constructor that accepts a 
c-string. It also overloads the [] operators to allow access to individual chars
within the c-string. It supports 6 relational operators, as well as a 
concatenation operator (+) and a self assignment concatenation operator (+=). It
also supports stream insertion and extraction operators. The class also overloads 
the assignment operator. Lastly, the class includes a member function 'length' 
that returns the string length of a MyString, and a member function 'read' that
reads an input stream using a custom delimiter char variable.


MyString();
	post:	the MyString will be initialized as an empty string (" ") allocating
			only enough memory to fit the string




MyString(const char *right);
	post:	the MyString will be initialized with the values of the c-string 
			allocating the exact amount of memory needed to fit it.
			




MyString(const MyString& right);
	post:	the MyString will be initialized with the value of the 'right' mstring




~MyString();
	post:	will deallocate the memory previously allocated to the mstring




MyString operator=(const MyString& right); 
	post:	if the 'right' MyString is the same as the calling MyString, it 
			assigns the calling MyString to itself. Otherwise it will assign
			the 'right' mstring to the calling mstring, after allocating the
			appropriate amount of memory.



char operator[](int index) const;
	post:	after checking that the index is within bounds of the calling mstring,
			will return the value in the index of the calling mstring.



char& operator[](int index);
	post:	after checking that the index is within bounds of the calling mstring,
		will return a reference to the char located in the index



int length() const;
	post:	will return the length of the mstring as an int



friend std::ostream& operator<<(std::ostream& out, const MyString &right);
	pre:	the ostream object is ready for writing
	post:	the mstring has been inserted into the ostring out for printing



friend std::istream& operator>>(std::istream& in, MyString &right);
	pre:	the istream object is ready for reading. the istream string has a
			maximum size of 127 elements.
	post:	the string in the istream object has been read and inserted into
			the 'right' MyString object



void read(std::istream& in, char delim);
	post:	the string will be read up to the delimiter value. the read string
			is copied to the calling 'mstring'



friend bool operator<(const MyString &left, const MyString &right);
	post:	will return true if the left mstring comes before the right in
			alpha-numeric order, otherwise will return false



friend bool operator<=(const MyString &left, const MyString &right);
	post:	will return true if the left mstring comes before the right in
			alpha-numeric order	or they're the same, otherwise returns false



friend bool operator>(const MyString &left, const MyString &right);
	post:	will return true if the right mstring comes before the left in
			alphanumeric order, otherwise will return false



friend bool operator>=(const MyString &left, const MyString &right);
	post:	will return true if the right mstring comes before the left in
			alpha-numeric order or if they're the same, otherwise returns false



friend bool operator==(const MyString &left, const MyString &right);
	post:	will return true if both mstrings are equal, otherwise returns false



friend bool operator!=(const MyString &left, const MyString &right);
	post:	will return false if both mstrings are equal, otherwise returns false



friend MyString operator+(const MyString &left, const MyString &right);
	post:	will concatanate the 'right' mstring to the calling 'mstring'. returns
			the concatenated MyString after allocating the proper amount of memory.



MyString operator+=(const MyString &right);
	post:	concatenates the calling mstring with the 'right' mstring and assigns
			this result to the calling 'mstring' after allocating the proper 
			amount of memory.

*/


#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring{
	class MyString {
	private:
		char *mstring;

	public:
		MyString();
		MyString(const char *right);
		MyString(const MyString& right);
		~MyString();
		MyString operator=(const MyString& right);
		char operator[](int index) const;
		char& operator[](int index);
		int length() const;
		friend std::ostream& operator<<(std::ostream& out, const MyString &right);
		friend std::istream& operator>>(std::istream& in, MyString &right);
		void read(std::istream& in, char delim);
		friend bool operator<(const MyString &left, const MyString &right);
		friend bool operator<=(const MyString &left, const MyString &right);
		friend bool operator>(const MyString &left, const MyString &right);
		friend bool operator>=(const MyString &left, const MyString &right);
		friend bool operator==(const MyString &left, const MyString &right);
		friend bool operator!=(const MyString &left, const MyString &right);
		friend MyString operator+(const MyString &left, const MyString &right);
		MyString operator+=(const MyString &right);
};
}


/*

----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will

Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing apple to
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing  to Banana
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing Banana to Banana
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing why to wackity
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

*/
#endif