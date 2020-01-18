#include "Node.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void calculator();
bool preCheck(string infix);
string toPost(string infix);
int postCalc(string postfix);


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




void calculator()
{
	string test1 = "2+2";
	string test2 = "3+(8-2)";
	string test3 = "(4*2)/2";
	string test4 = "3*2-2/2+1";
	string testPost1 = toPost(test1);
	string testPost2 = toPost(test2);
	string testPost3 = toPost(test3);
	string testPost4 = toPost(test4);
	int calc1 = postCalc(testPost1);
	int calc2 = postCalc(testPost2);
	int calc3 = postCalc(testPost3);
	int calc4 = postCalc(testPost4);


	cout << test1 << " to post: ";
	cout << testPost1 << " calculated: " << calc1 << endl << endl;

	cout << test2 << " to post: ";
	cout << testPost2 << " calculated: " << calc2 << endl << endl;

	cout << test3 << " to post: ";
	cout << testPost3 << " calculated: " << calc3 << endl << endl;

	cout << test4 << " to post: ";
	cout << testPost4 << " calculated: " << calc4 << endl << endl;
}




string toPost(string infix)
{
	string postfix;
	aStack stack;

	for (int i = 0; i < infix.length(); i++)
	{
		if (isdigit(infix[i]))
			postfix += infix[i];

		else if (infix[i] == '(')
			stack.push(infix[i]);

		else if (infix[i] == '+' || infix[i] == '-')
		{
			if (stack.isEmpty())
				stack.push(infix[i]);
			else if (stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '*' || stack.peek() == '/')
			{
				while ((!stack.isEmpty())
					&& (stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '*' || stack.peek() == '/'))
				{
					char op = stack.peek();
					stack.pop();
					postfix += op;
				}
				stack.push(infix[i]);
			}
			else
				stack.push(infix[i]);
		}

		else if (infix[i] == '*' || infix[i] == '/')
		{
			if (stack.isEmpty())
				stack.push(infix[i]);
			else if (stack.peek() == '*' || stack.peek() == '/')
			{
				while ((!stack.isEmpty())
					&& (stack.peek() == '*' || stack.peek() == '/'))
				{
					char op = stack.peek();
					stack.pop();
					postfix += op;
				}
				stack.push(infix[i]);
			}
			else
				stack.push(infix[i]);
		}

		else if (infix[i] == ')')
		{
			while (stack.peek() != '(')
			{
				char op = stack.peek();
				stack.pop();
				postfix += op;
			}
			stack.pop();
		}


		if (i == infix.length() - 1)
		{
			while (!stack.isEmpty())
			{
				char op = stack.peek();
				stack.pop();
				postfix += op;
			}
		}
	}
	return postfix;
}




int postCalc(string postfix)
{
	aStack stack;
	
	for (int i = 0; i < postfix.length(); i++) 
	{
		if (isdigit(postfix[i]))
			stack.push(postfix[i]);
		else
		{
			int result;
		
			int op2 = stack.peek() - '0';
			stack.pop();
			int op1 = stack.peek() - '0';
			stack.pop();

			switch (postfix[i])
			{
			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '/':
				result = op1 / op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			default:
				break;
			}

			if(result < 10 && result >= 0)
				stack.push(result + '0');

		}
	}

	return stack.peek() - '0';
}




int main()
{
	calculator();
}

/****************************************

OUTPUT:

2+2 to post: 22+ calculated: 4

3+(8-2) to post: 382-+ calculated: 9

(4*2)/2 to post: 42*2/ calculated: 4

3*2-2/2+1 to post: 32*22/-1+ calculated: 6

****************************************/
