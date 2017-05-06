#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct node{
	char vex;
	struct node *next;
	int info;
}EdgeNode;

typedef struct vnode{
	char vex;
	EdgeNode *firstarc;
}VertexNode;

typedef VertexNode AdjList[M];

typedef struct{
	AdjList adjlist;
	int n, e;
}ALGraph;

int locateGraph(ALGraph G,char c)
{
	int i;
	for ( i = G.n-1;i>=0;i--)
		if (G.adjlist[i].vex == c)
			return i;
			
	return i;
}

ALGraph createGraph(){
	ALGraph G;
	G.n = 0;
	G.e = 0;
	
	printf("Enter vexs :\n");
	do{
		printf("No.%d vex is : ",G.n);
		scanf(" %c",&G.adjlist[G.n++].vex);
		G.adjlist[G.n-1].firstarc = NULL; 
	}while(G.adjlist[G.n-1].vex != '*');
	G.n--;
	printf("Enter edges :\n");
	char head,tail;
	do{
		printf("No.%d edge is : ",G.e);
		scanf(" %c %c",&head,&tail);
		int h,t;
		h = locateGraph(G,head);
		t = locateGraph(G,tail);
		
		if (h == -1 || t == -1 || h == t)
			continue;
			
		EdgeNode *e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->vex =head;
		e->next = G.adjlist[t].firstarc;
		G.adjlist[t].firstarc = e;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->vex =tail;
		e->next = G.adjlist[h].firstarc;
		G.adjlist[h].firstarc = e;
		G.e++;
	}while(head != '*' && tail != '*'); 
	
	return G;
}

void printfGraph(ALGraph G){
	printf("G start\n");
	//printf("%d\n",G.n);
	for (int i = 0; i < G.n;i++)
		printf(" %c",G.adjlist[i].vex);

	printf("\n");

	EdgeNode *p;
	int i;
	for (i =0; i < G.n;i++)
	{
		
		printf(" %c\n",G.adjlist[i].vex);

		p = G.adjlist[i].firstarc;
		while (p){
				printf("%c -> %c\n",G.adjlist[i].vex, p->vex);
			p = p->next;
		}
		printf("\n");
	}
//	printf("\n");
	printf("G end");
}
int main(void){
	ALGraph G = createGraph();
	printfGraph(G);
	
	return 0;
}