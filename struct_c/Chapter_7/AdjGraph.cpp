#include<stdio.h>

#define M 100

typedef struct {
	char vexs[M];
	int edges[M][M];
	int n, e;
} AdjGragh;

void createAdjGragh(AdjGragh *G)
{
	int i,j,k,w;
	printf("Enter n e :\n");
	scanf("%d %d",&G->n, &G->e);
	printf("Enter %d vexs: \n",G->n);
	getchar();
	for (i = 0; i <G->n;i++)
		G->vexs[i] = getchar();
	for (i = 0; i < G->n ;i++)
		for (j =0; j<G->n;j++)
			G->edges[i][j] = 0;
	for (k = 0; k < G->e;k++)
	{
	printf("Enter i j and w in [i][j]:\n");		
		scanf("%d %d %d",&i,&j,&w);
		G->edges[i][j] = w;
		G->edges[j][i] = w;
		
	}
	printf("AdjGragh created \n");		

}

int main(void){
	AdjGragh G;
	
	createAdjGragh(&G);
	printf("n %d e %d\n",G.n,G.e);
	for (int i = 0; i < G.n;i++)
	{
		printf("[%d] %c \n",i, G.vexs[i]);
	}
	
	for (int i =0; i <G.n;i++)
	{
			for (int j =0; j <G.n;j++)
		{
			printf("[%d]\t",G.edges[i][j]);
		}
		printf("\n");
	}
}