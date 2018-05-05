#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "stack.h"

void EvaluatePostfix();
void push(STACK *st, const int data);
int pop(STACK *st);
void init(STACK *st, int size);
void Deinit(STACK *st);

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

void EvaluatePostfix()
{
	char expr[100];
	printf("Enter the postfix expression:\n");
	
	//this results into reading upto '\n'
	scanf("%[^\n]s",expr);
	printf("Expression is %s\n",expr);
	
	int i = 0;
	int result = 0;
	
	STACK p_stack; //creating stack
	init(&p_stack,10); //memory allocation
	
	char *token = strtok(expr," ");
	printf("Token=%s\n",token);
	
	int no;
	
	while(token)
	{
		if(isdigit(token[0]))
		{
			sscanf(token,"%d",&no);
			printf("no=%d\n",no);
			push(&p_stack,no);
		}
		else
		{
			switch(token[0])
			{
				case '+':
					result = pop(&p_stack) + pop(&p_stack);
				
					printf("\nAddition is %d\n",result);
					push(&p_stack,result);
					break;
				
				case '*':
					result = pop(&p_stack) * pop(&p_stack);
				
					printf("\nMultiplication is %d\n",result);
					push(&p_stack,result);
					break;
				
				case '-':
					{
					int no2 = pop(&p_stack);
					int no1 = pop(&p_stack);
					
					result = no1 - no2;
					
					printf("\nSubtraction is %d\n",result);
					
					push(&p_stack,result);
					}
					break;
				
				case '/':
					{
					int no2 = pop(&p_stack);
					int no1 = pop(&p_stack);
					
					result = no1/no2;
					
					printf("\nDivision is %d\n",result);
					
					push(&p_stack,result);					
					}
					break;
			}
		}
		token = strtok(NULL," ");
		printf("Token=%s\n",token);
	}
	printf("Final Result = %d\n",pop(&p_stack));
	Deinit(&p_stack); //free memory
}

int main()
{
	EvaluatePostfix();
	return 0;
}

