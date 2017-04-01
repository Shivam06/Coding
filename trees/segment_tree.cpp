#include<iostream>
using namespace std;

struct node {
	int data, lower_limit, upper_limit;
	node* left;
	node* right;
};

node* construct_node() {
	node* newnode = new node;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void construct_seg_tree(node*& head, int arr[], int start, int end) {
	
	head->lower_limit = start;
	head->upper_limit = end;

	if (start >= end) {
		head->data = arr[start];
		return;
	}

	int mid = (start + end)/2;
	head->left = construct_node();
	head->right = construct_node();
	construct_seg_tree(head->left, arr, start , mid);
	construct_seg_tree(head->right, arr, mid + 1, end);
	
	head->data = head->left->data + head->right->data;
}	

int find_sum(node* head, int l, int u) {
	if (head->lower_limit >= l && head->upper_limit <= u)
		return head->data;

	else if (head->lower_limit > u ||  head->upper_limit < l)
		return 0;

	else 
		return find_sum(head->left, l, u) + find_sum(head->right, l, u);
}



void update_seg_tree(node*& head, int idx, int d2) {
	
	if (head->lower_limit == idx && head->upper_limit == idx){
		head->data = d2;
		return;
	}

	int mid = (head->lower_limit + head->upper_limit)/2;
	if (idx <= mid)
		update_seg_tree(head->left, idx, d2);
	else
		update_seg_tree(head->right, idx, d2);

	head->data = head->left->data + head->right->data;
}

void update (int arr[], node*& head, int idx, int d2) {
	arr[idx] = d2;
	update_seg_tree(head, idx, d2);
}

void display(node* head) {
	if ( head == NULL )
		return;

	display(head->left);
	cout << head->data << " ";
	display(head->right);
}

int main() {
	int arr[10] = {4,2,3,1};
	node* head = new node;
	construct_seg_tree(head, arr, 1, 2);
	

	update(arr, head, 1, 4);
	cout << find_sum(head, 0,3) << endl;
	return 0;
}