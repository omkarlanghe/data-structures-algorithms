#include "singlyLL.h"
#include<stdio.h>
#include<stdlib.h>
NODE_T *Create(const int noOfNodes);
NODE_T *Insert(NODE_T *head, const int position, const int data);
NODE_T *Delete(NODE_T *head, const int position);
NODE_T *Display(NODE_T *head);
int search(NODE_T *head, const int data);
void freeLL(NODE_T *head);

NODE_T* Create(const int noOfNodes)
{
	printf("\nEntry:%s\n",__FUNCTION__);
	NODE_T *head = NULL;
	for(int i=0;i<noOfNodes;i++)
	{
		int data;
		printf("Enter the the data to add :\n");
		scanf("%d",&data);
		Insert(head,i+1,data);
	}
	return head;
}

NODE_T *Insert(NODE_T *head, const int position, const int data)
{
	printf("\nEntry:%s\n",__FUNCTION__);
	if(position<1)
	{
		printf("You have entered invalid position,cannot add..");
	}
	else
	{
		NODE_T *temp = (NODE_T *)malloc(sizeof(NODE_T));
		temp->data = data;
		temp->next = NULL;
		
		if(position == 1)
		{
			if(head != NULL)
			{
				temp->next = head;	
			}
			head = temp;		
		}
		else if(head != NULL)
		{
			NODE_T *traverse = head;
			int pos = position;
			//this check of traverse->next makes sure that if user enters position beyond length of a linked list then we stop at last node, insert the new node after that. It also helps in preventing the segmentation fault which will occur due to memory traverse beyond last node.
			while(traverse->next && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			temp->next = traverse->next;
			traverse->next = temp;
		}
		
		else
		{
		//control will enter in this else, if positon is other than 1 and head is NULL i.e there are no nodes in linked list .Hence temp should be freed as it is not going to be added in linked list. 
			printf("You have entered invalid position,cannot add..");
			free(temp);
		}
	}
	printf("\nExit:%s\n",__FUNCTION__);
	return head;
}
NODE_T *Delete(NODE_T *head, const int position)
{
	printf("\nEntry:%s\n",__FUNCTION__);
	if(head)
	{
		NODE_T *deleteNode = NULL;
		if(position == 1)
		{
			deleteNode = head;
			head = head->next;
			deleteNode->next = NULL;
		}
		else
		{
			NODE_T *traverse = head;
			int pos = position;
			
			while(traverse && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			if(traverse==NULL)
			{
				printf("You have entered incorrect positoin to delete,cannot delete\n");
			}
			else
			{
				deleteNode = traverse->next;
				traverse->next = deleteNode->next;
				deleteNode->next = NULL;
			}
		}
		if(deleteNode)
		{
			free(deleteNode);
		}
		
	}
	printf("\nExit:%s\n",__FUNCTION__);
	return head;	
}
NODE_T *Display(NODE_T *head)
{
	printf("\nEntry:%s\n",__FUNCTION__);
	while(head)
	{
		printf("%d-->",head->data);
		head = head->next;
	}
	printf("NULL");
	printf("\nExit:%s\n",__FUNCTION__);	
}
int search(NODE_T *head, const int data)
{
}
void freeLL(NODE_T *head)
{
	printf("\nEntry:%s\n",__FUNCTION__);
	while(head)
	{
		head = Delete(head,1);
	}
	printf("\nExit:%s\n",__FUNCTION__);		
}

