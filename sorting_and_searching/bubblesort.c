#include<stdio.h>
#include<stdlib.h>
void bubblesort(int *array, int size);
void bubblesort(int *array, int size)
{
	for(int i=0 ; i<size; i++)
	{
		for(int j=0 ; j<size-i-1 ; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}
int main()
{
	int *array,size;

	printf("Enter the size of the array:\n");
	scanf("%d",&size);
	
	array = (int *)malloc(size*sizeof(int));
	
	printf("Enter the elements in the array:\n");
	for(int i=0 ; i<size ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("array sorted in Bubble sort is:\n");
	
	bubblesort(array,size);
	for(int i=0 ; i<size ; i++)
	{
		printf("%d\n",array[i]);
	}
	
	free(array);
	return 0;
}
