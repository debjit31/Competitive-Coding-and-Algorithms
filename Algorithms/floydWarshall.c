#include<stdio.h>
#define INF 999999
//#define V 4
int V;
void printSolution(int a[V][V]){
	
	int i,j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(a[i][j] == INF)
				printf("%7s","INF");
			else
				printf("%7d", a[i][j]);
		}
		printf("\n");
	}
	
	
}
void ShortestPath(int graph[V][V]){
	
	int dist[V][V],i,j,k;
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
		{
			dist[i][j] = graph[i][j];
		}
	for(k=0; k<V; k++)
	{
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}	
	}
	printSolution(dist);	
	
}

int main()
{
	int i,j;
	int graph[50][50];
	printf("Enter the number of vertices :- ");
	scanf("%d",&V);
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d", &graph[i][j]);
		}
			
	}
	/*
	int graph[V][V] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      }; */
	ShortestPath(graph);		
}
