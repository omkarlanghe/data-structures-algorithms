#ifndef SINGLY_H
#define SINGLY_H

typedef struct NODE{
	int data;
	struct Node *next;
}NODE_T;

NODE_T *Create(const int noOfNodes);
NODE_T *Insert(NODE_T *head, const int position, const int data);
NODE_T *Delete(NODE_T *head, const int position);
NODE_T *Display(NODE_T *head);
int search(NODE_T *head, const int data);
void freeLL(NODE_T *head);

#endif

