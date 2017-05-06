#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char vex;
	struct node* next;
} Edge;


typedef struct algNode{
	Edge v;
	struct algNode *next;
} ALGNode;

typedef struct{
	ALGNode *alg;
	int n;
	int e;
} ALG;

int visited[9999];

ALGNode* locateG(ALG G,char c)
{
	ALGNode *n;
	n = G.alg;
	while (n)
	{
		if (n->v.vex == c)
			return n;
		n = n->next;
	}
	printf("can't find.\n");
	return n;
}

int locateGint(ALG G,char c)
{
	ALGNode *n;
	n = G.alg;
	int i =0;
	while (n)
	{
		if (n->v.vex == c)
			break;
		n = n->next;
		i++;
	}
	
	return i;
}

ALG createALG()
{
	//init
	ALG G;
	G.n = 0;
	G.e = 0;
	G.alg = (ALGNode*)malloc(sizeof(ALGNode));
	G.alg->next = NULL;
	//enter vexs
	printf("Enter vexs : \n");
	while (1)
	{
		char v;
		printf("No.%d vex is : ",G.n);
		scanf(" %c",&v);
		
		if (v == '*') break;
		
		//create node
		ALGNode *n;
		n = (ALGNode*)malloc(sizeof(ALGNode));
		n->v.vex = v;
		n->v.next = NULL;
		
		//insert node
		n->next = G.alg->next;
		G.alg->next = n;
		G.n++;
	}
	
	printf("Enter edges : \n");
	while (1)
	{
		char head,tail;
		printf("No.%d edge is : ",G.e);
		scanf(" %c %c",&head, &tail);
		
		if (head == '*' || tail == '*') break;
		if (head == tail) continue;
		
		ALGNode *hode,*tode;
		hode = locateG(G,head);
		tode = locateG(G,tail);
		
		//printf("hode %c tode %c\n",hode->v.vex,tode->v.vex);
		
		Edge* e;
		//e = tode->v;
		e = (Edge*)malloc(sizeof(Edge));
		e->vex = tail;
		e->next = hode->v.next;
		hode->v.next = e;
		e = (Edge*)malloc(sizeof(Edge));
		e->vex = head;
		e->next = tode->v.next;
		tode->v.next = e;
		
		G.e++;
	}
	return G;
}	

void printfALG(ALG G)
{
	printf("print ALG\n");
	
	printf("It has %d vex(s), and %d edge(s)\n",G.n, G.e);
	ALGNode *p;
	p = G.alg;
	while (p)
	{
		printf(" %c ",p->v.vex);
		Edge * e;
		e = p->v.next;
		while(e){
			printf("-> %c\n",e->vex);
			e = e->next;
		}
		printf("\n");
		
		p = p->next;
	}
	printf("\n");
	
	printf("printf end\n");
}

void DFS(ALG G,char c)
{
	
	ALGNode *p;
	int pos =  locateGint(G, c);
	p = G.alg;
	for (int i =0; i < pos ; i++) p = p->next;
		
	printf("Visited %c \n",p->v.vex);
	visited[pos] = 1;
	Edge *e;
	e = p->v.next;
	
	while (e)
	{
		if (!visited[locateGint(G, e->vex)])
			DFS(G,e->vex);
		e = e->next;
	}
}

void DFSTraverse(ALG G)
{
	int i ;
	for (i =0; i < G.n;i++)
		visited[i] = 0;
	ALGNode *p;
	p = G.alg;
	i = 0;
	while (p)
	{
		if(!visited[i])
			DFS(G,p->v.vex);
		p = p->next;
		i++;
	}
}

int main(void){
	ALG G = createALG();
	printfALG(G);
	DFS(G,'a');
	return 0;
}

