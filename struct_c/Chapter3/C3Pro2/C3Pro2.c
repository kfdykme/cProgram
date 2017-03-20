#include <stdio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

typedef struct Node StackNode;

struct Linked{
	StackNode *top;
};

typedef struct Linked LinkedStack;

void StackInit(LinkedStack *S)
{
	S->top = NULL;
}

int StackIsEmpty(LinkedStack *S)
{
	if (S->top == NULL)
		return 1;
	else 
		return 0;
}

void StackPush(LinkedStack *S,char c)
{
	StackNode *p;
	p = (StackNode*) malloc(sizeof(StackNode));
	
	if (p == NULL)
	{
		printf("Apply space faile\n");
		exit(0);
	}
	
	p->data = c;
	p->next = S->top;
	S->top = p;
}

char StackPop(LinkedStack *S)
{
	StackNode * p;
	char c;
	p = S->top;
	c = p->data;
	S->top = S->top->next;
	free (p);
	return c;
}
	
	
	
	

#include <string.h>
int main(void)
{
	char s[100], *c;
	gets(s);
	c = s;
	int length = strlen(s), l = length/2 ;
	int i;
	LinkedStack L;
	StackInit(&L);
	
	for (i = 0; i < l; i++)
	{
		StackPush(&L, s[i]);	
	}
	
	if (length % 2 )
			i++;
		
	for (; i < length; i++)
	{
		if (s[i] != StackPop(&L))
		{
			printf("NOt!!");
			return 0;
		}	
	}
	
	printf("Yes!!");
	//scanf("%s");		
	return 0;
}