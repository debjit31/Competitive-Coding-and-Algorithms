#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
void primeSieve(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int p = 2; p*p <= n; p++)
	{
		if (prime[p] == true)
		{
			for(int i = p*p; i<= n ; i+=p)
				prime[i] = false;
		}
	}
	for(int p=2;p<=n;p++)
	{
		if(prime[p] == true)
			printf("%d ", p);
	}
	
}
int main()
{
	int n;
	printf("Enter a number :- ");
	scanf("%d", &n);
	printf("All prime numbers smaller than and equal to %d are :- \n",n);
	primeSieve(n);	
}

