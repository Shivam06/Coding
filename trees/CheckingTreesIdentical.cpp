#include "stdafx.h"
#include<iostream>
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

bool checkSimilar(node* r1, node* r2) {
	if (r1 != NULL && r2 != NULL) {
		if (r1->data == r2->data) {
			return checkSimilar(r1->left, r2->left) && checkSimilar(r1->right, r2->right);
		}
		else {
			return false;
		}
	}
	else {
		if (r1 == NULL && r2 == NULL)
			return true;
		else {
			return false;
		}
	}
}

int main()
{
	node* root1 = NULL;
	node* root2 = NULL;
	insert(root1, 13);
	insert(root1, 15);
	insert(root1, 11);
	insert(root1, 9);
	insert(root1, 12);
	insert(root1, 14);
	insert(root2, 13);
	insert(root2, 15);
	insert(root2, 11);
	insert(root2, 9);
	insert(root2, 12);
	insert(root2, 18);
	inorder_traversal(root1);
	cout << endl;
	inorder_traversal(root2);
	cout << endl;
	cout << checkSimilar(root1, root2) << endl;
    return 0;
}
