#include<iostream>
#include"BST.h"
using namespace std;

int main() {
	BST* bst = new BST(10);
	bst->insert(20);
	bst->insert(22);
	bst->insert(21);
	bst->insert(19);
	bst->insert(18);
	bst->insert(24);
	bst->insert(26);
	bst->insert(28);
	bst->insert(30);
	bst->inorder_traversal();
	cout << endl;
	cout << bst->diameter() << endl;
	return 0;
}