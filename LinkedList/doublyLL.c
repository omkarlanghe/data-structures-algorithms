#include "doubly.h"
#include<stdio.h>
#include<stdlib.h>

NODE_T *create(const int noOfNodes)
{
	printf("\n Entry:%s\n",__FUNCTION__);
	struct NODE_T *head = NULL;
	
	for(int i=0 ; i<noOfNodes ; i++)
	{
		int data;
		printf("Enter the data to be added in linked list:\n");
		scanf("%d",&data);
	}
	printf("\nExit:%s\n",__FUNCTION__);
	
	return head;
}

void insert(NODE_T **dhead, const int position, const int data)
{
	printf("\n Entry:%s\n",__FUNCTION__);
	if(position < 1 || dhead == NULL)
	{
		printf("you cannot enter the invalid position,cannot add..");
	}
	else
	{
	//create a new node with the data to be inserted..
		NODE_T * temp = (NODE_T *)malloc(sizeof(NODE_T));
		temp->prev = NULL;
		temp->data = data;
		temp->next = NULL;
		
		if(position == 1)
		{
			if(*dhead != NULL)
			{
				temp->next = *dhead;
				temp->next->prev = temp
			}
			*dhead = temp;
		}
		else if(*dhead != NULL)//this handles other than first, all positions
		{
			NODE_T *traverse = *dhead;
			int pos = position;
			
			//the check of traverse->next makes sure that if user enters position beyond the length of linked list then we stop at last node and insert the new node 			after that. It also helps in preventing the segmentation fault which will occur due to moving traverse beyond last node.
			
			while(traverse->next && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			temp->prev = traverse;
			temp->next = traverse->next;
			traverse->next = temp;
			
			//when we are inserting at last position, temp->next is NULL & hence accessing prev of it results into segmentation fault.
			
			if(temp->next)
			{
				temp->next->prev = temp;
			}
			else
			{
			//control will enter in this else, if position is other than 1 and head is NULL i.e.  there is no nodes in linked list. Hence temp should be freed as it 			is not going to be added in linked list.
			
				printf("You have entered invalid position, cannot add...");
				free(temp);
			} 
		}
		
	}
	printf("\nExit:%s\n",__FUNCTION__);
}

void _delete(NODE_T **dhead, const int position)
{
	printf("\n Entry:%s\n",__FUNCTION__);
	
	if(dhead && *dhead)
	{
		NODE_T *deleteNode = NULL;
		if(position == 1)
		{
			deleteNode = *dhead;
			*dhead = (*dhead)->next;
			deleteNode->next = NULL;
			
			//second node prev is currently pointing to first node but now as second node is becoming first node set its prev to NULL.
			if(*dhead)
			{
				(*dhead)->next = NULL;
			}
		}
		else
		{
			NODE_T *traverse = *dhead;
			int pos = position;
			
			while(traverse->next && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			if(traverse == NULL)
			{
				printf("You have entered incorrect position to delete, cannot add..");
			}
			else
			{
				deleteNode = traverse->next;
				traverse->next = deleteNode->next;
				
				//this check is to ensure that if we are deleting last node than there is no next node to it & we dont end up in segmentation fault by trying 					to access its previous.
				if(deleteNode->next)
				{
					deleteNode->next->prev = traverse;
				}
				deleteNode->next = NULL;
				deleteNode->prev = NULL;
			}
		}
		if(deleteNode)
		{
			free(deleteNode);
		}
	}
	printf("\n Exit:%s\n",__FUNCTION__);
}

void display(NODE_T *head)
{	
	printf("\n Entry:%s\n",__FUNCTION__);
	
	while(head)
	{
		printf("%d-->",head->data);
		head  = head->next;
	}
	printf("NULL");
	printf("\n Exit:%s\n",__FUNCTION__);
}

void reverseDisplay(NODE_T *head)
{
	if(head)
	{
		NODE_T *traverse = head;
		while(traverse->next)
		{
			traverse = traverse->next
		}
		while(traverse)
		{
			printf("%d-->",traverse-data);
			traverse = traverse->prev;
		}
	}
}

void freeLL(NODE_T **head)
{
	printf("\n Entry:%s\n",__FUNCTION__);
	while(head && *head)
	{
		delete(head,1);
	}
	printf("\n Exit:%s\n",__FUNCTION__);	
}
