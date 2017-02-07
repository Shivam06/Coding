#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node* next;
		node* prev;
		node(int x) {
			data = x;
			next = NULL;
			prev = NULL;
		}
};

void insert(node*& head, int x) {
	node* newnode = new node(x);
	if(head == NULL) {
		head = newnode;
	} 
	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}

void insert(node* &head, int x, int pos) {
/* pos tells the position after head where we want to insert the new node */
	node* newnode = new node(x);
	if(pos == 0) {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	else{
		int count = 1;
		node* temp = head;
		while (count < pos && temp!=NULL) {   /* Put exception if pos is much higher than length of linked list */
			temp = temp->next;
			count++;
		}
		if(temp == NULL) {
			cout << "Not Possible" << endl;
			return;
		}
		node* temp_next = temp->next;
		temp->next = newnode;
		newnode->next = temp_next;
		newnode->prev = temp;
	}
}

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
	node* head = NULL;
	insert(head, 10);
	insert(head, 20);
	insert(head, 25);
	//cout << head->next->next->prev->data << endl;
	display(head);
	insert(head, 2, 3);
	display(head);
	return 0;
}