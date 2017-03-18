#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	Node *next;
};
typedef struct Node LQNode;


struct Queue{
	LQNode *front;
	LQNode *rear;
};

typedef struct Queue LQueue;


void LinkedQueueInit(LQueue *Q){
	
	
	LQNode* q =  (LQNode*)malloc(sizeof(LQNode));
	
	q->next = NULL;
	Q->rear = Q->front = q;
	
}

int LinkedQueueEmpty(LQueue *Q){
	if (Q->rear == Q->front)
		return 1;
	else 
		return 0;
}

void EnLinkedQueue(LQueue *Q, int x){
	LQNode *q = (LQNode*)malloc(sizeof(LQNode));
	
	q->data = x;
	q->next =NULL;
	Q->rear->next = q;
	Q->rear = q;
}

int DeLinkedQueue(LQueue *Q){
	
	if (Q->rear == Q->front)
	{
		printf("LinkedQueue is empty");
		exit(0);
	}
	
	LQNode *q = (LQNode *)malloc(sizeof(LQNode));
	
	q = Q->front->next;
	Q->front->next = q->next;
	int x=q->data;
	free(q);
	
	//??
	if (Q->front->next == NULL)
		Q->rear=Q->front;
		
	return x;
}

