#include<iostream>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void level_order_traversal(node* head) {
	queue<node*> q1;
	q1.push(head);
	while(!q1.empty()){
		node* temp = q1.front();
		cout << temp->data << endl;
		if(temp->left != NULL)
			q1.push(temp->left);
		if(temp->right != NULL)
			q1.push(temp->right);
		q1.pop();
	}
}

int main() {
	node* head = new node(10);
	head->left = new node(6);
	head->right = new node(14);
	head->left->right = new node(8);
	head->right->right = new node(16);
	level_order_traversal(head);
	return 0;
}
