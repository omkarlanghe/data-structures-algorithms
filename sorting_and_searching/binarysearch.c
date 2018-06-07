#include<stdio.h>
#include<stdlib.h>

int binary_search(int * array, int ele, int lb, int ub);

int binary_search(int * array, int ele, int lb, int ub)
{
	int retVal = 0;
	
	if(lb < ub && array)
	{
		while(lb <= ub)
		{
			int mid = (lb+ub)/2;
			printf("\nmid = %d",mid);
			
			if(array[mid] == ele)
			{
				retVal = 1;
				break;
			}
			else if(array[mid] > ele)
			{
				ub = mid-1;
			}
			else
			{
				lb = mid+1;
			}
			printf("\n%d%d",lb,ub);
		}
	}
	return retVal;
}

int main()
{
	int *array = NULL;
	int size = 0;
	int ele;
	
	printf("\nEnter the size of an array:");
	scanf("%d",&size);
	
	array = (int*)malloc(size * sizeof(int));
	
	printf("\nEnter the elements in array:");
	for(int i=0; i<size; i++)
	{
		scanf("%d",&array[i]);	
	}
	
	printf("\nEnter the element to be searched:");
	scanf("%d",&ele);
	
	if(binary_search(array,ele,0,size))
	{
		printf("\n %dFound in array\n",ele);
	}
	else
	{
		printf("\n %dNot Found in array\n",ele);
	}
	free(array);
}
