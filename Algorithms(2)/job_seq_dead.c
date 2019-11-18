#include<stdio.h>
struct Job{
	char id;
	int dead;
	int profit;
}arr[50];
int min(int a,int b)
{
	return (a<b)?a:b;
}
int printJobScheduling(int n)
{
	int i,j,tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j].profit < arr[j+1].profit)
			{
				tmp = arr[j].profit;
				arr[j].profit = arr[j+1].profit;
				arr[j+1].profit = tmp;
			}
		}
	}
	int result[n];
	int slot[n];
	for(i=0;i<n;i++)
		slot[i] = 0;
	for(i=0;i<n;i++){
		for(j=min(n, arr[i].dead)-1; j>=0; j--){
			if(slot[j] == 0)
			{
				result[j] = i;
				slot[j] = 1;
				break;
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(slot[i])
			printf("%d ", arr[result[i]].id);
	}	
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%c %d %d" , &arr[i].id, &arr[i].dead, &arr[i].profit);
	}
	printJobScheduling(n);
}
