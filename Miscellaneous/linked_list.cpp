#include<iostream>
using namespace std;

class node {
public:
	node* next;
	int data;
	node(int x) {
		data = x;
		next = NULL;
	}
};

void display(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	node* head = new node(5);
	head->next = new node(10);
	head->next->next = new node(15);
	display(head);
	return 0;
}