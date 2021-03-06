// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = NULL;

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	terminate_tree(root);
}


// implement the functions described by these headers
void BinarySearchTree::insert_integer(struct node** tree, int value) {
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

bool BinarySearchTree::search_tree(struct node **tree, int value) {
	if (*tree == nullptr) {
		return(false);
	}
	else {
		if (value == (*tree)->value) 
			return(true);
		
		else {
			if (value < (*tree)->value)
				return(search_tree(&(*tree)->left, value));
			else
				return(search_tree(&(*tree)->right, value));
		}
	}
}

void BinarySearchTree::print_tree(struct node* tree) {
	if (tree != NULL) {
		print_tree(tree->left);
		cout << "The value is: " << tree->value << "\n";
		print_tree(tree->right);
	}
}

void BinarySearchTree::terminate_tree(struct node * tree) {
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

	BinarySearchTree BST;
	
	BST.insert_integer(&tree, 8);
	BST.insert_integer(&tree, 10);
	BST.insert_integer(&tree, 5);
	BST.insert_integer(&tree, 9);
	BST.insert_integer(&tree, 22);
	BST.insert_integer(&tree, 3);
	BST.insert_integer(&tree, 2);

	// the binary search tree
	BST.search_tree(&tree,9);
	BST.print_tree(tree);
	BST.terminate_tree(tree);
	return 0;
}
