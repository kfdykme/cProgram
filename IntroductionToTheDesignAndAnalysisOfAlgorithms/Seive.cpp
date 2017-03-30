#include <stdio.h>


int Sieve(int n,int *L)
{
	int i,j ,A[n];
	for(i=2;i<=n;i++)
		A[i] = i;
	for(i=2; i*i < n;i++)
		if(A[i] != 0)
		{
			j= i*i;
			while (j<=n)
			{
				A[j] =0;
				j+=i;
			}
		}
		
	j=0;
	for(i=2;i<=n;i++)
		if(A[i] !=0)
			L[j++] = A[i];
	return j;		
}

int main(void)
{
	int L[10000];
	int j = Sieve(25,L);
	int i;
	for(i=0;i<j;i++)
		printf("%d ",L[i]);
		
	
	
	return 0;
}