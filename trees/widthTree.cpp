#include "stdafx.h"
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	int level;
};

void insert(node* &head, int data) {
	if (head == NULL) {
		node* newnode = new node;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->data = data;
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

int width(node* head) {
	int sum = 0, max = 0, count = 0, past_count = count;
	queue<node*> q;
	node* temp = head;
	temp->level = count;
	q.push(temp);

	while (!q.empty()) {
		temp = q.front();
		count = temp->level;
		if (past_count == count) {
			sum++;
			if (sum > max)
				max = sum;
		}
		else {
			if (sum > max)
				max = sum;
			sum = 1;
			past_count = count;
		}

		if (temp->left != NULL) {
			temp->left->level = count + 1;
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			temp->right->level = count + 1;
			q.push(temp->right);
		}
		
		q.pop();
	}
	return max;
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
	cout << width(head) << endl;
    return 0;
}
