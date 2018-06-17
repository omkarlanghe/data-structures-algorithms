#include<stdio.h>
#include<stdlib.h>
void Indegree(int **graph, int noOfvertices);
void Outdegree(int **graph, int noOfvertices);

void simulateGraph()
{
	int **graph;
	int noOfvertices;
	int i,j;
	
	printf("Enter number of vertices in graph:-\n");
	scanf("%d",&noOfvertices);
	
	graph = (int **)malloc(noOfvertices*sizeof(int*));
	
	for(i=0 ; i<noOfvertices ; i++)
	{
		graph[i] = (int *)malloc(noOfvertices*sizeof(int));
	}
	
	//accept graph
	for(i=0 ; i<noOfvertices ; i++)
	{
		for(j=0 ; j<noOfvertices ; j++)
		{
			printf("\n Enter 1 if there is an edge between (v %d, v %d) o.w O:-",i,j);
			scanf("%d",&graph[i][j]);
		}	
	}
	
	//calculate indegree of vertices
	Indegree(graph, noOfvertices);
	//calculate outdegree of vertices
	Outdegree(graph, noOfvertices);
	
	for(i=0 ; i<noOfvertices ; i++)
	{
		free(graph[i]);
	}	
	free(graph);
}

void Indegree(int **graph, int noOfvertices)
{
	int i;
	for(i=0 ; i<noOfvertices ; i++)
	{
		int in_degree = 0, j;
		
		for(j=0 ; j<noOfvertices ; j++)
		{
			if(graph[j][i])
			{
				in_degree++;
			}
			printf("\n In-Degree of v %d is %d",i+1,in_degree);
		}
	}
}

void Outdegree(int **graph, int noOfvertices)
{
	int i;
	for(i=0 ; i<noOfvertices ; i++)
	{
		int out_degree = 0, j;
		
		for(j=0 ; j<noOfvertices ; j++)
		{
			if(graph[i][j])
			{
				out_degree++;
			}
		}
		printf("\n Out-Degree of v %d is %d",i+1,out_degree);
	}
}

int main()
{
	simulateGraph();
	return 0;
}
