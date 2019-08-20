#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n;
void primeSieve(int a,int b)
{
	bool prime[b+1];
	for(int i=a;i<=b;i++)
		prime[i] = true;
		
	for(int p=2;p*p<=n;p++)
	{
		if(prime[p] == true)
		{
			for(int i = p*p;i<=b;i+=p)
				prime[i] = false;
		}
	}
	for(int p = a; p<=b; p++)
	{
		if(prime[p] == true)
		{
			printf("%d ", p);
		}
	}
	
}
int main()
{
	scanf("%d", &n);
	int data[n];
	for(int i = 0; i<n; i++)
		scanf("%d", &data[i]);
		
	int max = data[0], min = data[0];
	for(int i=0; i<n ;i++)
	{
		if (data[i] > max)
			max = data[i];
		else if (data[i] < min)
			min = data[i];
	}
	//printf("%d %d", min,max);
	primeSieve(min, max);
}
