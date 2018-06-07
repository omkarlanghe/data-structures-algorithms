#ifndef BST_H
#define BST_H
#include<stdbool.h>

typedef struct TreeNode
{
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
}TREENODE_T;

	TREENODE_T *createBST(int noOfnodes);
	TREENODE_T *insert(TREENODE_T *root, int data);
	_Bool search(TREENODE_T *root, int data);
	void preorder(TREENODE_T *);
	void inorder(TREENODE_T *);
	void postorder(TREENODE_T *);
	int countleafNodes(TREENODE_T *root);
	int countDepth(TREENODE_T *root);
	int countnonleafNodes(TREENODE_T *root);
	int countAllNodes(TREENODE_T *root);
	_Bool isBalancedTree(TREENODE_T *root);
	void freeAllnodes(TREENODE_T *root);		
#endif
