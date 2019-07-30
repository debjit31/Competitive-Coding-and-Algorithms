#include<stdio.h>
int duration[100],profits[100],jobs[100];
char job_names[100];
void sort_jobs(int pro[], int time[],int n)
{
	int tmp1,tmp2,i,j;
	int swapped;
	for(i=0;i<n-1;i++)
	{
		swapped = 0;
		for(j=0;j<n-i-1;j++)
		{
			if(pro[j]<pro[j+1])
			{
				tmp1 = pro[j];
				pro[j] = pro[j+1];
				pro[j+1] = tmp1;
				tmp2 = time[j];
				time[j] = time[j+1];
				time[j+1] = tmp2;
				swapped++;
			}
		}
		if(swapped == 0)
			break;
	}
	
}
void job_scheduling(int pro[], int time[], int n){
	int result[n],slot[n],i,j,sum=0;
	for(i=0;i<n;i++)
		slot[i]=0;
	for(i=0;i<n;i++)
	{
		for(j = time[i]-1; j>=0; j--)
		{
			
			if(slot[j] == 0)
			{
				result[j] = i; 
				slot[j] = 1;
				sum+=pro[i];
				break;
			}
		}
	}
	printf("\nThe jobs that should be selected are :- ");
	for(i=0;i<n;i++)
	{
		if(slot[i])
			printf("J%d ", result[i]+1);
			
	}
	printf("\nThe total profit is :- %d", sum);
}
int main()
{
	int n,i,j;
	int tmp1,tmp2;
	printf("Enter the number of jobs :- ");
	scanf("%d",&n);
	printf("\nEnter the profit and durations separated by a single space :- \n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &profits[i], &duration[i]);
	}
	sort_jobs(profits, duration, n);
	printf("The available job durations with their profits in decreasing order are :- \n");
	for(i=0;i<n;i++)
		printf("%d ",profits[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",duration[i]);
	int max;
	max = duration[0];
	for(i=1;i<n;i++)
	{
		if(duration[i] > max)
			max = duration[i];
	}
	printf("\n%d\n",max);
	job_scheduling(profits,duration,n);
}
