#include "stdafx.h"
#include<iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
void insert(node* &head, int data) {
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
void inorder(node* head) {
	if (head == NULL)
		return;
	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
}
int findMaxAndDel(node*& head) {
	if (head->right == NULL) {
		node* temp = head;
		int val = head->data;
		if (head->left == NULL) {
			head = NULL;
			delete temp;
			return val;
		}
		else {
			node* temp1 = head->left;
			head = temp1;
			delete temp;
			return val;
		}
	}
	else {
		return findMaxAndDel(head->right);
	}
}
int findMinAndDel(node*& head) {
	if (head->left == NULL) {
		node* temp = head;
		int val = head->data;
		if (head->right == NULL) {
			head = NULL;
			delete temp;
			return val;
		}
		else {
			node* temp1 = head->right;
			head = temp1;
			delete temp;
			return val;
		}
	}
	else
		return findMinAndDel(head->left);
}
void deleteNode(node* & head, int key) {
	if (head == NULL)
		return;

	if (head->data == key) {
		if (head->right != NULL) {
			int val = findMinAndDel(head->right);
			head->data = val;
		}
		else if (head->right == NULL) {
			if (head->left == NULL) {
				node* temp = head;
				head = NULL;         //    - (1)
				delete temp;
			}
			else {
				int val = findMaxAndDel(head->left);
				head->data = val;
			}
		}
		return;                 // Return is important as I have made head = NULL in (1). So, (2) and (3) will give error.
	}

	deleteNode(head->left, key);          // - (2)
	deleteNode(head->right, key);         // - (3)
}

int main()
{
	node* head = NULL;
	insert(head, 10);
	insert(head, 5);
	insert(head, 15);
	insert(head, 0);
	insert(head, 8);
	insert(head, 12);
	insert(head, 18);
	insert(head, 14);
	inorder(head);
	cout << endl;
	deleteNode(head, 10);
	inorder(head);
    return 0;
}
