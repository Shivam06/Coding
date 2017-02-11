#include<iostream>
using namespace std;

class Tree {
public:
	int data;
	Tree* left;
	Tree* right;
	Tree(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}

	
};

void insert(Tree* head, int x) {
	if (head == NULL)
		return;

	if(head->data >= x) {
		if (head -> left != NULL)
			insert(head->left, x);
		else
			head->left = new Tree(x);
	}
	else {
		if (head->right != NULL)
			insert(head->right, x);
		else
			head->right = new Tree(x);
	}
}

void pre_traversal(Tree* head) {
	if(head == NULL) 
		return;
	pre_traversal(head->left);
	cout << head->data << " ";
	pre_traversal(head->right);
}

int height()