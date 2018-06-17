#include "graph.h"
#include "stack.h"
#include "queue.h"
#include<stdio.h>
#include<stdlib.h>

int **AllocateGraph(int noOfvertices)
{
	int **graph = NULL;
	
	graph = (int **)malloc(noOfvertices*sizeof(int *));
	
	for(int i=0 ; i<noOfvertices ; i++)
	{
		graph[i] = (int *)malloc(noOfvertices*sizeof(int));
	}
	return graph;
}

int **Accept(int **graph, int noOfvertices)
{
	if(NULL == graph)
	{
		graph = AllocateGraph(noOfvertices);
		
		if(NULL == graph)
		{
			return NULL;
		}
	}
	
	for(int i=0 ; i<noOfvertices ; i++)
	{
		for(int j=0 ; j<noOfvertices ; j++)
		{
			if(i != j)
			{
				printf("\n Is there an edge between v %d , v %d ?(Enter 1 if yes,o.w O):-",i+1,j+1);
				scanf("%d",&graph[i][j]);
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}
	return graph;
}

void Display(int **graph, int noOfvertices)
{
	if(NULL != graph)
	{
		for(int i=0 ; i<noOfvertices ; i++)
		{
			for(int j=0 ; j<noOfvertices ; j++)
			{
				printf("%d\t",graph[i][j]);
			}
			printf("\n");
		}
	}
}

int Indegree(int **graph, int vertex, int noOfvertices)
{
	int in_degreeCount = 0;
	
	if(graph)
	{
		for(int i=0 ; i<noOfvertices ; i++)
		{
			if(graph[i][vertex-1])
			{
				in_degreeCount++;
			}
		}
	}
	return in_degreeCount;
}

int Outdegree(int **graph, int vertex, int noOfvertices)
{
	int out_degreeCount = 0;
	
	if(graph)
	{
		for(int i=0 ; i<noOfvertices ; i++)
		{
			if(graph[vertex-1][i])
			{
				out_degreeCount++;
			}
		}
	}
	return out_degreeCount;
}

void BFS(int **graph, int noOfvertices)
{
	Queue q;
	InitQueue(&q, noOfvertices);
	
	int *visited = malloc(noOfvertices*sizeof(int)); //create visited array
	int count = 1;
	
	memset(visited, 0 ,noOfvertices*sizeof(int));
	
	int startingvertex;
	
	printf("\n**********************BFS**********************\n");
	printf("\n Enter starting vertex:-");
	scanf("%d",&startingvertex);
	
	printf("\nvertex visited: %d",startingvertex);
	visited[startingvertex-1] = 1;
	
	EnQueue(&q,startingvertex-1);
	
	while(!IsQueueEmpty(&q) && count != noOfvertices)
	{
		int vertex = DeQueue(&q);
		for(int i=0 ; i<noOfvertices ; i++)
		{
			if(graph[vertex][i] && visited[i] == 0)
			{
				printf("\n vertex visited: %d",i+1);
				
				visited[i] = 1;
				EnQueue(&q,i);
				count++;
			}
		}
	}
	
	printf("\n count = %d QueueEmpty = %d",count,IsQueueEmpty(&q));
	free(visited);
	DeInitQueue(&q);
	
}
void DFS(int **graph, int noOfvertices)
{
	printf("\n******************DFS***************\n");
	
	STACK_T st;
	InitStack(&st, noOfvertices+1);
	
	int *visited = malloc(noOfvertices*sizeof(int));
	memset(visited, 0, noOfvertices*sizeof(int));
	int startingvertex;
	
	printf("\n Enter the starting vertex:-");
	scanf("%d",&startingvertex);
	
	visited[startingvertex-1];
	
	Push(&st,startingvertex-1);
	
	printf("\n Vertex visted : %d",startingvertex);
	
	int vertex = startingvertex - 1;
	int i = 0;
	int count = 1;
	
	while(count != noOfvertices && !IsEmpty(&st))
	{
		while(i < noOfvertices)
		{
			if(graph[vertex][i] && visited[i] == 0)
			{
				count++;
				visited[i] = 1;
				Push(&st,i);
				printf("\n Vertex visited : %d",i+1);
				
				vertex = i;
				i = 0;
				continue;
			}
			i++;
		}
		vertex = Pop(&st);
		
		//printf("\n 1 vertex poped :%d\n",vertex);
		
		if(!IsEmpty(&st))
		{
			vertex = Peep(&st);
			i = 0;
		}
	}
	free(visited);
	DeInitStack(&st);
}

void freeGraph(int **graph, int noOfvertices)
{
	if(graph)
	{
		for(int i=0 ; i<noOfvertices ; i++)
		{
			free(graph[i]);
		}
		free(graph);
	}
}

void simulateGraph()
{
	int **graph;
	int noOfvertices;
	int i,j;
	
	printf("Enter the number of vertices graph has:\n");
	scanf("%d",&noOfvertices);
	
	graph = (int **)malloc(noOfvertices*sizeof(int *));
	
	for(i=0 ; i<noOfvertices ; i++)
	{
		graph[i] = (int *)malloc(noOfvertices*sizeof(int));
	}
	//accept graph
	
	for(i=0 ; i <noOfvertices ; i++)
	{
		for(j=0 ; j<noOfvertices ; j++)
		{
			printf("\nEnter 1 if there is an edge between (v%d,v%d) o.w 0:-",i,j);
			scanf("%d",&graph[i][j]);
		}
	}
	
	//Display(graph, noOfvertices);
	
	//printf("in-degree count : %d\n",Indegree(graph,vertex, noOfvertices));

	//printf("out-degree count : %d\n",Outdegree(graph,vertex, noOfvertices));

	printf("BFS Display : \n");
	BFS(graph, noOfvertices);
	
	printf("DFS Display : \n");
	DFS(graph, noOfvertices);
		
	for(i=0 ; i<noOfvertices ; i++)
	{	
		free(graph[i]);
	}
	free(graph);
}

int main()
{
	simulateGraph();
	return 0;
}
