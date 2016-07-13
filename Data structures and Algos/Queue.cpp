#include <bits/stdc++.h>

using namespace std;

/*
- add(item)
- remove()
- peek() // return top of stack
- isEmpty()
*/

class Queue
{
	int items[5];
	int head, tail, qLength=5;
	// Head points to the index just in front of the 1st item of queue


public:
	Queue()
	{
		head = -1;
		tail = -1;
	}

	void addItem(int x)
	{
		if (tail == qLength-1) return;
		tail++;
		items[tail] = x;
	}

	int remove(){
		// Item to be removed = items[head]
		if (head == tail) return; // Underflow
		head++;
		int x = items[head];
		return x;
	}
	
}
