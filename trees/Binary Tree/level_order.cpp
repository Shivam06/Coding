#include<iostream>
#include<algorithm>
#include<math.h>
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

int height(node* head) {
	if(head == NULL)
		return -1;
	else
		return max(height(head->left),height(head->right)) + 1;
}

void print_single_level(node* head, int level) {
	if(level == 0)
		cout<<head->data<<endl;
	else if(level > 0) {
		print_single_level(head->left, level-1);
		print_single_level(head->right, level-1);
	}
	else {
		cout<<"Level can't be negative"<<endl;
	}
}

void level_order_traversal(node* head) {
	for(int h = 0; h<= height(head); h++) {
		print_single_level(head, h);
	}
}

void display(node* head) {
	if(head == NULL)
		return;
	display(head->left);
	cout << head->data << " " << endl;
	display(head->right);
}

int main() {
	node* head = new node(10);
	head->left = new node(6);
	head->right = new node(14);
	head->left->left = new node(4);
	head->left->right = new node(8);
	head->right->left = new node(12);
	head->right->right = new node(18);
	//display(head);
	node* temp = new node(3);
	level_order_traversal(head);
	return 0;
}