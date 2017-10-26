#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void insertNode(node*& head, int data) {
	node* newnode = new node;
	newnode->data = data;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
	}

	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display(node* head) {
	node* temp = head;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void deleteNode(node*& head, int k) {
	node* prev = new node;
	node* temp = head;
	prev->next = head;

	while (temp!=NULL) {
		//cout << temp->data << endl;
		if (temp->data == k) {
			int flag = (temp == head);
			prev->next = temp->next;
			free(temp);
			temp = prev->next;
			if (flag) {
				head = temp;
			}
		}
		else {
			prev = temp;
			temp = temp->next;
		}
	}
}

int main() {
	node* head = NULL;
	insertNode(head, 4);
	insertNode(head, 7);
	insertNode(head, 21);
	insertNode(head, 3);
	insertNode(head, 1);
	insertNode(head, 4);
	deleteNode(head, 4);
	display(head);
	return 0;
}