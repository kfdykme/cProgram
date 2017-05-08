#include <stdio.h>

#include <stdlib.h>

#define M 1000

typedef struct node{
	char vex;
	struct node *next;
} VexNode;

typedef VexNode list[M];

typedef struct{
	list alg;
	int v,e;
} ALG;


int locateALG(ALG *G,char c)
{
	int i;
	for (i =G->v; i >= 0; i--)
	{
		//printf("%c--->%d\n",c,i);
		if ( G->alg[i].vex == c)
			break;
	}
	return i;
}

ALG createALG(){
	ALG G;
	G.v = 0;
	G.e = 0;
	return G;
}

void insertALGVex(ALG *G, char c)
{
	G->alg[G->v].vex = c;
	G->alg[G->v].next = NULL;
	G->v++;
}

void insertALGEdge(ALG *G,char h, char t)
{
	int hi = locateALG(G,h);
	if (hi == -1)
	{
		insertALGVex(G,h);
		hi = locateALG(G,h);
	}
	int ti = locateALG(G,t);
	if (ti == -1)
	{
		insertALGVex(G,t);
		ti = locateALG(G,t);
	}
	
	VexNode *p ;
	p =  (VexNode*)malloc(sizeof(VexNode));
	
	p->vex = t;
	
	//printf("%d %d\n",hi , ti);
	//if (G->alg[hi].next != NULL)
	//printf("%c",G->alg[hi].next->vex);
	p->next = G->alg[hi].next;

	G->alg[hi].next = p;
	G->e++;		
}


void printfALG(ALG *G){
	printf("G start\n");
	//printf("%d\n",G.n);
	for (int i = 0; i < G->v;i++)
		printf(" %c",G->alg[i].vex);

	printf("\n");

	VexNode *p;
	int i;
	for (i =0; i < G->v;i++)
	{
		
		printf(" %c\n",G->alg[i].vex);

		p = G->alg[i].next;
		while (p){
				printf("%c -> %c\n",G->alg[i].vex, p->vex);
			p = p->next;
		}
		printf("\n");
	}
//	printf("\n");
	printf("G end");
}


void readString(char *s,ALG *G){
	char c;
	int ht = 0 ;
	/*
	 0 - start
	 1 - head 
	 2 - head done
	 3 - tail
	 4 - tail done
	 */
	 char head;
	 char tail;
	while((c = *s++) != '\0')
	{
		switch (ht)
		{
			case 1:
				printf("head is %c\n",c);
				head = c;
				ht++;
				break;
			case 3:
				printf("tail is %c\n",c);
				tail = c;
				
				//insert
				insertALGEdge(G,head,tail);
				
				ht++;
				break;
		}
		
		if (c == '(' && ht == 0) ht++;
		else if (c == ',' && ht == 2) ht++;
		else if (c == ')'&& ht == 4) ht = 0;
	
	} 
	printfALG(G);
}

int main(void)
{
	char s[100] = "(a,c),(a,d),(b,e),(c,d),(e,c)";
	ALG G = createALG();
	readString(s,&G);
	return 0;
}