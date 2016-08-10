#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

void insert(node*& root, int data) {
	if (root == NULL) {
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return;
	}

	if (root->data < data) {
		insert(root->right, data);
	}
	else {
		insert(root->left, data);
	}
}

void inorder_traversal(node* root) {
	if (root == NULL)
		return;

	inorder_traversal(root->left);
	cout << root->data << " ";
	inorder_traversal(root->right);
}

int height(node* head) {
	if (head == NULL)
		return -1;
	else {
		return max(height(head->left), height(head->right)) + 1;
	}
}

int maxNodesBetweenLeaves(node* head) {
	if (head == NULL)
		return 0;
	else {
		int headLeavesCount = height(head->left) + height(head->right) + 3;
		return max(max(headLeavesCount, maxNodesBetweenLeaves(head->left)), maxNodesBetweenLeaves(head->right));
	}
}

int optimizedmaxNodesBetweenLeaves(node* head,int & h) {
	if (head == NULL) {
		h = 0;
		return 0;
	}
	else {
		int lh = 0;
		int rh = 0;
		int lc = optimizedmaxNodesBetweenLeaves(head->left, lh);
		int rc = optimizedmaxNodesBetweenLeaves(head->right, rh);
		h = max(lh, rh) + 1;
		return max(lh + rh + 1, max(lc, rc));
	}
}

int main()
{
	node* head = NULL;
	insert(head, 10);
	insert(head, 4);
	insert(head, 3);
	insert(head, 5);
	insert(head, 6);
	insert(head, 7);
	insert(head, 11);
	insert(head, 2);
	insert(head, 1);
	int h = 0;
	cout << optimizedmaxNodesBetweenLeaves(head,h) << endl;
	return 0;
}
