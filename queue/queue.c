#include "queue.h"
#include<stdio.h>
#include<stdlib.h>

void initQ(QUEUE_T *const q, const int size)
{
	if(q)
	{
		q->queue = (int*)malloc(size*sizeof(int));
		q->iSize = size;
		q->leftFront = q->leftRear = -1;
		q->rightFront = q->rightRear = size;	
	}
}
void DeinitQ(QUEUE_T *const q)
{
	if(q && q->queue)
	{
		free(q->queue);
		q->queue = NULL;
		q->iSize = 0;
		q->leftFront = q->leftRear = -1;
	}
}
void EnqueueRight(QUEUE_T *const q,const int data)
{
	if(q && q->queue)
	{
		q->queue[--q->rightRear] = data;
	}
	else
	{
		printf("\nSomething wrong...");
	}
}
int DequeueRight(QUEUE_T *const q)
{
	int data = -1;
	if(q && q->queue && !isRightQEmpty(q))
	{
		data = q->queue[--q->rightFront];
	}
	return data;
}
void EnqueueLeft(QUEUE_T *const q,const int data)
{
	if(q && q->queue)
	{
		q->queue[++q->leftRear] = data;
	}
	else
	{
		printf("\nSomething wrong...");
	}
}
int DequeueLeft(QUEUE_T *const q)
{
	int data = -1;
	if(q && q->queue && !isLeftQEmpty(q))
	{
		data = q->queue[++q->leftFront];
	}
	return data;
}
int isQFull(const QUEUE_T *const q)
{
	if(q && q->queue)
	{
		return q->leftRear+1 == q->rightRear;
	}
	return -1;
}
int isRightQEmpty(const QUEUE_T *const q)
{
	if(q && q->queue)
	{
		return q->rightRear == q->rightFront;
	}
	return -1;
}
int isLeftQEmpty(const QUEUE_T *const q)
{
	if(q && q->queue)
	{
		return q->leftRear == q->leftFront;
	}
	return -1;
}
void DisplayQ(const QUEUE_T *const q)
{
	if(q && q->queue)
	{
		for(int i = 0; i < q->iSize; i++)
		{
			printf("%d:",q->queue[i]);
		}
		printf("\n");
	}
}

int main()
{
	QUEUE_T q;
	initQ(&q,10);
	
	EnqueueRight(&q,1);
	EnqueueRight(&q,2);
	EnqueueRight(&q,3);
	printf("\nDisplay Queue:");
	
	DisplayQ(&q);
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	
	EnqueueRight(&q,1);
	EnqueueRight(&q,2);
	EnqueueRight(&q,3);
	printf("\nDisplay Queue:");

	DisplayQ(&q);
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	printf("\n%d:",DequeueRight(&q));
	
	DeinitQ(&q);
	return 0;	
}

