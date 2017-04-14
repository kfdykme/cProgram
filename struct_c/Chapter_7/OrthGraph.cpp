# include <stdio.h>
# include <stdlib.h>
#define M 100

typedef struct node{
	int headvex;
	int tailvex;
	struct node *hlink, *tlink;
} EdgeNode;

typedef struct vnode{
	char c;
	int w;
	EdgeNode *firstin,*firstout;
} VertexNode;

typedef struct 
{
	VertexNode Orthlist[M];
	int vexnum, arcnum;
} OrthGraph;

void createOLGraph(OrthGraph *G)
{
	printf("Enter vexnum arcnum(a b):\n");
	scanf("%d %d",&G->vexnum, &G->arcnum);
	int ix;
	for ( ix =0;ix<G->vexnum; ++ix)
	{
		printf("Enter th %dth data and wight(a b) \n",ix);
		scanf(" %c %d",&G->Orthlist[ix].c,
		&G->Orthlist[ix].w);
		G->Orthlist[ix].firstin = NULL;
		G->Orthlist[ix].firstout = NULL;
	}
	
	for (ix = 0;ix<G->arcnum;ix++)
	{
		char v1,v2;
		printf("Enter <v1,v2>(v1 v2)\n");
		scanf(" %c %c",&v1,&v2);
		
		//find head an tail
		//head:
		int head = -1;
		for ( head = 0; head <G->vexnum;head++)
			if ( G->Orthlist[head].c == v2)
				break;  
		int tail = -1;
		for ( tail = 0; tail <G->vexnum;tail++)
			if ( G->Orthlist[tail].c == v1)
				break;  
		
		if (tail == -1 || head == -1)
			printf("Error : can't find head or tail!\n");
		EdgeNode *p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->tailvex = tail;
		p->headvex = head;
		
		p->hlink = G->Orthlist[head].firstin;
		p->tlink = G->Orthlist[tail].firstout;
		
		G->Orthlist[head].firstin = p;
		G->Orthlist[tail].firstout = p;
	}
}
		
	


int main(void){
	
	OrthGraph G;
	
	createOLGraph(&G);
	printf("vex %d arc %d",G.vexnum, G.arcnum);
	for (int i = 0; i <G.vexnum;i++)
	{
		while(
	}
	return 0;
}