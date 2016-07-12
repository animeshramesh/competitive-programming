#include <bits/stdc++.h>

using namespace std;

/*
- pop()
- push(item)
- peek() // return top of stack
- isEmpty()
*/

class Stack
{
	int items[5];
	int top;

public:
	stack()
	{
		top = -1; // Initial top value
	}

	void push(int x)
	{
		if (top > 4) // Stack Overflow
			return;
		top++;
		items[top] = x;
	}	

	void pop()
	{
		if (top == -1) // Stack empty
			return;
		top--;
	}

	int peek()
	{
		return items[top];
	}

	int isEmpty()
	{
		return top < 0;
	}
}