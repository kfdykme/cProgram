#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

struct Node{
	int data[MAXSIZE];
	int front;
	int rear;
};

typedef struct Node CircleSeqQueue;

void InitCircleSeqQueue(CircleSeqQueue *C){
	C->front = -1;
	C->rear = -1;
}

int CircleSeqQueueEmpty(CircleSeqQueue *C){
	if (C->front == C->rear)
		return 1;
	else 
		return 0;
}

void EnCircleSeqQueue(CircleSeqQueue *C, int x){
	if ((C->rear + 1) % MAXSIZE == C->front ){
		printf("CircleSeqQueue is full");
		exit(0);
		}
	 if (C->rear == MAXSIZE-1)
		C->rear = -1;
		
	C->data[++C->rear] = x;
}

int DeCircleSeqQueue(CircleSeqQueue *C){
	if (CircleSeqQueueEmpty(C)){
		printf("CircleSeqQueue is empty.");
		exit(0);
	} 
	if (C->front == MAXSIZE-1)
			C->front = -1;
	
	return C->data[++C->front];
	
}


