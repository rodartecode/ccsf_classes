// LinkedList1.cpp : Defines the entry point for the console application.
//

#include "LinkedList.h" 


// ADT list operations
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>


using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	cout << "The list contains " << endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		cout << listPtr->getEntry(pos) << " ";
	} // end for
	cout << endl << endl;
}  // end displayList

void displayList(ListInterface<int>* listPtr)
{
	cout << "The list contains " << endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		cout << listPtr->getEntry(pos) << " ";
	} // end for
	cout << endl << endl;
}  // end displayList

void listTester()
{
	ListInterface<string>* listPtr = new LinkedList<string>();
	cout << "Testing the Link-Based List:" << endl;
	string data[] = { "one", "two", "three", "four", "five", "six" };
	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
	for (int i = 0; i < 6; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
			cout << "Inserted " << listPtr->getEntry(i + 1)
			<< " at position " << (i + 1) << endl;
		else
			cout << "Cannot insert " << data[i] << " at position " << (i + 1)
			<< endl;
	}  // end for

	displayList(listPtr);

	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
	cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;

	cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
	cout << "After replacing the entry at position 3 with XXX: ";
	listPtr->setEntry(3, "XXX");
	displayList(listPtr);

} // end listTester

void reverseTester()
{
	cout << "Now testing reverse: " << endl;

	LinkedList<int>* listPtr = new LinkedList<int>();
	int data[] = { 1, 2, 3, 4, 5, 6 };

	for (int i = 0; i < 6; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
			cout << "Inserted " << listPtr->getEntry(i + 1)
			<< " at position " << (i + 1) << endl;
		else
			cout << "Cannot insert " << data[i] << " at position " << (i + 1)
			<< endl;
	} 
	displayList(listPtr);
	cout << "And now reversed: " << endl;
	listPtr->reverse();
	displayList(listPtr);
}

int main()
{
	listTester();
	reverseTester();
	return 0;
}  // end main

