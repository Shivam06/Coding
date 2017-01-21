#include<iostream>
using namespace std;

class node {
public:
	node* left;
	node* right;
	int data;
};

node* createnode(int data) {
	node* newnode = new node;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;
	return newnode;
}

void insert(node*& head, int data) {
	if(head == NULL) {
		head = createnode(data);
	}
	else {
		if(head->data >= data){
			insert(head->left, data);
		}
		else {
			insert(head->right, data);
		}
	}
}

void display(node* head) {
	if(head == NULL)
		return;
	display(head->left);
	cout<<head->data<<" ";
	display(head->right);
}

int main() {
	node* head = NULL;
	insert(head, 10);
	insert(head, 5);
	insert(head, 14);
	insert(head, 12);
	display(head);
	return 0;
}