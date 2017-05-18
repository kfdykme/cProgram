#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next,*fore;
} Node;

typedef struct {
	Node *head;
} CirLink;

void initCirLink(CirLink *L);
void inCirLink(CirLink *L,int e);

/*
void change(CirLink *L);
void changeOne(CirLink *L,Node *n);
void change(CirLink *L){
	Node *p ;
	Node *p1,*p2;
			
	p = L->head;
	p1 = p->next;
	while ( p->next != L->head)
	{
	//de
		p->next = p1->next;
		p1->next->fore = p;
	
	//insert	
		
		L->head->next->fore = p1;
		p1->next = L->head->next;
		p1->fore= L->head;
		L->head->next = p1;
		
		printf("%d\n",p->d);
		p = p->next;
		p1 = p->next;
	}
}

*/

void initCirLink(CirLink *L)
{
	L->head->next = L->head;
	L->head->fore = L->head;
}
void inCirLink(CirLink *L,int e){
	Node *p ;
	
	p = (Node*)malloc( sizeof(Node));
	
	p->d = e;
	L->head->next->fore = p;
	p->next = L->head->next;
	p->fore= L->head;
	L->head->next = p;
	
}

int main(void)
{
	CirLink L;
	L.head =(Node*)malloc( sizeof(Node));
	
	initCirLink(&L);
	int a[100] = {0,1,2,3,4,5,3,4,2,1,1,};
	for (int i = 0; i < 12; i++)
		inCirLink(&L,a[i]);
	Node *p,*p2;
	p = L.head->next;
	p2 = p->next;
	while ( p != L.head)
	{
		printf("%d %d\n",p->d,p2->d);
		p = p->next;
		p2 = p2->next;
	}
//	change(&L);
	p = L.head->fore;
	p2 = p->fore;
	while ( p != L.head)
	{
		printf("%d %d\n",p->d,p2->d);
		p = p->fore;
		p2 = p2->fore;
	}
}