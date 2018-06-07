#include<stdio.h>
#include<stdlib.h>

void selectionsort(int *array, int size);

void selectionsort(int *array, int size)
{
	for(int i=0 ; i<size ; i++)
	{
		for(int j=i+1 ; j<size ; j++)
		{
			if(array[i] > array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main()
{
	int *array,size;
	
	printf("Enter the size of an array:\n");
	scanf("%d",&size);
	
	array = (int *)malloc(size*sizeof(int));
	
	printf("Enter the elements in an array:\n");
	for(int i=0 ; i<size ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("sorted array using selection sort:\n");
	selectionsort(array,size);
	
	for(int i=0 ; i<size ; i++)
	{
		printf("%d\n",array[i]);
	}
	
	free(array);
	return 0;
}
