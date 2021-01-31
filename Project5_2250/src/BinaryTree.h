//Header file for a binary tree
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <String>
class BinaryTree {
private:
	struct TreeNode {
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;
		int charCount = 0;
		std::string letters = "";
	};
public:
	BinaryTree();
	void printChars(TreeNode *);
	void inputChars(TreeNode *, std::string);
	void incrementCharCount(TreeNode *);
	TreeNode *root;
	~BinaryTree();
};
#endif
