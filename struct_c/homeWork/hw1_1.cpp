#include <stdio.h>
#include <stdlib.h>



struct node{
	int first;
	int last;
	int *q;
	int M;
};

typedef struct node Queue;

void insert(Queue *Q,int e);
int deleteQu(Queue *Q);
int isEmpty(Queue *Q);
int isFullQu(Queue *Q);

int isFullQu(Queue *Q)
{
//	printf("isFull\n");
//	printf("firsrt %d last %d\n",Q->first, Q->last);
	if((Q->last +1  ) % Q->M == Q->first)
	{
			printf("is Full\n");
			return 1;
	} else {
		return 0;
	}
	
}

void insert(Queue *Q,int e)
{
//	printf("insert start\n");

						
	if (!isFullQu(Q)){
		
		if (Q->last +1 == Q->M)
			Q->last = -1;
		Q->q[++Q->last] = e;
		
	
	}
}

int isEmpty(Queue *Q)
{
	if (Q->first == Q->last)
		return 1;
	else 
		return 0;
}

int deleteQu(Queue *Q)
{
	if (!isEmpty(Q))
	{
		if (Q->first + 1 == Q->M)
			Q->first = -1;
		int e = Q->q[++Q->first];
		return e;
	}
	return -1;
}

int main(void)
{
	Queue Q;
	Q.M = 100;
	Q.q  = (int*)malloc(sizeof (int) *(Q.M+1));
	Q.first = 0;
	Q.last = 0;
	int testData[100] = {3,2,1,3,-1,3,2,1,0,9,11};	
	for  (int i = 0 ;  ; i++)
	{
		if (testData[i] > 0)
			insert(&Q,testData[i]);
		if (testData[i] == 0)
			break;
		if (testData[i] == -1)
			deleteQu(&Q);
		
			

	}
	printf("printf\n");
	while (!isEmpty(&Q))
	{
		int d = deleteQu(&Q);
		printf("%d",d);

	}
	return 0;
}