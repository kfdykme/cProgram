#include <stdio.h>
#include <stdlib.h>
int i = 0;
int A[1050],s[1050],C[1050];
		
int canZC(int x)
{
	int t ;
	for ( t = 1; t <= i ; t++)
		if (x % s[C[t]] == 0)
			return 1;
	return 0;
	}	

int main(void)
{
	int Atc, HP;
	int t, N,e = 0, st = 0;
	scanf("%d",&N);
	while (N)
	{	
		double sum = 0;
		for (t = 1; t < N;t++)
		{
			scanf("%d %d",&A[t], &s[t]);
			sum+= (A[t] * 1.0f / s[t]); 
		}
		
		scanf("%d %d", &Atc, &HP);
		
		for (t = 1; t < N; t++)
			if (A[t] > Atc)
			{
				i++;
				C[i] = t;
			}
		
		st = (int)(HP - Atc/sum);
		e = (int)(HP /sum);
		
		int l =0;
		for (t = 1;t < N ;t++)
		     l +=(st /s[t] * A[t]);
		 while (l < (HP-Atc))
		 {
		 	st++;    
		 	l=0;
		for (t = 1;t < N ;t++)
		     l +=(st /s[t] * A[t]);
		 }
		 
		 while (canZC(st) && (st <= e))
		 	st++; 
		 	
		 l = 0;
		 for (t = 1;t < N;t++)
		     l += (e /s[t] * A[t]);
		 while (l < HP)
		 {
		 	e++;    
		 	l=0;
		 	for (t = 1;t < N;t++)
		     l += (e /s[t] * A[t]);
		 }
		
		 
		 while (canZC(e) && (e>=st))
		 	e--; 
		
				
		if (st>e)
			printf("Impossible\n");
		else 		
			printf("%d %d\n", st, e);
	scanf("%d",&N);
	}
	return 0;
}