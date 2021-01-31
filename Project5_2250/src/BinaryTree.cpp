#include "BinaryTree.h"
#include <string>
#include <iostream>

BinaryTree::BinaryTree() {
	root = new TreeNode;

	root->right
	= root->left
	= nullptr;
}

void BinaryTree::incrementCharCount(TreeNode *node) {
	node->charCount++;
}

void BinaryTree::inputChars(TreeNode *node, std::string chars) {
	if(root->letters == "") {				//create root node if there is none
		root->letters = chars;
		incrementCharCount(root);
	} else if(chars < node->letters) {		//string less than node value, assign to left node
		if(node->left == nullptr) {
			//assign char string to a new left node
			node->left = new TreeNode;
			node->left->letters = chars;
			node->left->charCount = 1;

			//set new leaf node's ptrs to nullptr
			node->left->left
			= node->left->right
			= nullptr;
		} else
			inputChars(node->left, chars);	//recursive function to go down the tree until a leaf node is found
	} else if(chars > node->letters) {		//string greater than current node value, assign to right node
		if(node->right == nullptr) {
			//assign char string to new right node
			node->right = new TreeNode;
			node->right->letters = chars;
			node->right->charCount = 1;

			//set new leaf node ptrs to nullptr
			node->right->left
			= node->right->right
			= nullptr;
		} else
			inputChars(node->right, chars);
	} else if (chars == node->letters) {
		incrementCharCount(node);	//if chars are not lower or higher, then they are the same, so increment current count of that char.
	}
}

void BinaryTree::printChars(TreeNode *node) {
	if(node == nullptr)
		return;

	//print characters in order from left to right most tree
	if(node->left != nullptr)
		printChars(node->left);
	if(node->letters != "")
		printf("%s: %d times\n",node->letters.c_str(), node->charCount);
	if(node->right != nullptr)
		printChars(node->right);
}

BinaryTree::~BinaryTree() {}
