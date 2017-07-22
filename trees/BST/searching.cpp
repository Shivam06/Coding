#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int key;
	Node *left,*right;
};

Node* createNode(int data) {
    Node* newnode = new Node;
    newnode->key = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(Node*& root, int data) {
	if (root == NULL) 
		root = createNode(data);
	else {
		if (root->key >= data) {
			if (root->left != NULL)
				insert(root->left, data);
			else {
				root->left = createNode(data);
			}
		}
		else {
			if (root->right != NULL)
				insert(root->right, data);
			else {
				root->right = createNode(data);
			}
		}
	}
} 

void insert_array(Node*& root, vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		insert(root, v[i]);
	}
}

int search(Node* root, int key) {
	if (root == NULL)
		return 0;
	if (root->key == key) {
		return 1;
	}

	return search(root->left, key) || search(root->right, key);
}


int main() {
	Node* root = NULL;
	int arr[] = {50, 30, 70, 20, 40, 60, 80};
	vector<int> v(arr, arr+7);
	insert_array(root, v);
	cout << search(root, 10) << endl;
	return 0;
}