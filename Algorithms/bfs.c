#include <stdio.h>
int front = 0, rear = 0;
int queue[100];
int n;
void enqueue(int a)
{
	if(rear == n+1)
		printf("\nQueue Overflow!!!");
	else if(front == 0 && rear == 0)
	{
		front=1;
		rear=1;
	}
	else
		rear++;
	
	queue[rear] = a;
		
}
int dequeue()
{
	if (front == n+1)
		return 0;
	else
	{
		return queue[front++];
	}
}
int queue_empty()
{
    if(front == n+1)
        return 1;
    else 
        return 0;
}
void bfs(int adj[50][50], int s, int d, int n){
    
    int visited[50],i,j,dv,k=0,path[100];
    for(i=1;i<=n;i++)
        visited[i] = 0;
    visited[s] = 1;
    enqueue(s);
    while(!queue_empty()){
        
        dv = dequeue();
        //printf("%d ", dv);
        path[k++] = dv;
        for(j=1;j<=n;j++){
            if(adj[dv][j] == 1)
            {
                if(visited[j] == 0)
                {
                    visited[j] ==  1;
                    enqueue(j);
                }
            }
        }
        
    }
    for(i=0;i<=k;i++)
    	printf("%d ", path[i]);
}
int main() {
	int i,j,s,d;
	scanf("%d", &n);
	int adj[50][50];
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        scanf("%d", &adj[i][j]);
	    }
	}
	scanf("%d", &s);
	scanf("%d", &d);
	bfs(adj,s,d,n);

	return 0;
}
