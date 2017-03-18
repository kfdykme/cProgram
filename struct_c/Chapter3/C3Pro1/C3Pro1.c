#include <stdio.h>
#include "linkedstack.h"
#include <stdlib.h>
#include <time.h>


int main(void){

	LinkedStack Lj,Lo;
	int i, n;
	
	srand(time(NULL));
	
	LinkedStackInit(&Lo);		
	LinkedStackInit(&Lj);		
	
	printf("Enter n:");
	scanf("%d",&n);
	
	for (i = 0; i < n; i++)
	{
		int x = rand() ;
		if ( x % 2)
			LinkedStackPush(&Lj,x);
		else
			LinkedStackPush(&Lo,x);
	}
	
	printf("ji shu:\n");
	while (Lj.top)
	{
	printf("%d\n",LinkedStackPop(&Lj));
	}
	printf("ou shu:\n");
	while (Lo.top)
	{
	printf("%d\n",LinkedStackPop(&Lo));
	}
	
	return 0;
}