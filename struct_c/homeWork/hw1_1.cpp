#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} Node;

typedef struct {
	Node *head;
} CirLink;

void initCirLink(CirLink *L);
void inCirLink(CirLink *L,int e);
Node* getCirLink(CirLink *L,int e);
void deCirLink(CirLink *L,int e);
void deAllCirLink(CirLink *L,int e);
void deAllCirLink(CirLink *L,int e){
		Node *p,*p2;
	p = L->head->next;
	p2 = p->next;
	while ( p != L->head)
	{
		if(p2->d == e)
		{
			deCirLink(L,e);
		}
	//	printf("%d %d\n",p->d,p2->d);
		p = p->next;
		p2 = p2->next;
	}

}
void initCirLink(CirLink *L)
{
	L->head->next = L->head;
}

void inCirLink(CirLink *L,int e)
{
	Node *p ;
	
	p = (Node*)malloc( sizeof(Node));
	
	p->d = e;
	p->next = L->head->next;
	L->head->next = p;
}
Node* getCirLink(CirLink *L,int e)
{
	Node *p;
	p  = L->head->next;
	while (p !=L->head )
	{
		if (p->d == e)
			break;
		p = p->next;
	}
	return p;
}
void deCirLink(CirLink *L, int e)
{
	Node *p,*p2;
	p = L->head->next;
	p2 = p->next;
	while ( p != L->head)
	{
		if(p2->d == e)
		{
			p->next = p2->next;
			p2 = p->next->next;
			free(p2);
			return ;
		}
	//	printf("%d %d\n",p->d,p2->d);
		p = p->next;
		p2 = p2->next;
	}
}
int main(void)
{
	CirLink L;
	L.head =(Node*)malloc( sizeof(Node));
	
	initCirLink(&L);
	int a[100] = {0,1,2,3,4,5,3,4,2,1,1,};
	for (int i = 0; i < 12; i++)
		inCirLink(&L,a[i]);
	deAllCirLink(&L,1);
	Node *p,*p2;
	p = L.head->next;
	p2 = p->next;
	while ( p != L.head)
	{
		printf("%d %d\n",p->d,p2->d);
		p = p->next;
		p2 = p2->next;
	}
}