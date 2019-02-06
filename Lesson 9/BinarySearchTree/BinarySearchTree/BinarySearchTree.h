#pragma once

class BinarySearchTree {
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert_integer(struct node** tree, int value);
	bool search_tree(struct node **tree, int value);
	void print_tree(struct node* tree);
	void terminate_tree(struct node * tree);
	
	
private:
	/*struct node {
		int value;
		struct node* left;
		struct node* right;
	};*/
	struct node* root;
	struct node** tree=nullptr;
};