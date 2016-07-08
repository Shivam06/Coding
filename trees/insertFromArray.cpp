#include<iostream>
using namespace std;



struct node{
	int data;
	node* left;
	node* right;
};

node* head = NULL;

void insert_node(node* &h, int data){

if(h==NULL){
	h = new node;
	h->data = data;
	h->left = NULL;
	h->right = NULL;
	return;
}

else {
	h->data>data ? insert_node(h->left,data) : insert_node(h->right,data);
}
}

void parse(int* arr, int a,int b){
	if(a==b){
		insert_node(head,arr[a]);
		return;
	}
	if(a>b)
	{
		return;
	}
	else{
		int n = b-a+1;
		insert_node(head,arr[n/2]);
		parse(arr,a,n/2-1);
		parse(arr,n/2 + 1,b);	
	}
}

void inorder(node* h){
	if(h==NULL){
		return;
	}
	
	inorder(h->left);
	cout<<h->data<<" ";
	inorder(h->right);
}

int main(){
	int array[] = {1,6,9,17};
	parse(array,0,3);
	inorder(head);
	return 0;
}
