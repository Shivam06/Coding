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

    /*int diameter() {          // Method for finding diameter of the tree 
        // O(n^2) run time. I want better than this!
        if (this == NULL)
            return 0;
        int dia = (this->left)->height() + (this->right)->height() + 3;
        return max(max((this->left)->diameter(), (this->right)->diameter()), dia);
    }*/

    int diameter_helper(BST* head) {
        static int static_dia = 0;
        if(this == NULL)
            return -1;

        int lh = (this->left)->diameter_helper(head) + 1;
        int rh = (this->right)->diameter_helper(head) + 1;
        int dia = lh + rh + 1;
        if(dia > static_dia)
            static_dia = dia;
        if(this != head)
            return max(lh, rh);
        else
            return static_dia;
    }

    int diameter(){
        return diameter_helper(this);
    }
};