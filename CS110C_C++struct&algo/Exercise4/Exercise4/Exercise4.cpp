/// Array-based List Class for Playlists
// Max Luttrell CS 110C
// Jesse E Rodarte
//
// update 1/31/2018:
//  - removed dynamic exception specifications for getEntry and setEntry
//  - improved comments
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
	static const int CHUNK_SIZE = 100;
	ItemType *list;
	int numItems;
	int maxItems;
public:
	// default constructor and destructor
	List() {
		numItems = 0; maxItems = CHUNK_SIZE;
		list = new ItemType[CHUNK_SIZE];
	}
	~List() { delete[] list; }

	// list member functions
	bool isEmpty() { return numItems == 0; }
	int getLength() { return numItems; }
	bool insert(int pos, const ItemType& item);
	bool remove(int pos);

	// clear the list
	// clear can simply set numItems to zero.  The array list may still contain
	// items already inserted into the list, but since numItems is zero, there
	// isn't any way to get at them using getEntry() or setEntry()
	void clear() { numItems = 0; }

	// return entry at postion pos
	// throw invalid_argument if pos<1 or pos>getLength()
	ItemType getEntry(int pos) const;

	// set entry at postion pos to item
	// throw invalid_argument if pos<1 or pos>getLength()
	void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
	bool canAdd;

	canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));
	if (canAdd)
	{
		// first, we have to move everything after our insertion point over one
		// position to make room for our new item.  start at the back of the list.
		// don't forget arrays start at postion zero and our list ADT starts at
		// position 1.
		for (int i = numItems; i >= pos; i--)
			list[i] = list[i - 1];

		// now put our item at position pos-1
		list[pos - 1] = item;

		numItems++;
	}
	else
	{
		int oldSize = CHUNK_SIZE;
		maxItems += CHUNK_SIZE;
		ItemType *temp = new ItemType[maxItems];
		for (int i = 0; i < oldSize; i++)
		{
			temp[i] = list[i];
		}
		delete[] list;
		ItemType *list = new ItemType[maxItems];
		for (int i = 0; i < maxItems; i++)
		{
			list[i] = temp[i];
		}
		delete[] temp;
		for (int i = numItems; i >= pos; i--)
		{
			list[i] = list[i - 1];
		}
		list[pos - 1] = item;

		numItems++;

		return true;
	}
	return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
	if (pos<1 || pos>numItems) {
		throw invalid_argument("ERROR: getEntry() using invalid position");
	}
	return list[pos - 1];
}

// TODO: add implementations for setEntry() and remove() functions


template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
	if (pos<1 || pos>getLength()) 
	{
		throw invalid_argument("ERROR: setEntry() using invalid position");
	}
	else 
	{
		list[pos - 1] = item;
	}
}


template<class ItemType>
bool List<ItemType>::remove(int pos) {
	if (pos < 1 || pos > getLength()) {
		return false;
	}
	for (int i = pos; i < maxItems; i++)
	{
		list[i - 1] = list[i];
	}
	numItems--;
	return true;
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
	bool inputCheck;
	int trackNumber;

	do
	{
		inputCheck = true;
		cout << "Please enter the track number you'd like to view: ";
		if (!(cin >> trackNumber))
		{
			cout << "Please enter numbers only.\n";
			cin.clear();
			cin.ignore(10000, '\n');
			inputCheck = false;
		}
	} while (!inputCheck);
	return trackNumber;
}


int main()
{
	List<string> songs;
	char goAgain = 'y';
	int trackNumber;
	string trackName;

	// Insert some songs into our list
	songs.insert(1, "One More Saturday Night");
	songs.insert(1, "Friday I'm in Love");
	songs.insert(3, "Sunday Morning Coming Down");
	songs.insert(1, "California Love");

	cout << "Welcome!  There are " << songs.getLength() << " tracks.\n";
	while (goAgain != 'n')
	{
		char command;
		cout << "GET track, NEW track, or PRINT playlist (G/N/P)??:  ";
		cin.get() >> command;
		toupper(command);
		cin.sync();

		switch (command)
		{
		case 'G':
			trackNumber = getTrack();
			try
			{
				trackName = songs.getEntry(trackNumber);
			}
			catch (invalid_argument arg)
			{
				cout << arg.what() << endl;
				trackName = "No Track";
			}
			cout << "Your track name is " << trackName << endl;
			if (trackName != "No Track")
			{
				char result;
				cout << "Delete/Continue (D/C)??: ";
				cin.get() >> result;
				toupper(result);
				if (result = 'D')
				{
					songs.remove(trackNumber);
					cout << "Song removed!!";
				}
			}

		case 'N':
			;

		case 'P':
			;


		}
		
		cout << "Go again? (y/n) ";
		cin >> goAgain;
	}

	cout << "Rock on!\n";
	return 0;
}
