#include "stdafx.h"
#include<iostream>
using namespace std;

struct node {
	int data;
	node* left = NULL;
	node* right = NULL;
};

void insert(node* & head,int data) {
	if (head == NULL) {
		node* newnode = new node;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		head = newnode;
	}
	else {
		if (head->data > data) {
			insert(head->left, data);
		}
		else {
			insert(head->right, data);
		}
	}
}

void printHelper(node* head, int k, int count) {
	if (head == NULL)
		return;

	if (count == k)
		cout << head->data << " ";

	printHelper(head->left, k, count + 1);
	printHelper(head->right, k, count + 1);
}

void printKdistNode(node* head, int k) {
	int count = 0;
	printHelper(head, k, count);
}

int main()
{
	node* head = NULL;
	insert(head, 10);
	insert(head, 5);
	insert(head, 2);
	insert(head, 7);
	insert(head, 15);
	insert(head, 12);
	printKdistNode(head, 2);
    return 0;
}
