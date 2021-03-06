/*
Jesse E Rodarte
12/12/17
110B
Dave Harden
a16_2.cpp

This program has 2 functions. A void function called ascSort, which uses a 
recursive selection sort to sort an int array. There's also a helper function
called smallestIndex which will search through an array and return the index of
the smallest value it finds. The driver program initializes an int array using 
the const int SIZE.  It then prints out the array before its sorted, and then 
calls ascSort on it, and prints it out again after its sorted.
*/

#include <iostream>

using namespace std;

const int SIZE = 10;

void ascSort(int arr[], int size, int index = 0);
int smallestIndex(int arr[], int size, int index);


int main()
{
	int t1[SIZE] = { 1, 3, 2, 4, 11, 7, 6, 9, 13, 8 };

	for (int i = 0; i < SIZE; i++) {
		cout << t1[i] << ", ";
	}
	cout << endl;

	ascSort(t1, SIZE);

	for (int i = 0; i < SIZE; i++) {
		cout << t1[i] << ", ";
	}
	cout << endl;

	return 0;
}






/*
The ascSort function takes 3 parameters. First is the int array called arr, an
int variable represeting the size of the array called size, and an int index 
which represents the subscript from where the array should be sorted which is 
generally initialized with the value of '0'. The function will only run if the 
index value is less than the value size - 1. First it initializes a new int
named 'small' with the value of smallestIndex. It then stores the value in the
[index] subscript into a temp int and swaps the [index] and [small] values. It 
then calls itself again using an incremented index value. When the index value
reaches the end of the array the function stops running and the array is sorted.

pre: index < size 
post: The int array is sorted in ascending order
*/

void ascSort(int arr[], int size, int index) {
	if (index < size - 1) {		
		int small = smallestIndex(arr, size, index);
		int temp = arr[index];
		arr[index] = arr[small];
		arr[small] = temp;

		ascSort(arr, size, index + 1);}
}






/*
The smallestIndex function will return the index of the smallest value in an 
int array. The 3 parameters are an int array 'arr', an int for 'size', and an
int 'index' which represents the starting point of the search. First the 
verifies that index is not at the end of the array, and if it is, it will 
return the index value. If not it will run a loop and check every value in the 
array between, and including, the 'index' and 'size - 1' subscripts, using an
int 'search' as a temporary subscript. Every loop it will compare the values of 
the 'index' and 'search' subscripts. If the 'search' value is smaller than the 
'index' value, than the index will be assigned the 'search' position. Once
the loop is finished it will return whatever the 'index' value was.

pre: index < size
post: Will return the index position of the first 'smallest' value it finds
*/

int smallestIndex(int arr[], int size, int index) {
	if (size - 1 == index) {
		return index;
	}

	for (int search = index + 1; search < size; search++) {
		if (arr[search] < arr[index]) {
			index = search;
		}
	}

	return index;
}



/*

1, 3, 2, 4, 11, 7, 6, 9, 13, 8,
1, 2, 3, 4, 6, 7, 8, 9, 11, 13,
Press any key to continue . . .

*/

