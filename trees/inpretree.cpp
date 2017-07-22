#include<iostream>
using namespace std;


struct Node
{
  int data;
  Node* left;
  Node* right;
};


Node* createNode(int data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void buildTreeHelper(int in[], int pre[], int inStrt, int inEnd, Node*& root, Node* tempRoot, int dir) {
    static int idx = 0;
    //cout << idx << endl;
    if (inStrt > inEnd)
        return;
    
    if (root == NULL) {
        root = createNode(pre[idx]);
        tempRoot = root;
    }
    else {
        if (dir == 0) {
        	//cout << dir << " "<< tempRoot->data << " ";
            tempRoot->left = createNode(pre[idx]);
            tempRoot = tempRoot->left;
            //cout << tempRoot -> data <<endl; 
        }
        else {
        	//cout << dir << " "<< tempRoot->data << " ";
            tempRoot->right = createNode(pre[idx]);
            tempRoot = tempRoot->right;
            //cout << tempRoot -> data <<endl; 
        }
    }
    
    
    int mid;
    for (int i = inStrt; i <= inEnd; i++) {
        if(in[i] == pre[idx])
            mid = i;
    }
    idx++;
    //cout << in[mid] << " " << inStrt <<" " << mid << " " <<inEnd << endl;

    buildTreeHelper(in, pre, inStrt, mid-1, root, tempRoot, 0);
    buildTreeHelper(in, pre, mid+1, inEnd, root, tempRoot, 1);
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    Node* root = NULL;
    Node* tempRoot = root;
    int dir = 0;
    buildTreeHelper(in, pre, inStrt, inEnd, root, tempRoot, dir);
    return root;
}

void postTrav(Node* head){
	if(head==NULL)
	    return;
	
	postTrav(head->left);
	postTrav(head->right);
	cout<<head->data<<"  ";
}

int main() {
	int inArr[] = {2, 4, 1, 6, 3, 7};
	int preArr[] = {1, 2, 4, 3, 6, 7};
	Node* root = buildTree(inArr, preArr, 0, 5);
	cout <<endl;
	//cout << root->left->left->data << endl;
	postTrav(root);
	return 0;
}