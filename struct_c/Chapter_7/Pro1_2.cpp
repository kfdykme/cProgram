#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct adjgraph{
 char vex[M];
 int edge[M][M];	
 int en;
 int vn;
} AdjGraph;

int locateGraph(AdjGraph G,char c)
{
	int i;
	for ( i = G.vn-1 ; i >= 0; i--)
		if(G.vex[i] == c)
			return i;		
	return i; 
}


AdjGraph createGraph(){
	AdjGraph G;
	G.en = 0;
	G.vn = 0; 
	printf("Enter vexs, and end by '*':\n");
	while(G.vn == 0 || G.vex[G.vn-1] != '*')
	{
		printf("No.%d vex is : ",G.vn);
		scanf(" %c",&G.vex[G.vn++]);
	}
	for ( int i = 0; i  <G.vn ; i++)
		for (int j = 0; j < G.vn ; j++)
			G.edge[i][j] = 0;
			
	printf("Enter edge and end by '* *':\n");
	char head,tail;
	do{
		printf("No.%d edge is : ",G.en);
		scanf(" %c %c",&head , &tail);
		
		int h,t;
		h = locateGraph(G,head);
		t = locateGraph(G,tail);
		
		if (h == -1 || t == -1 || t == h)
		 continue;
		
		G.edge[h][t] = 1;
		G.edge[t][h] = 1;
		G.en++;
	}while (head != '*' && tail != '*' );
	
	return G;
}

void printfGraph(AdjGraph G)
{
	for (int i =0 ; i < G.vn ; i++)
	{
		for (int j =0 ; j < G.vn ; j++)
			printf(" %d",G.edge[i][j]);
		printf("\n");
	}
}

int getDegree(AdjGraph G)
{
	printf("Enter a vex :");
	char c;
	scanf(" %c",&c);
	int pos = locateGraph(G,c);
	if (pos == -1)
	{
		printf("Can't find this vex !\n");
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < G.vn; i++)
		if (G.edge[0][i] == 1)
			sum++;
	return sum;
}	

int main(void){
	AdjGraph G= createGraph();
	printfGraph(G);
	
	printf("%d",getDegree(G));
	return 0;
}