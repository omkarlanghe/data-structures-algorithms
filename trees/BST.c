#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

TREENODE_T *createBST(int noOfnodes)
{

	TREENODE_T *root = NULL;
	for(int i=0 ; i<noOfnodes ; i++)
	{
		int data;
		printf("Enter data to add in BST:\n");
		scanf("%d",&data);
		root = insert(root,data);		
	}
	return root;
	
}
TREENODE_T *insert(TREENODE_T *root, int data)
{
	TREENODE_T  *treenode = (TREENODE_T *)malloc(sizeof(TREENODE_T));
	
	if(NULL == treenode)
	{
		printf("failed to add data..");
	}
	else
	{
		treenode->data = data;
		treenode->left = NULL;
		treenode->right = NULL;
	
		if(NULL == root)
		{
			root = treenode;
		}
		else
		{
			TREENODE_T *traverse = root;
			
			while(1)
			{
				if(treenode->data >= traverse->data)
				{
					if(traverse->right == NULL)
					{
						traverse->right = treenode;
						break;
					}
					else
					{
						traverse = traverse->right;
					}
				}
				else
				{
					if(traverse->left == NULL)
					{
						traverse->left = treenode;
						break;
					}
					else
					{
						traverse = traverse->left;
					}
				}
			}
		}
	}
	return root;
}
_Bool search(TREENODE_T *root, int data)
{
	int flag = 0;

	if(root == NULL)
	{
		return;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	} 
	
	if(root->left)
	{
		if(data == root->data)
		{
			flag = 1;
		}
	}
	if(root->right)
	{
		if(data == root->data)
		{
			flag = 1;
		}
	}
	return flag;
}
void preorder(TREENODE_T *root)
{
	if(root == NULL)
		return;
	
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TREENODE_T *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}

void postorder(TREENODE_T *root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}

void freeAllnodes(TREENODE_T *root)
{
	if(root == NULL)
	{
		return;
	}
	freeAllnodes(root->left);
	freeAllnodes(root->right);
	free(root);
}

int countleafNodes(TREENODE_T *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return countleafNodes(root->left) + countleafNodes(root->right);
}
int countDepth(TREENODE_T *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return 1;	
	}
	
	if(root->left && root->right)
	{
		int leftdepth = countDepth(root->left);
		int rightdepth = countDepth(root->right);
		
		return 1 + (leftdepth > rightdepth ? leftdepth : rightdepth);
	}
	else if(root->left)
	{
		return 1 + countDepth(root->left);	
	}
	else
	{
		return 1 + countDepth(root->right);
	}
}

int countnonleafNodes(TREENODE_T *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL)
	{
		return 1 + countnonleafNodes(root->right);
	}
	
	if(root->right == NULL)
	{
		return 1 + countnonleafNodes(root->left);
	}
	
	return 1 + countnonleafNodes(root->left) + countnonleafNodes(root->right);
}

int countAllNodes(TREENODE_T *root)
{
	if(root == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	
	return 1 + countAllNodes(root->left)+ countAllNodes(root->right);
}

_Bool isBalancedTree(TREENODE_T *root)
{
	if(root)
	{
		if(abs(countDepth(root->left) - countDepth(root->right)) < 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;	
}

int main()
{
	int noOfnodes,data;
	TREENODE_T *root = NULL;
	
	printf("Enter the number of nodes you want to create in a tree:\n");
	scanf("%d",&noOfnodes);
	
	root = createBST(noOfnodes);
	
	printf("\nPre-order Traversal:-\n");
	preorder(root);
	
	printf("\n");
	
	printf("\nIn-order Traversal:-\n");
	inorder(root);
	
	printf("\n");
	
	printf("\nPost-order Traversal:-\n");
	postorder(root);
	
	printf("\n");
	
	printf("\ncount of leaf nodes:- %d\n",countleafNodes(root));

	printf("\nDepth of the tree:- %d\n",countDepth(root));

	printf("\ncount of non-leaf nodes:- %d\n",countnonleafNodes(root));
	
	printf("\ncount of all nodes in a tree:- %d\n",countAllNodes(root));
	
	if(isBalancedTree(root))
	{
		printf("Tree is balanced\n");
	}
	else
	{
		printf("Tree is not balanced\n");
	}
	
	printf("Enter the element to be searched in a tree:\n");
	scanf("%d",&data);
	
	if(search(root,data) == 1)
	{
		printf("Element found in a tree:\n");
	}
	else
	{
		printf("Element no found in a tree:\n");
	}
	
	freeAllnodes(root);
	
	return 0;
}
