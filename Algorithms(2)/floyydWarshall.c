#include<stdio.h>
int V;
void printSolution(int a[50][50]){
    
    int i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
}
void ShortestPath(int cost[50][50]){
    
    int dist[50][50],i,j,k;
    for(i=0;i<V;i++)
    {
    	for(j=0;j<V;j++)
    	{
    		dist[i][j] = cost[i][j];
		}
	}
	//printSolution(cost);
	//printSolution(dist);
        
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
    int cost[50][50];
    scanf("%d",&V);
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d", &cost[i][j]);
        }
            
    }
    ShortestPath(cost);        
}
