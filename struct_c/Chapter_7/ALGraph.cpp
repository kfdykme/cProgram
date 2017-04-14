#include <stdio.h>
#include <stdlib.h>
#define M 100
typedef struct node
{
	int adjvex;
	struct node * nextarc;
	int info;
} EdgeNode;

typedef struct vnode
{
	char vex;
	EdgeNode *firstarc;
} VertexNode;

typedef VertexNode AdjList[M];

typedef struct 
{
	AdjList adjList;
	int n, e;
} ALGragh;


void createALGragh(ALGragh *G)
{
	int i, j,k;
	EdgeNode *s;
	printf("Enter n e.: ");
	scanf("%d %d",&G->n,&G->e);
	getchar();// get '\n'
//	printf("G->adjList[%d].vex : ",0);
	
	for(i = 0; i < G->n ;i++)
	{
		printf("G->adjList[%d].vex : ",i);
		G->adjList[i].vex = getchar();
		G->adjList[i].firstarc = NULL;
		getchar();
	}
	
	for ( k =0 ;k<G->e;k++)
	{
		printf("enter i j");
		scanf("%d %d",&i, &j);
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->nextarc = G->adjList[i].firstarc;
		G->adjList[i].firstarc =s ;
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = i;
		s->nextarc = G->adjList[j].firstarc;
		G->adjList[j].firstarc =s ;
	}
}
int main(void){
	ALGragh G;
	createALGragh(&G);
	for ( int i  =0 ; i<G.n;i++)
	{
		printf("--[%d]-is-%c\n",i,G.adjList[i].vex);
		EdgeNode *s;
		s  = G.adjList[i].firstarc;
		while(s != NULL)
		{
			printf("[%d]\t%c\n",i,G.adjList[s->adjvex].vex);
			s = s->nextarc;
		}
		printf("\n");
	}
	
	return 0;
}