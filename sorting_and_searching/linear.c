#include<stdio.h>
#include<stdlib.h>

int linear_search(int *array, int ele, const int size)
{
	int retVal = 0;
	for(int i=0 ; i<size ; i++)
	{
		if(array[i] == ele)
		{
			retVal = 1;
			break;
		}
		
	}
	return retVal;
}

int main()
{
	int *array,size,ele;
	
	printf("Enter the size of an array:\n");
	scanf("%d",&size);
	
	array = (int *)malloc(size*sizeof(int));
	
	printf("Enter the elements in an array:\n");
	for(int i=0 ; i<size ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("Enter the element to be searched in an array:\n");
	scanf("%d",&ele);
	
	int result = linear_search(array,ele,size);
	
	if(result == 1)
	{
		printf("%d is the element found in an array using linear search:\n",ele);
	}
	else
	{
		printf("%d element not found in array:\n",ele);
	}
	
	free(array);
	return 0;
}	
