#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

void init(STACK *st, int size);
void Deinit(STACK *st);
void push(STACK *st, const int data);
int pop(STACK *st);
int peep(STACK *st);
int isEmpty(STACK *st);
int isFull(STACK *st);
void Display(STACK *st);

void init(STACK *st, int size)
{
	if(st)
	{
		st->size = size;
		
		(*st).stack = (int *)malloc(size*sizeof(int));
		st->top = -1;
	}
}

void Deinit(STACK *st)
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
	{
		st->stack[++st->top] = data;
	}
}

int pop(STACK *st)
{
	int temp = -1;
	if(st && st->stack)
	{
		temp = st->stack[st->top];
		st->top--;
	}
	return temp;
}

int peep(STACK *st)
{
	int temp = -1;
	if(st && st->stack)
	{
		temp = st->stack[st->top];
	}
	return temp;
}

int isEmpty(STACK *st)
{
	if(st)
	{
		return st->top == -1;
	}
	return -1;
}

int isFull(STACK *st)
{
	if(st)
	{
		return st->top == st->size-1; 
	}
	return -1;
}

void Display(STACK *st)
{
	while(st->top!=-1)
	{
		printf("%d\n",st->stack[st->top]);
		st->top--;
	}
}


int main()
{
	STACK c_stack;
	c_stack.stack = NULL;
	int i,ch,size,data;
	do
	{
		printf("\n**STACK OPERATIONS**");
		printf("\n1.Initialization\n2.De-initialization\n3.Push\n4.Pop\n5.Display\n6.Exit");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the size of stack:\n");
				scanf("%d",&size);
				init(&c_stack,size);
				printf("STACK INITIALIZED\n");
				break;
			
			case 2:
				Deinit(&c_stack);
				printf("STACK DEINITIALIZED\n");
				break;
			
			case 3:
				if(!isFull(&c_stack))
				{
					printf("Enter the elements to push onto the stack:\n");
					scanf("%d",&data);
					push(&c_stack,data);
				}
				else
				{
					printf("Stack is full\n");
				}
				break;
			
			case 4:
				if(!isEmpty(&c_stack))
				{
					printf("Elements popped :%d\n",pop(&c_stack));
				}
			case 5:
				Display(&c_stack);
				break;
				
			case 6:
				exit(0);
				break;
			default:
				printf("You have entered wrong choice:\n");
		}
	}
	while(ch!=6);
	return 0;
}
