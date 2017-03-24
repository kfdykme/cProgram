#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *root,*lchild, *rchild;
} BinTNode;
typedef BinTNode *BiTree;

typedef struct stacknode{
	BiTree data;
	struct stacknode *next;
} StackNode;

typedef struct treestack{
	StackNode *top;
} Stack;


void Push(Stack *S,BiTree BT)
{
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("malloc X");
		exit(0);
	}
	p->data = BT;
	p->next = S->top;
	//S->top->next = S->top;
	S->top = p;
}

StackNode* Pop(Stack *S)
{
	if (S->top == NULL)
	{
		printf("Stack is empty\n");
		exit(0);
	}
	
	StackNode *p = (StackNode*)malloc(sizeof(StackNode));
	p = S->top ;
	S->top = S->top->next;
	return p;
}


void PreOrderTraverse(BiTree BT)
{
	if(BT != NULL)
	{
		printf("%c", BT->data);
		PreOrderTraverse(BT->lchild);
		PreOrderTraverse(BT->rchild);
	}
}

void PreOrderNoRec(BiTree BT)
{
	Stack *S;
	BiTree p = BT->root;
	while ((NULL != p) 
		|| (S->top != NULL))
		{
			if (NULL != p)
			{
				printf("%C",p->data);
				Push(S,p);
				p = p ->lchild;
			}
			else
			{
				p = S->top->data;
				Pop(S);
				p = p->rchild;
			}
		}
}	

void InOrderTraverse(BiTree BT)
{
	if (BT != NULL)
	{
		InOrderTraverse(BT->lchild);
		printf("%c",BT->data);
		InOrderTraverse(BT->rchild);
	}
}

void InOrderNoRec(BiTree BT)
{
	stack *S;
	
	BiTree = p = BT->root;
	while ((NULL != p) 
		|| (S->top != NULL)
	{
		if(NULL != p)
		{
			Push(S,p);
			p = p->lchild;
		}
		else
		{
			p = S->top->data;
			Pop(S);
			printf("%c",p->data);
			p = p->rchild;
		}
	}
}

void PostOrderTraverse(BiTree BT)
{
	if(BT != NULL)
	{
		PostOrderTraverse(BT->lchild);
		PostOrderTraverse(BT->rchild);
		printf("%c",BT->data);
	}
}

void PostOrderNoRec(BiTree BT)
{
	stack *S;
	stack *tag;
	BitTree p = BT->root;
	while ((NULL != p) 
		|| S->top != NULL)
	{
		while (NULL != p)
		{
			Push(S,p);
			Push(tag,0);
			p = p->lchild;
		}
		if(S->top != NULL)
		{
			if((Pop(tag))->data == 1)
			{
				p = S->top->data;
				Pop(S);
				printf("%c",p->data);
				Pop(tag);
			}
			else
			{
				p = S->top;
				if (S->top != NULL)
				{
					p = p->rchild;
					Pop(S);
					Push(tag,1);
				}
			}
		}
	}
}


int main(void)
{
	
	
	return 0;
}