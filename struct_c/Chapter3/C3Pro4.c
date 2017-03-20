#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

typedef struct node Node;

struct stack{
	Node * top;
};

typedef struct stack Stack;

void StackInit(Stack *S)
{
	S->top = NULL;
}

int StackIsEmpty(Stack *S)
{
	if (S->top == NULL)
		return 1;
	else 
		return 0;
}

void StackPush(Stack *S, int e)
{
	Node *p;
	
	p = (Node*) malloc (sizeof(Node));
	
	if (p == NULL){
		printf("faile");
		exit(0);
	}
	
	p->data = e;
	p->next = S->top;
	S->top = p;
}

int StackPop(Stack *S)
{
	
	if (S->top == NULL)
	{
		printf("Stack is Empty");
		exit(0);
	}
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	
	if (p == NULL){
		printf("faile");
		exit(0);
	}
	
	
	p = S->top;
	int x = p->data;
	S->top = S->top->next;
	free(p);
	return x;
}

void ClearStack(Stack *S)
{
	while (!StackIsEmpty(S))
	{
		StackPop(S);
	}
	
}

int main(void)
{
	
	Stack s;
	StackInit(&s);
	for (int i = 0; i < 20; i++)
		StackPush(&s,i);

	ClearStack(&s);

	for (int i = 0; i < 20 ; i++)
		printf("%d\n",StackPop(&s));
		
		
	return 0;
}