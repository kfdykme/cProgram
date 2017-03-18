#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node LStackNode;

typedef struct{
	LStackNode *top;
} LinkedStack;

void LinkedStackInit(LinkedStack *s){
	s->top = NULL;
}

int LinkedStackEmpty(LinkedStack *s){
	if (s->top==NULL)
		return 1;
	else 
		return 0;
}

void LinkedStackPush(LinkedStack *s, int x){
	LStackNode *ls;
	ls = (LStackNode* )malloc(sizeof(LStackNode));
	
	if (ls == NULL){
		printf("apply space fa.. .");
		exit(0);
	}
	
	ls->data = x;
	ls->next = s->top;
	s->top = ls;
	
}

int LinkedStackPop(LinkedStack *s){
	LStackNode *p;
	int x;
	
	if (s->top == NULL)
	{
		printf("stack is empty,....");
		exit(0);
	}
	x = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	return x;
}
