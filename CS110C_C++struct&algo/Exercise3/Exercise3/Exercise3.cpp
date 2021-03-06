// Exercise3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdexcept>
#include <iostream>

using namespace std;
const int MAX = 9;


template<class ItemType>
class Box
{
private:
	ItemType item;
public:
	void setItem(const ItemType& i)
	{
		item = i;
	}
	ItemType getItem() const
	{
		return item;
	}
};




Box<int> findBox(Box<int> boxes[], int size, int target)
{
	int i = 0;
	bool found = false;
	while (!found && (i < size))
	{
		if (target == boxes[i].getItem())
			found = true;
		else
			i++;
	}
	if (target < 0)
		throw logic_error("That's not a valid search valueeeeee");
	if (!found)
		throw logic_error("Target not found in any box!");
	return boxes[i];
}




int main()
{
	Box<int> ssNum[MAX];
	Box<int> targetNum;

	for (int i = 0; i < MAX; i++) {
		ssNum[i].setItem((i + 1) * 111111111);
	}

	for (int i = 0; i < MAX; i++) {
		cout << ssNum[i].getItem() << endl;
	}

	try {
		targetNum = findBox(ssNum, MAX, 111111111);
	}
	catch(logic_error logErr) {
		cout << endl << logErr.what() << endl;
		targetNum.setItem(1);
	}
}

