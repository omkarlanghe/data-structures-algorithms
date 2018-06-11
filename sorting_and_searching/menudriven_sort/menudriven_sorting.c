#include "sort.h"
#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *array, int size)
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

void bubbleSort(int *array, int size)
{	
	for(int i=0 ; i<size ; i++)
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

void insertionSort(int *array, int size)
{
	if(array)
	{
		int key;
		int i,j;
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

void partition(int array[], int result[], int min, int max)
{
	int mid;
	if(min < max)
	{
		mid = (min + max)/2;
		partition(array, result, min, mid);
		partition(array, result, mid+1, max);
		merge(array, result, min, mid, max);
	}
}

void merge(int array[], int result[], int min, int mid, int max)
{
	int i,j,k;
	i = min;
	j = mid+1;
	int m = 0;
	
	while( i<=mid && j<=max)
	{
		if(array[i] < array[j])
		{	
			result[m] = array[i];
			i++;
		}
		else
		{
			result[m] = array[j];
			j++;
		}
		m++;
	}
	
	while( i <= mid)
	{
		result[m] = array[i];
		i++;
		m++;
	}
	
	while( j <= max)
	{
		result[m] = array[j];
		j++;
		m++;
	}
	
	for(i=min,j=0 ; i<=max ; i++,j++)
	{
		array[i] = result[j];
	}
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


void simulateOperation()
{
	int choice,size,*array,*result;
	
	printf("WELCOME TO SORTING OPERTAION_MENU-DRIVEN");
	printf("\n1.Selection Sort");
	printf("\n2.Bubble Sort");
	printf("\n3.Insertion Sort");
	printf("\n4.Merge Sort");
	printf("\n5.Quick Sort");
	printf("\n6.Exit");
	printf("\n");
	printf("\nEnter Your choice :");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("WELCOME TO SELECTION SORT:\n");
			printf("Enter the size of an array\n");
			scanf("%d",&size);
			
			array = (int *)malloc(size*sizeof(int));
			
			printf("Enter the elements in an array\n");
			for(int i=0 ; i<size ; i++)
			{
				scanf("%d",&array[i]);
			}
			
			printf("Sorted array in selection sort:\n");
			selectionSort(array,size);
			for(int i=0 ; i<size ; i++)
			{
				printf("%d ",array[i]);
			}
			printf("\n");
			free(array);
			break;	
			
		case 2:
			printf("WELCOME TO BUBBLE SORT:\n");
			printf("Enter the size of an array\n");
			scanf("%d",&size);
			
			array = (int *)malloc(size*sizeof(int));
			
			printf("Enter the elements in an array\n");
			for(int i=0 ; i<size ; i++)
			{
				scanf("%d",&array[i]);
			}
			
			printf("Sorted array in bubble sort:\n");
			bubbleSort(array,size);
			for(int i=0 ; i<size ; i++)
			{
				printf("%d ",array[i]);
			}
			printf("\n");
			free(array);
			break;
		
		case 3:
			printf("WELCOME TO INSERTION SORT:\n");
			printf("Enter the size of an array\n");
			scanf("%d",&size);
			
			array = (int *)malloc(size*sizeof(int));
			
			printf("Enter the elements in an array\n");
			for(int i=0 ; i<size ; i++)
			{
				scanf("%d",&array[i]);	
			}
			
			printf("Sorted array in insertion sort:\n");
			insertionSort(array,size);
			for(int i=0 ; i<size ; i++)
			{
				printf("%d ",array[i]);
			}
			printf("\n");
			free(array);
			break;
		
		case 4:
			printf("WELCOME TO MERGE SORT:\n");
			printf("Enter the number of elements:\n");
			scanf("%d",&size);
			
			array = malloc(size*sizeof(int));
			result = malloc(size*sizeof(int));
			
			for(int i=0 ; i<size ; i++)
			{
				printf("Enter %d elements:\n",i+1);
				scanf("%d",&array[i]);
			}
			
			partition(array, result, 0, size-1);
			
			printf("MERGE SORTED ELEMENTS:\n\n");
			for(int i=0 ; i<size ; i++)
			{
				printf("%d ",result[i]);
			}
			printf("\n");
			
			free(array);
			free(result);
			break;
			
			
		case 5:
			printf("WELCOME TO QUICK SORT:\n");
			printf("Enter the size of the array:\n");
			scanf("%d",&size);
			
			array = malloc(size*sizeof(int));
			
			printf("Enter the elements in an array:\n");
			for(int i=0 ; i<size ; i++)
			{
				scanf("%d",&array[i]);
			}
			
			quicksort(array,0,size-1);
			
			printf("QUICK SORT ELEMENTS:\n\n");
			for(int i=0 ; i<size ; i++)
			{
				printf("%d ",array[i]);
			}
			printf("\n");
			
			free(array);
			break;
		
		case 6:
			exit(0);
			break;
		
		default:
			printf("sorry you have entered wrong choice...\n");	
			
	}
}
int main()
{	
	simulateOperation();
	return 0;
}
