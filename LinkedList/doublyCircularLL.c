#include "doublyCircularLL.h"
#include<stdio.h>
#include<stdlib.h>


NODE_T *create(const int noOfnodes)
{
	struct NODE_T *head = NULL;
	
	for(int i=0 ; i<noOfnodes ; i++)
	{
		int data;
		printf("Enter the data to be added in a node:\n");
		scanf("%d",&data);
	}
	return head;
}
void insert(NODE_T **head, const int position, const int data)
{
	if(position<1 || dhead == NULL)
	{
		printf("You have entered invalid position, cannot add..");
	}
	else
	{
		//create a new node with the data to be inserted
		NODE_T *temp = (NODE_T *)malloc(sizeof(NODE_T));
		
		temp->prev = NULL;
		temp->data = data;
		temp->next = NULL;
		
		if(position == 1)
		{
			if(*dhead != NULL)
			{
				temp->next = *dhead;
				temp->prev = (*dhead)->prev;
				(*dhead)->prev = temp;
				temp->prev->next = temp;	
			}
			else
			{
				temp->next = temp;
				temp->prev = temp;
			}
			*dhead = temp;
		}
		else if(*dhead != NULL)
		{
			NODE_T *traverse = *dhead;
			int pos = position;
			
			while(traverse->next != *dhead && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			//same as doubly..
			temp->prev = traverse;
			temp->next = traverse->next;
			//additional addition in doubly circular..
			traverse->next = temp;
			traverse->next->prev = temp;
			
		}
	}
}

void _delete(NODE_T **head, const int position)
{
	if(dhead && *dhead)
	{
		NODE_T *deleteNode = NULL;
		
		if(position == 1)
		{
			deleteNode = *dhead;
			
			if(deleteNode->next != *dhead)
			{
				*dhead = (*dhead)->next;
				(*dhead)->prev = deleteNode->prev;
				deleteNode->prev->next = *dhead;
			}
			else
			{
				*dhead = NULL;
			}
			deleteNode->next = NULL;
			deleteNode->prev = NULL;
		}
		else
		{
			NODE_T *traverse = *dhead;
			int pos = position;
			
			while(traverse->next != *dhead && pos-2)
			{
				traverse = traverse->next;
				pos--;
			}
			
			if(traverse->next == *dhead)
			{
				printf("You entered incorrect position to delete, cannot delete..");
			}
			else
			{
				//same as doubly
				deleteNode = traverse->next;
				traverse->next = deleteNode->next;
				//additional addition in doubly circular..
				deleteNode->next->prev = traverse;
				deleteNode->next = NULL;
				deleteNode->prev = NULL;
			}
		}
		
		if(deleteNode)
		{
			free(deleteNode);
		}
	}
}

void display(NODE_T *head)
{
	while(head)
	{
		printf("%d-->",head->data);
		head = head->next;
	}
	printf("\n");
}
int search(NODE_T *head, const int data)
{
}

void reverse_display(NODE_T *head)
{
	if(head)
	{
		NODE_T *traverse = head->prev;
		NODE_T *reverse_head = traverse;
		
		while(traverse != reverse_head)
		{
			printf("%d-->",traverse->data);
			traverse = traverse->prev;
		}
	}
}

NODE_T *midpoint(NODE_T *head)
{
	NODE_T *traverse_step1 = head;
	
	if(head)
	{
		NODE_T *traverse_step2 = head->next;
		
		if(traverse_step1 && traverse_step2)
		{
			while(traverse_step1 && traverse_step2->next)
			{
				traverse_step1 = traverse_step1->next;
				traverse_step2 = traverse_step2->next->next;
			}
		}
	}
}

void freeLL(NODE_T **head)
{
	while(head && *head)
	{
		_delete(head,1);
	}
}

