#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

void insert(node*& head, int data) {
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
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

void split(node* head, node*& start_a, node*& start_b) {
	start_a = head;
	node* slow = head, *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	start_b = slow->next;
	slow->next = NULL;
	//display(start_a);
	//cout << endl;
	//display(start_b);
}

node* merge(node* a, node* b) {
	node* head = NULL;
    node* temp = head;
    node* prev_a, *prev_b;
    prev_a = new node;
    prev_b = new node;
    prev_a->next = a;
    prev_b->next = b;
    
    while (a!=NULL && b!=NULL) {
    	//cout << "Done" << endl;
        if (a->data <= b->data) { 
	        //node* temp_a = a->next;
	        //cout << 1 << endl;
	        prev_a->next = a->next;
	        //cout << 2 << endl;
	        if (!head) {
	            head = a;
	            temp = head;
	        }
	        else {
	            temp->next = a;
	            temp = temp->next;
	        }
	        //cout << 3 << endl;
	        a = a->next;
	        //cout << 4 << endl;
    	}

    	else {
    		//cout << 1 << endl;
    		prev_b->next = b->next;
    		//cout << 2 << endl;
    		if(!head) {
    			head = b;
    			temp = head;
    		}
    		else {
    			temp->next = b;
    			temp = temp->next;
    		}
    		//cout << 3 << endl;
    		b = b->next;
    		//cout << 4 << endl;
    	}

    }
    
    while (b != NULL) {
        node* t = b;
        b = a;
        a = t;
    }
    
    while (a != NULL) {
        temp->next = a;
        temp = temp->next;
        a = a->next;
    }
    return head;
}

void merge_sort(node* &head) {
	if (head == NULL || head->next == NULL) 
		return;
	node* start_a;
	node* start_b;
	split(head, start_a, start_b);
	//cout << "Before Merge" << endl<< endl;
	//display(start_a);
	//cout << "\t";
	//display(start_b);
	//cout << endl;
	merge_sort(start_a);
	merge_sort(start_b);
	//cout << "After Merge" << endl << endl;
	//display(start_a);
	//cout <<"\t";
	//display(start_b);
	head = merge(start_a, start_b);
	//cout << endl;
	//cout << "Combined" <<endl << endl;
	//display(head);
	//cout << endl << endl;
}

node *removeDuplicates(node *root)
{
    node* temp = root;
    node* prev = new node;
    prev->next = temp;
    while (temp->next != NULL) {
    	cout << temp->data << endl;
        if (temp->data == temp->next->data) {
            prev->next = temp->next;
            free(temp);
            node* temp = prev->next;
        }
        else {
        	prev = temp;
            temp = temp->next;
        }
    }
    return root;
}

int main() {
	node* head = NULL;
	insert(head, 5);
	insert(head, 3);
	insert(head, 1);
	insert(head, 2);
	insert(head, 8);
	insert(head, 6);
	insert(head, 3);
	insert(head, 3);
	//display(head);
	merge_sort(head);
	//cout << endl;
	display(head);
	cout << endl;
	head = removeDuplicates(head);
	display(head);
	return 0;
}