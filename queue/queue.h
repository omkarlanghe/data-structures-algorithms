#ifndef QUEUE_H
#define QUEUE_H

typedef struct
{
	int iSize;
	
	//this is for operating from left side
	int leftFront;
	int leftRear;
	
	//this is for operating from right side
	int rightFront;
	int rightRear;
	int *queue;
}QUEUE_T;

	void initQ(QUEUE_T *const q, const int size);
	void DeinitQ(QUEUE_T *const q);
	void EnqueueRight(QUEUE_T *const q,const int data);
	int DequeueRight(QUEUE_T *const q);
	void EnqueueLeft(QUEUE_T *const q,const int data);
	int DequeueLeft(QUEUE_T *const q);
	int isQFull(const QUEUE_T *const q);
	int isRightQEmpty(const QUEUE_T *const q);
	int isLeftQEmpty(const QUEUE_T *const q);
	void DisplayQ(const QUEUE_T *const q);

#endif
