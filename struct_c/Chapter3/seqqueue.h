#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
struct Node{
	int data[MAXSIZE];
	int front;
	int rear;
};

typedef struct Node SeqQueue;

void InitSeqQueue(SeqQueue *Q){
	Q->front  = -1;
	Q->rear = -1;
}

void EnSeqQueue(SeqQueue *Q, int x){
	if (Q->rear == MAXSIZE-1){
		printf("full");
		exit(0);
	}
	Q->data[++Q->rear] = x;
}

int DeSeqQueue(SeqQueue *Q){
	if (Q->front == Q->rear){
		printf("SeqQueue is null.");
		exit(0);
	}
	return Q->data[++Q->front];
}


