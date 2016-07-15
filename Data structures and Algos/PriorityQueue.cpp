// Lower priority = Higher priority
// Implemented this using Linked List.

/*
Operations:
- Insert
- Remove
*/

struct Node {
	int data, priority;
	Node * next;
}

node * front = NULL;

struct Node * createNewNode(int data, int priority)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->priority = priority;
	newNode->next = NULL;

	return newNode;
}

void insertNode(int data, int priority)
{	
	Node * newNode = createNewNode(data, priority);
	
	if (front == NULL || priority < front->priority)
	{	
		newNode->next = front;
		front = newNode;
	}

	else
	{
		Node * cur = front;

		while (cur->next && cur->next->priority >= priority)
			cur = cur->next;

		newNode->next = cur->next;
		cur->next = newNode;
	}

}

void removeNode()
{
	if (front == NULL) return; //Underflow;

	front = front->next;
}