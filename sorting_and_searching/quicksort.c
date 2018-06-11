#include<stdio.h>
#include<stdlib.h>
void quicksort(int *array, int lb, int ub);
int main()
{	
	int *array;
	int size;
	
	printf("Enter the size of the array:\n");
	scanf("%d",&size);
	
	array = malloc(size*sizeof(int));
	
	printf("Enter the elements in an array:\n");
	for(int i=0 ; i<size; i++)
	{
		scanf("%d",&array[i]);
	}
	
	quicksort(array,0,size-1);
	
	printf("Sorted elements in quick sort:\n\n");
	for(int i=0; i<size ; i++)
	{
		printf("%d ",array[i]);
	}
	
	free(array);
	return 0;
}

void quicksort(int *array, int lb, int ub)
{
	int pivot, down, temp, up;
	
	if(lb < ub)
	{
		pivot = lb;
		up = lb;
		down = ub;
		
		while(up < down)
		{
			while(array[up] <= array[pivot] && up < ub)
			{
				up++;
			}
			while(array[down] > array[pivot])
			{
				down--;
			}
			
			if(up < down)
			{
				temp = array[up];
				array[up] = array[down];
				array[down] = temp;
			}
		}
		
		if( up >= down)
		{
			temp = array[pivot];
			array[pivot] = array[down];
			array[down] = temp;
		}
		
		quicksort(array, lb, down-1);
		quicksort(array, down+1, ub);
		
	}
}

