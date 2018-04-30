#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

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
		st->stack=NULL;
	}
}

int main()
{
	//creating first stack of name c_stack[10];
	STACK c_stack;
	init(&c_stack,10); //Dynamic memory allocation by calling init funtion from stack.h

	push(&c_stack,1);
	push(&c_stack,2);
	push(&c_stack,6);
	printf("\n popped: %d",pop(&c_stack));
	printf("\n peep Element %d",peep(&c_stack));
	printf("\n popped Element %d",pop(&c_stack));
	printf("\n popped Element %d",pop(&c_stack));
	push(&c_stack,1);
	push(&c_stack,2);
	push(&c_stack,3);
	push(&c_stack,4);
	push(&c_stack,5);
	push(&c_stack,6);
	push(&c_stack,7);
	printf("\n peep Element %d",peep(&c_stack));
	if(isEmpty(&c_stack))
	{
		printf("\n stack is empty\n");
	}
	else if(isFull(&c_stack))
	{
		printf("\n stack is full\n");
	}
	else
	{
		printf("\n stack contains data\n");
	}
	
	
	//creating second stack of name python_stack[10];
	STACK python_stack;
	init(&python_stack,10); //Dynamic memory allocation by calling init funtion from stack.h
	
	push(&python_stack,4);
	push(&python_stack,5);
	push(&python_stack,8);
	printf("\n popped: %d",pop(&python_stack));
	printf("\n peep Element %d",peep(&python_stack));
	printf("\n popped: %d",pop(&python_stack));
	printf("\n popped: %d",pop(&python_stack));
	if(isEmpty(&python_stack))
	{
		printf("\n stack is empty\n");
	}
	else if(isFull(&python_stack))
	{
		printf("\n stack is full\n");
	}
	else
	{
		printf("\n stack contains data\n");
	}
		
	Deinit(&c_stack); //free the memory by calling Deinit funtion from stack.h
	Deinit(&python_stack); //free the memory by calling Deinit funion from stack.h
	
	return 0;
}

