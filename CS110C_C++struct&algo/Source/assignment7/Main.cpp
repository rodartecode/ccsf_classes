#include "Node.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

static const int MAX_QUEUE = 7;

class aQueue {
private:
	char entries[MAX_QUEUE];

	int front;
	int back;

public:
	aQueue() { front = 0; back = 0; };

	bool enqueue(char newEntry)
	{
		if (front != (back + 1) % (MAX_QUEUE + 1))
		{
			entries[back] = newEntry;
			back = (back + 1) % (MAX_QUEUE + 1);
			return true;
		}
		else
		{
			cout << "ERROR!! ERROR!!! CRITICAL ERRORR!!!" << endl;
			return false;
		}
	}

	bool dequeue()
	{
		if (front != back)
		{
			front = (front + 1) % (MAX_QUEUE + 1);
			return true;
		}
		else
			return false;
	}

	char peek()
	{
		if (!isEmpty())
			return entries[front];
	}

	bool isEmpty()
	{
		return front == back;
	}
};

class aStack
{
private:
	Node<char>* topPtr;

public:
	aStack() : topPtr(nullptr)
	{
	}

	~aStack()
	{
		while (!isEmpty())
			pop();
	}

	bool isEmpty()
	{
		return topPtr == nullptr;
	}

	bool push(char newChar)
	{
		bool result = true;

		Node<char>* newTop = new Node<char>();
		newTop->setItem(newChar);
		newTop->setNext(topPtr);

		topPtr = newTop;
		newTop = nullptr;

		return result;
	}

	bool pop()
	{
		bool result = false;

		if (!isEmpty())
		{
			Node<char>* deletePtr = topPtr;
			topPtr = topPtr->getNext();

			deletePtr->setNext(nullptr);
			delete deletePtr;
			deletePtr = nullptr;

			result = true;
		}

		return result;
	}

	char peek()
	{
		assert(!isEmpty());

		return topPtr->getItem();
	}
};

bool isPalindrome(string aString)
{
	aStack stack;
	aQueue queue;

	for (char i : aString)
	{
		stack.push(i);
		queue.enqueue(i);
	}

	while (!stack.isEmpty() && !queue.isEmpty())
	{
		if (stack.peek() == queue.peek())
		{
			stack.pop();
			queue.dequeue();
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string test1 = "aaaaab";
	string test2 = "tacocat";
	string test3 = "failtest";

	bool failtest = isPalindrome(test3);
	cout << "failtest = " << failtest << endl;

	bool result1 = isPalindrome(test1);
	cout << "result1 = " << test1 << " = " << result1 << endl;

	bool result2 = isPalindrome(test2);
	cout << "result2 = " << test2 << " = " << result2 << endl;
}

/*

EXPECTED OUTPUT:

ERROR!! ERROR!!! CRITICAL ERRORR!!!
failtest = 0
result1 = aaaaab = 0
result2 = tacocat = 1

*/