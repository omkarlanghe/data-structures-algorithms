#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void SimulateOperation();
void stack_op();

void SimulateOperation()
{
	int choice = 0;
	printf("##### WELCOME TO MENUDRIVEN PROGRAM FOR DATA STRUCTURES #####\n");
	printf("1.Stack\n2.Queue\n3.Linked List\n4.Sorting and Searching\n5.Trees\n6.Graphs\n");
	printf("#############################################################\n");
	printf("Enter your choice:\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Welcome to Stack. Lets Push-Pop...!!");
			stack_op();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		
	}
}

void stack_op()
{
	STACK c_stack;
	c_stack.stack = NULL; //using (.) we go inside STACK and made *stack = NULL
	int choice = 0, size = 0, data =0;

	do
	{
		printf("\n1.Initialization\n2.De-Initialization\n3.Push\n4.Pop\n5.Display\n6.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the size of the stack:\n");
				scanf("%d", &size);
				init(&c_stack, size);
				printf("stack initialized\n");
				break;
			case 2:
				deinit(&c_stack);
				printf("stack de-initialized\n");
				break;
			case 3:
				if(!isFull(&c_stack))
				{
					printf("Enter the elements to push on to the stack:\n");
					scanf("%d",&data);
					push(&c_stack, data);
				}
				else
				{
					printf("stack is full, cannot push\n");
				}
				break;
			case 4:
				if(!isEmpty(&c_stack))
					printf("Elements popped : %d\n", pop(&c_stack));
				break;
			case 5:
				Display(&c_stack);
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("you have entered wrong choice:\n");
		}
	}while(choice != 6);
}

void init(STACK *st, int size)
{
	if(st)
		st->size = size;
		(*st).stack = (int *)malloc(size*sizeof(int));
		st->top = -1;
}

void deinit(STACK *st)
{
	if(st && st->stack)
	{
		free(st->stack);
		st->stack = NULL;
	}
}

void push(STACK *st, const int data)
{
	if(st && st->stack)
		st->stack[++st->top] = data;
}

int pop(STACK *st)
{
	int temp = -1;
	if(st && st->stack)
		temp = st->stack[st->top];
		st->top--;
	return(temp);
}

int peep(STACK *st)
{
	int temp = -1;
	if(st && st->stack)
		temp = st->stack[st->top];
	return(temp);
}

int isEmpty(STACK *st)
{
	if(st)
		return st->top == -1;
	return(-1);
}

int isFull(STACK *st)
{
	if(st)
		return st->top == st->size-1;
	return(-1);
}

void Display(STACK *st)
{
	while(st->top != -1)
	{
		printf("stack[top] -> %d\n", st->stack[st->top]);
		st->top--;

	}
}

int main()
{
	SimulateOperation();
	return(0);
}
