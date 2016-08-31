#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;

struct node {
	int data;
	node* link;
};

void push_last(node**h, int x)
{
	node* newnode = new node;
	newnode->data = x;
	newnode->link = NULL;

	newnode->link = *h;
	*h = newnode;
}

void display(node* h)
{
	node* temp = h;
	stack <int> stk;
	while (temp != NULL)
	{
		stk.push(temp->data);
		temp = temp->link;
	}
	
	while (!stk.empty())
	{
		cout << stk.top() << "\t";
		stk.pop();
	}
	cout << endl;
}

int findK(node* h, node* & pvt, int k)
{
	static int count = 0;

	if (count == k)
		return pvt->data;

	else
	{
		pvt = pvt->link;
		count++;
		return findK(h, pvt, k);
	}
}

int main()
{
	node* head = NULL;
	push_last(&head, 35);
	push_last(&head, 23);
	push_last(&head, 89);
	push_last(&head, 17);
	push_last(&head, 12);
	display(head);
	cout << findK(head, head, 2) << endl;
    return 0;
}
