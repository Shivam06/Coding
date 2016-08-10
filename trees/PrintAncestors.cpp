#include "stdafx.h"
#include<iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

void insert(node*& head, int data) {
	if (head == NULL) {
		node* newnode = new node;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		head = newnode;
	}
	else {
		if (head->data < data)
			insert(head->right, data);
		else
			insert(head->left, data);
	}
}

void helper(node* head, node* key, int& flag) {
	static node* pastNode = head;

	if (head == NULL)
		return;

	if (head == key) {
		flag = 1;
		pastNode = head;
		return;
	}
	helper(head->left, key, flag);
	helper(head->right, key, flag);

	if (flag) {
		if (head->left == pastNode || head->right == pastNode) {
			cout << head->data << " ";
			pastNode = head;
		}
	}
}

int printAncestors(node* head,node* key) {
	if (head == key)
		return false;
	int flag = 0;
	helper(head, key, flag);
	return flag;
}

int main()
{
	node* head = NULL;
	insert(head, 10);
	insert(head, 5);
	insert(head, 15);
	insert(head, 4);
	insert(head, 3);
	insert(head, 7);
	node* key = new node;
	key->data = 13;
	if (printAncestors(head, head->left->left->left))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
    return 0;
}
