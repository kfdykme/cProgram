#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct circlenode{
	int data[MAXSIZE];
	int front;
	int rear;
};

typedef struct circlenode CircleQueue;

void QueueInit(CircleQueue *cQ)
{
	cQ->front = 0;
	cQ->rear = 0;
}

int QueueIsEmpty(CircleQueue *cQ)
{
	if (cQ->front == cQ->rear)
		return 1;
	else
	 	return 0;
}

void QueueEn(CircleQueue *cQ, int e)
{
	if ((cQ->rear +1 ) % MAXSIZE == 
		cQ->front)
	{
		printf("Queue is Full.");
		exit(0);
	}
	
	if (cQ->rear == MAXSIZE -1)
		cQ->rear = 0;
		
	cQ->data[cQ->rear++] = e;
}

int QueueDe(CircleQueue *cQ)
{
	if (QueueIsEmpty(cQ))
		printf("Queue is Empty.");
	
	if (cQ->front == MAXSIZE -1)
		cQ->front = 0;
	
	return cQ->data[cQ->front++];
}	

int QueueLength(CircleQueue *cQ)
{
	int l;
	if (cQ->front > cQ->rear)
	{
		l  = cQ->rear + MAXSIZE - cQ->front;
	} else if (cQ->front == cQ->rear){
		l = 0;
	} else 
	{
		l = cQ->rear - cQ->front;
	}
	
	return l;
}

int main(void)
{
	CircleQueue Q;
	
	QueueInit(&Q);
	
	int l ;
	
	for (int i = 0; i < 99 ; i++)
		QueueEn(&Q,i);
	for (int i = 0; i < 20 ; i++)
		QueueDe(&Q);
	l = QueueLength(&Q);
	
	printf("%d",l);
	
	return 0;
}