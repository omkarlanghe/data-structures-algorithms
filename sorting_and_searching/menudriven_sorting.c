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

void simulateOperation()
{
	int choice,size,*array;
	
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
		case 5:
		
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
