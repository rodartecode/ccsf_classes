
#include <iostream>
#include <utility>
#include <time.h>

using namespace std;

void arrFiller(int arr[], int size);

void bubbleSort(int arr[], int size, int& count);
void mergeSort(int arr[], int first, int last, int& count);
void merge(int arr[], int first, int mid, int last, int& count);
void countSort(int arr[], int size, int& count);

const int MAX = 128;
const int MID = 32;
const int LOW = 8;
const int RANGE = 25;

int main()
{
	int arr1[LOW];
	int arr2[MID];
	int arr3[MAX];

	int a1 = 0, a2 = 0, a3 = 0; 
	int b1 = 0, b2 = 0, b3 = 0;
	int c1 = 0, c2 = 0, c3 = 0;

	arrFiller(arr1, LOW);
	bubbleSort(arr1, LOW, a1);

	arrFiller(arr1, LOW);
	bubbleSort(arr1, LOW, a2);

	arrFiller(arr1, LOW);
	bubbleSort(arr1, LOW, a3);

	cout << "bubbleLow1 accesses = " << a1 << endl;
	cout << "bubbleLow2 accesses = " << a2 << endl;
	cout << "bubbleLow3 accesses = " << a3 << endl;
	cout << "bubbleLow average = " << (a1 + a2 + a3) / 3 << endl << endl;

	arrFiller(arr2, MID);
	bubbleSort(arr2, MID, b1);

	arrFiller(arr2, MID);
	bubbleSort(arr2, MID, b2);

	arrFiller(arr2, MID);
	bubbleSort(arr2, MID, b3);

	cout << "bubbleMid1 accesses = " << b1 << endl;
	cout << "bubbleMid2 accesses = " << b2 << endl;
	cout << "bubbleMid3 accesses = " << b3 << endl;
	cout << "bubbleMid average = " << (b1 + b2 + b3) / 3 << endl << endl;

	arrFiller(arr3, MAX);
	bubbleSort(arr3, MAX, c1);

	arrFiller(arr3, MAX);
	bubbleSort(arr3, MAX, c2);

	arrFiller(arr3, MAX);
	bubbleSort(arr3, MAX, c3);

	cout << "bubbleMax1 accesses = " << c1 << endl;
	cout << "bubbleMax2 accesses = " << c2 << endl;
	cout << "bubbleMax3 accesses = " << c3 << endl;
	cout << "bubbleMax average = " << (c1 + c2 + c3) / 3 << endl << endl;



	a1 = 0, a2 = 0, a3 = 0;
	b1 = 0, b2 = 0, b3 = 0;
	c1 = 0, c2 = 0, c3 = 0;

	arrFiller(arr1, LOW);
	mergeSort(arr1, 0, LOW - 1, a1);

	arrFiller(arr1, LOW);
	mergeSort(arr1, 0, LOW - 1, a2);

	arrFiller(arr1, LOW);
	mergeSort(arr1, 0, LOW - 1, a3);

	cout << "mergeLow1 accesses = " << a1 << endl;
	cout << "mergeLow2 accesses = " << a2 << endl;
	cout << "mergeLow3 accesses = " << a3 << endl;
	cout << "mergeLow average = " << (a1 + a2 + a3) / 3 << endl << endl;

	arrFiller(arr2, MID);
	mergeSort(arr2, 0, MID - 1, b1);
	
	arrFiller(arr2, MID);
	mergeSort(arr2, 0, MID - 1, b2);

	arrFiller(arr2, MID);
	mergeSort(arr2, 0, MID - 1, b3);

	cout << "mergeMid1 accesses = " << b1 << endl;
	cout << "mergeMid2 accesses = " << b2 << endl;
	cout << "mergeMid3 accesses = " << b3 << endl;
	cout << "mergeMid average = " << (b1 + b2 + b3) / 3 << endl << endl;

	arrFiller(arr3, MAX);
	mergeSort(arr3, 0, MAX - 1, c1);

	arrFiller(arr3, MAX);
	mergeSort(arr3, 0, MAX - 1, c2);

	arrFiller(arr3, MAX);
	mergeSort(arr3, 0, MAX - 1, c3);

	cout << "mergeMax1 accesses = " << c1 << endl;
	cout << "mergeMax2 accesses = " << c2 << endl;
	cout << "mergeMax3 accesses = " << c3 << endl;
	cout << "mergeMax average = " << (c1 + c2 + c3) / 3 << endl << endl;
		

	a1 = 0, a2 = 0, a3 = 0;
	b1 = 0, b2 = 0, b3 = 0;
	c1 = 0, c2 = 0, c3 = 0;

	arrFiller(arr1, LOW);
	countSort(arr1, LOW, a1);

	arrFiller(arr1, LOW);
	countSort(arr1, LOW, a2);

	arrFiller(arr1, LOW);
	countSort(arr1, LOW, a3);

	cout << "countLow1 accesses = " << a1 << endl;
	cout << "countLow2 accesses = " << a2 << endl;
	cout << "countLow3 accesses = " << a3 << endl;
	cout << "countLow average = " << (a1 + a2 + a3) / 3 << endl << endl;

	arrFiller(arr2, MID);
	countSort(arr2, MID, b1);

	arrFiller(arr2, MID);
	countSort(arr2, MID, b2);

	arrFiller(arr2, MID);
	countSort(arr2, MID, b3);

	cout << "countMid1 accesses = " << b1 << endl;
	cout << "countMid2 accesses = " << b2 << endl;
	cout << "countMid3 accesses = " << b3 << endl;
	cout << "countMid average = " << (b1 + b2 + b3) / 3 << endl << endl;

	arrFiller(arr3, MAX);
	countSort(arr3, MAX, c1);

	arrFiller(arr3, MAX);
	countSort(arr3, MAX, c2);

	arrFiller(arr3, MAX);
	countSort(arr3, MAX, c3);

	cout << "countMax1 accesses = " << c1 << endl;
	cout << "countMax2 accesses = " << c2 << endl;
	cout << "countMax3 accesses = " << c3 << endl;
	cout << "countMax average = " << (c1 + c2 + c3) / 3 << endl << endl;

}



void arrFiller(int arr[], int size)
{
	int random;


	for (int i = 0; i < size; i++)
	{
		random = rand() % RANGE + 1;
		arr[i] = random;
	}
}




void bubbleSort(int arr[], int size, int& count)
{
	bool sorted = false;
	int passes = 1;
	while (!sorted && passes < (size))
	{
		sorted = true;
		for (int i = 0; i < size - 1; i++)
		{
			int nextI = i + 1;
			if (arr[i] > arr[nextI])
			{
				swap(arr[i], arr[nextI]);
				sorted = false;
				count++;
				count++;
			}
			count++;
			count++;
		}
		passes++;
	}
}





void mergeSort(int arr[], int first, int last, int& count)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;

		mergeSort(arr, first, mid, count);
		mergeSort(arr, mid + 1, last, count);
		merge(arr, first, mid, last, count);
	}
}




void merge(int arr[], int first, int mid, int last, int& count) 
{
	int temp[MAX] = { 0 };

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = first1;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			temp[index] = arr[first1];
			first1++;
			count++;
			count++;
		}
		else
		{
			temp[index] = arr[first2];
			first2++;
			count++;
			count++;
		}
		index++;
		count++;
		count++;
	}

	while (first1 <= last1)
	{
		temp[index] = arr[first1];
		first1++;
		index++;
		count++;
		count++;
	}

	while (first2 <= last2)
	{
		temp[index] = arr[first2];
		first2++;
		index++;
		count++;
		count++;
	}

	for (index = first; index <= last; index++)
	{
		arr[index] = temp[index];
		count++;
		count++;
	}
}





void countSort(int arr[], int size, int& sum)
{
	int temp[MAX] = { 0 };

	int count[RANGE + 1] = { 0 };


	for (int i = 0; i < size; i++)
	{
		count[arr[i]]++;
		sum++;
	}

	for (int i = 1; i <= RANGE; i++)
	{
		count[i] += count[i - 1];
		sum++;
		sum++;
	}

	for (int i = 0; i < size; i++)
	{
		temp[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
		sum++;
		sum++;
		sum++;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i];
		sum++;
		sum++;
	}
}
