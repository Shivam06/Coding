#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	char data;
	node* left;
	node* right;
};

void insert(node* &head, char data) {
	if (head == NULL)
	{
		node* newnode = new node;
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		head = newnode;
	}
}
void inorder_traversal(node* root) {
	if (root == NULL)
		return;

	inorder_traversal(root->left);
	cout << root->data << " ";
	inorder_traversal(root->right);
}
void insertInTreeHelper(node* &head, int& pre, int in_start, int in_end, string inorder, string preorder) {
	if (in_end < in_start) {
		return;
	}

	int in = in_start;
	while (inorder[in] != preorder[pre])
		in++;

	insert(head, inorder[in]);
	pre++;
	
	insertInTreeHelper(head->left, pre, in_start, in-1, inorder, preorder);
	insertInTreeHelper(head->right, pre, in+1, in_end, inorder, preorder);

}

void insertInTree(node* &head, string inorder, string preorder) {
	int pre = 0;
	int in_start = 0;
	int in_end = inorder.size() - 1;
	insertInTreeHelper(head, pre, in_start, in_end, inorder, preorder);
}

int main()
{
	string s1 = "GDHBIEJAFC";
	string s2 = "ABDGHEIJCF";
	node* head = NULL;
	insertInTree(head, s1, s2);
	inorder_traversal(head);
    return 0;
}

