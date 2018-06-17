#ifndef GRAPH_H
#define GRAPH_H

int **AllocateGraph(int noOfvertices);
int **Accept(int **graph, int noOfvertices);
void Display(int **graph, int noOfvertices);
int Indegree(int **graph, int vertex, int noOfvertices);
int Outdegree(int **graph, int vertex, int noOfvertices);
void BFS(int **graph, int noOfvertices);
void DFS(int **graph, int noOfvertices);
void freeGraph(int **graph, int noOfvertices);

#endif
