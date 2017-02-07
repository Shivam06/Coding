#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node* next;
		node(int x) {
			data = x;
			next = NULL;
		}
};

void display(node* head) {
	int count = 0;
	while (head != NULL && count < 10) {
		cout << head->data << " ";
		head = head->next;
		count++;
	}
	cout << endl;
}

int main() {
	node* head = new node(10);
	head->next = new node(2);
	head->next->next = new node(8);
	head->next->next->next = head;
	display(head);
	return 0;
}