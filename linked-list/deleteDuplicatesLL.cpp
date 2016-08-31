// Deleting duplicates from linked list - using hashing ( O(n^2) - RunTime ) 

#include "stdafx.h"
#include<iostream>
#include<unordered_map>
using namespace std;

struct node {
	int data;
	node* next;
};

void push(node** h, int data)
{
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;

	if (*h == NULL)
	{
		*h = newnode;
	}
	else
	{
		node* temp = *h;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display(node* h)
{
	node* temp = h;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	unordered_map<int, int> node_map;   // STL - unordered_map - initially all elements are 0.
	node* head = NULL;
	push(&head, 32);
	push(&head, 89);
	push(&head, 23);
	push(&head, 24);
	push(&head, 29);
	push(&head, 23);
	push(&head, 50);
	display(head);
	cout << endl;
	//cout << node_map[0] << endl;
	node* temp=head->next;
	node* prev = head;
	node_map[head->data] = 1;
	node* temp1;
	while (temp != NULL)
	{
		if (node_map[temp->data] == 1)
		{
			temp1 = temp;
			temp = temp->next;
			prev->next = temp;
			delete temp1;
		}
		else
		{
			node_map[temp->data] = 1;
			temp = temp->next;
			prev = prev->next;
		}
	}

	display(head);

	return 0;



}
