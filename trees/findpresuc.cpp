#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int key;
	Node *left,*right;
};


Node* rightmost(Node* root) {
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* leftmost(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

void findPreSucHelper(Node* root, Node* pre, Node* suc, int key) {
    if (root == NULL) {
        if (pre != NULL) {
            cout << pre->key << " ";
        }
        else
            cout << "-1"<< " ";
            
        if (suc != NULL) {
            cout << suc->key;
        }
        else 
            cout << "-1";
        return;
    }
    
    if (root->key == key) {
        if (root->left != NULL) {
            cout << rightmost(root->left)->key<< " "; // complete it!
        }
        else {
            findPreSucHelper(root->left, pre, suc, key);
        }
        
        if (root->right != NULL) {
            cout << leftmost(root->right)->key << " ";
        }
        else {
            findPreSucHelper(root->right, pre, suc, key);
        }
    }
    else if (root->key > key) {
        findPreSucHelper(root->left, pre, root, key);
    }
    else {
        findPreSucHelper(root->right, root, suc, key);
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    findPreSucHelper(root, pre, suc, key); 
}

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

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    vector<int> v(arr, arr+7);
    insert_array(root, v);
    Node* pre, *suc;
    findPreSuc(root, pre, suc, 20);
    return 0;
}