#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};


class tree{	
node* head;
void inTravHelper(node* head){
	if(head == NULL){
		return;
	}
	inTravHelper(head->left);
	cout<<head->data<<"  ";
	inTravHelper(head->right);
}

void preTravHelper(node* head){
	if(head == NULL)
	    return;
	
	cout<<head->data<<"  ";
	preTravHelper(head->left);
	preTravHelper(head->right);    
}

void postTravHelper(node* head){
	if(head==NULL)
	    return;
	
	postTravHelper(head->left);
	postTravHelper(head->right);
	cout<<head->data<<"  ";
}
public:
	tree(node* &h){
		head= h;
	}
	
	void inorderTraversal(){
		inTravHelper(head);
	}
	
	void preOrderTraversal(){
		preTravHelper(head);
	}
	
	void postOrderTraversal(){
		postTravHelper(head);
	}

};

int main(){
	node* head = new node;
	head->data =13;
	node* node1 = new node;
	node1->data = 9;
	head -> left = node1;
	node* node2 = new node;
	node2->data = 15;
	head->right = node2;
	
	node* node3 = new node;
	node3->data = 7;
	node1->left = node3;
	node* node4 = new node;
	node4->data = 11;
	node2->left = node4;
	node3->left = NULL;
	node3->right = NULL;
	node1->right = NULL;
	node2->right = NULL;
	node4->left = NULL;
	node4->right = NULL;
	tree t1(head);
	t1.inorderTraversal();
	cout<<endl;
	t1.preOrderTraversal();
	cout<<endl;
	t1.postOrderTraversal();
	return 0;
}
