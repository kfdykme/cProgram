#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *lchild, *rchild;
	int ltag, rtag;
} TBinTNode;
typedef TBinTNode *TBinTree;

void InOrderThreading(TBinTree p)
{
	TBinTree pre;
	if (p != NULL)
	{
		InOrderThreading(p->lchild);
		if(p->lchild != NULL)
			p->ltag = 0;
		else
			p->ltag = 1;
		if(p->rchild != NULL)
			p->rtag = 0;
		else
			p->rtag = 1;
		if(pre != NULL)
		{
			if(pre->rtag == 1)
				pre->rchild = p;
			if (pre->ltag == 1)
				pre->lchild =p;
		}
		pre = p;
		InOrderThreading(p->rchild);
	}
}

TBinTNode * InOrderSuc(TBinTree p)
{
	TBinTNode *q;
	if (p->rtag == 1)
		return p->rchild;
	else
	{
		q = p->rchild;
		while(q->ltag == 0)
			q= q->lchild;
		return q;
	}
}

TBinTNode *InOrderPre(TBinTree p)
{
	TBinTNode *q;
	if (p->ltag ==1)
		return p->lchild;
	else
	{
		q=p->lchild;
		while(q->rtag==0)
			q= q->rchild;
		return q;
	}
}

void TraversInorderThrTree(TBinTree p)
{
	if ( p != NULL)
	{
		while (p->ltag ==0)
			p = p->lchild;
		while (p != NULL)
		{
			printf("%c\n",p->data);
			exit(0);
		}
	}
}
			
int main(void)
{
	
	return 0;
}