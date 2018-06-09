#include<stdio.h>
#include<stdlib.h>

void insertionsort(int *array, int size);
void display(int *array, int size);

void insertionsort(int *array, int size)
{
	int key,i,j;
	if(array)
	{
		for(i=0 ; i<size ; i++)
		{
			key = array[i];
			
			for(j=i-1 ; j>=0 && array[j]>key ; j--)
			{
				array[j+1] = array[j];
			}
			
			array[j+1] = key;
		}
	}
}

void display(int *array, int size)
{
	printf("Elements after sort:\n");
	insertionsort(array,size);
	for(int i=0 ; i<size ; i++)
	{
		printf("%d ",array[i]);
	}
}

int main()
{
	int *array, size;
	
	printf("Enter the size of the array:\n");
	scanf("%d",&size);
	
	array = (int *)malloc(size*sizeof(int));
	
	printf("Enter the elements in an array:\n");
	for(int i=0 ; i<size ;i++)
	{
		scanf("%d",&array[i]);
	}
	
	display(array,size);
	free(array);
	
	return 0;
	
}
