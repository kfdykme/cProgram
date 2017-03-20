#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100



struct q{
	int data[MAXSIZE];
	int count = 0;
	int *front = data;
};
	
typedef struct q Queue;

void QueueSetEmpty(Queue *Q)
{
	Q->front =NULL;
}

int QueueIsEmpty(Queue *Q)
{
	if (Q->front != NULL )
		return 1;
	else 
		return 0;
}

int QueueDe(Queue*Q)
{
	if (Q->count == 0)
	{
		printf("Queue is Empty\n");
		exit(0);
	}
	
	int x = *Q->front;
	Q->front++;
	Q->count--;
	return x;
}

void QueueEn(Queue *Q,int e)
{
	if (Q->count == MAXSIZE)
	{
		printf("Queue is Full\n");
		exit(0);
	}
	Q->data[(Q->front - Q->data + Q->count) % MAXSIZE] = e;
	Q->count++;
}

 int main(void){
 	Queue Q;
 	
 	QueueEn(&Q,1);
 	printf("%d", QueueDe(&Q));
 	
 	
 	 return 0;
 } 