#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode{
	char data;
	struct stackNode *next;
} Node;

typedef struct{
	Node *top;
} Stack;

void initStack(Stack *s);
void push(Stack *s,int e);
void readString(char *st,Stack *s);
char pop(Stack *s);

void initStack(Stack *s)
{
	s->top = NULL;// (Node*)malloc(sizeof(Node));
	//s->top->next = NULL;
}

void push(Stack *s,char e)
{
	Node* node = (Node*)malloc( sizeof (Node));
	
	if (node == NULL){
		printf("apply space fa.. .");
		exit(0);
	}
	node->data = e;
	node->next = s->top;
	s->top = node;
}

char pop(Stack *s)
{
	if (s->top != NULL)
	{
		char e = s->top->data;
		Node *p = s->top;
		
		s->top = p->next;
		free(p);
		return e;
	} else {
		printf("this stack is empty!\n");
		exit(0);
	}
	
}

void readString(char *st,Stack *s){
	char c;
	while((c = *(st++) ) != '\0')
	{
		if ( c == '(' 
		|| c == '['
		|| c == '{')
		{
			push(s,c);
		}
		if (c == ')')
		{
			if (pop(s) != '(')
			{
				printf("No~~~~~\n");
				return ;
			}
		}
		if ( c == ']')
		{
			if (pop(s) != '[')
			{
				printf("No~~~~~\n");
				return ;
			}
		}
		if ( c == '}')
		{	
			if (pop(s) != '{')
			{
				printf("No~~~~~\n");
				return ;
			}
		}
	}
}
int main(void)
{
	Stack *s;
	s = (Stack*) malloc (sizeof (Stack));

	char st[100];
	strcpy(st,"(((({)");
	char st2[100];
	strcpy(st2,"(((({}[]{()}))))");
	initStack(s);
	readString(st2,s);
	return 0;
}