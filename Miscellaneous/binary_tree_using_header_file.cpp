#include<iostream>
#include "Tree.h"
using namespace std;

int main() {
	Tree* tree = new Tree(3);
	insert(tree,8);
	insert(tree, 9);
	pre_traversal(tree);
	return 0;
}

