#include<iostream>
using namespace std;

class BST {
public:
	int data;
	BST* left;
	BST* right;
	bool iscreated;
    BST(int x) {  // Parametrized Constructor
    	data = x;
    	left = NULL;
    	right = NULL;
    	iscreated = true;
    }

    BST() {      // Default Constructor
    	left = NULL;
    	right = NULL;
    	iscreated = false;
    }

    void insert(int x) {
    	if (!iscreated) {
    		this->data = x;
    	}
    	else {
    		if(this->data < x) {
    			if(this->right != NULL)
    				(this->right)->insert(x);
    			else
    				this->right = new BST(x);
    		}
    		else {
    			if(this->left != NULL)
    			    (this->left)->insert(x);
    			else
    				this->left = new BST(x);
    	    }
    	}  // Method for insertion     // Method for insertion in tree
    }

    void inorder_traversal() {
        if(this == NULL)
            return;
        cout << this->data << " ";
        (this->left)->inorder_traversal();
        (this->right)->inorder_traversal();     // Method for inorder traversl of tree
    }

    int height() {
        if(this == NULL)
            return -1;
        else {
            return max((this->left)->height(), (this->right)->height()) + 1;
        }           // Method for finding height of tree
    }

    int diameter() {          // Method for finding diameter of the tree
        if (this == NULL)
            return 0;
        int dia = (this->left)->height() + (this->right)->height() + 3;
        return max(max((this->left)->diameter(), (this->right)->diameter()), dia);
    }
};