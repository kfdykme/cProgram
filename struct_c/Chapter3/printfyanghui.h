#include <stdio.h>
#include "linkedqueue.h"

void printyj(LQueue *q,int n)
{
	EnLinkedQueue(q,1);
	int i, j, s, x ;
	for ( i = 0; i< n; i++)
	{
		s= 0;
		EnLinkedQueue(q,0);
		for (j = 1; j <=i+2; j++)
		{
			x= DeLinkedQueue(q);
			EnLinkedQueue(q,x+s);
			s = x;
			if (j != i + 2)
				printf("%d ",s);
		}
		
		printf("\n");
	}
}

int main(void){
	LQueue q;
	LinkedQueueInit(&q);
	
	printyj(&q,20);
	return 0;
}