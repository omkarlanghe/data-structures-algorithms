#include<stdio.h>
#include<stdlib.h>

void partition(int [], int [], int , int);
void merge(int [], int [], int , int , int);

int main()
{
	int *arr;
	int *result;
	int i,size;
	
	printf("\n\t MERGE SORT\n\n");
	printf("Enter the total number of elements:\n");
	scanf("%d",&size);
	
	arr = malloc(size*sizeof(int));
	result = malloc(size*sizeof(int));
	
	for(i=0 ; i<size ; i++)
	{
		printf("Enter %d the elements : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	//parameterized return
	partition(arr, result, 0, size-1);
	printf("\n\t------MERGE SORTED ELEMENTS------\n\n");
	for(i=0 ; i<size ; i++)
	{
		printf("%d ",result[i]);
	}
	
	free(arr);
	free(result);
	return 0;
}

void partition(int arr[], int result[], int min, int max)
{
	int mid;
	if(min < max)
	{
		mid = (min + max)/2;
		partition(arr, result, min, mid);
		partition(arr, result, mid+1, max);
		merge(arr, result, min, mid, max);
	}
}

void merge(int arr[], int result[], int min, int mid, int max)
{
	int i,j,k;
	i = min;
	j = mid+1;
	int m = 0;
	
	while(i <= mid && j <= max)
	{
		if(arr[i] < arr[j])
		{
			result[m] = arr[i];
			i++;
		}
		else
		{
			result[m] = arr[j];
			j++;
		}
		m++;
	}
	
	while(i <= mid)
	{
		result[m] = arr[i];
		i++;
		
		m++;
	}
	
	while(j <= max)
	{
		result[m] = arr[j];
		j++;
		m++;
	}
	
	for(i = min,j = 0 ; i<=max ; i++,j++)
	{
		arr[i] = result[j];
	}
}
