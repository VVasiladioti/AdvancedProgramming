// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = NULL;
// implement the functions described by these headers
void insert_integer(struct node** tree, int value) {

	if (*tree == nullptr) {
		*tree = new node;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
		(*tree)->value = value;
	}
	else if (value < (*tree)->value) {
		insert_integer(&(*tree)->left, value);
	}
	else {
		insert_integer(&(*tree)->right, value);
	}
}

void print_tree(struct node* tree) {
	if (tree != NULL) {
		print_tree(tree->left);
		cout << "The value is: " << tree->value << "\n";
		print_tree(tree->right);
	}
}

void terminate_tree(struct node * tree) {
	if (tree != NULL) {
		terminate_tree(tree->left);
		terminate_tree(tree->right);
		delete tree;
	}
}


 /* Main function */
int main() {
	// call your implemented functions here to test
	struct node * tree = NULL;
	
	insert_integer(&tree, 8);
	insert_integer(&tree, 10);
	insert_integer(&tree, 5);
	insert_integer(&tree, 9);
	insert_integer(&tree, 22);
	insert_integer(&tree, 3);
	insert_integer(&tree, 2);

	// the binary search tree
	print_tree(tree);
	terminate_tree(tree);
	return 0;
}
