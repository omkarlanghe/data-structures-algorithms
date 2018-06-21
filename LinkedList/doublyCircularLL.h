#ifndef DOUBLY_CIRCULAR_H
#define DOUBLY_CIRCULAR_H

typedef struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
	
}NODE_T;

NODE_T *create(const int noOfnodes);
void insert(NODE_T **head, const int position, const int data);
void _delete(NODE_T **head, const int position);
void display(NODE_T *head);
int search(NODE_T *head, const int data);
void reverse_display(NODE_T *head);
NODE_T *midpoint(NODE_T *head);
void freeLL(NODE_T **head);

#endif
