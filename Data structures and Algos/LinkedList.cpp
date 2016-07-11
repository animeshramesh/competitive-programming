#include <bits/stdc++.h>

using namespace std;

/*
Operations :
 - Create new LL
 - Add a new node at tail
 - Insert new node at head
 - Delete node
 - Search for node
*/

struct Node{
	int id; 
	Node * next;
}

void initLinkedList(struct Node * head, int d) {

	head->id = d;
	head->next = NULL;
}

void appendToTail(struct Node * head, int d)
{	Node * cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	Node *tail = new Node;
	tail->id = d;
	tail->next = NULL;

	cur->next = tail;
}

struct Node * insertFront(struct Node * head, int d)
{
	Node * newHead = new Node;
	newHead->id = d;
	newHead->next = head;

	return newHead;
}

struct Node * searchNode(struct Node * head, int d)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur -> id == d) return cur;
		cur = cur -> next;
	}

	return NULL;
}

struct Node * deleteNode(struct Node * head, int d)
{
	// Handle case when node to be deleted is first node itself
	if (head -> id == d) 
	{	head = head->next;
		return head;
	}

	Node * cur = head;

	while (cur != NULL)
	{
		if (cur -> next -> id == d)
		{
			cur -> next = cur -> next -> next;
			return head;
		}
		cur = cur -> next;
	}

	return head;

}

