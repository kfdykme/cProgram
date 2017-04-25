#include <stdio.h>

#define M 1000

typedef enum{empty,connect} Edge;

typedef struct g{
	char vexs[M];
	Edge edge[M][M];
	int vn, en;
} AdjGraph;

int locate(AdjGraph G,char c)
{
	int pos;
	for (pos = G.vn -1; pos >= 0;pos--)
		if (G.vexs[pos] == c) return pos;
	printf("\nError : can't find %C in AdjGraph.\n",c);
	return pos;
}

AdjGraph createAdjGraph(){
	//init Graph
	AdjGraph G;
	G.vn = 0;
	G.en = 0;

	for (int i =0; i < G.vn;i++)
	for (int j = 0; j <G.vn;j++)
		G.edge[i][j] = empty;
			
	//enter vexs
	printf("Enter vexs, and finished by enter '0'.\n");
	while(1){
		printf("No %d vex is :",G.vn);
		scanf(" %c",&G.vexs[G.vn]);	
		if (G.vexs[G.vn] == '0') break;
		G.vn++;
	}
	
	//enter edges
	printf("Enter edfes, and finished enter by '0 0'.\n");
	while(1){
		char tc,hc;
		getchar();
		printf("No %d edge is:",G.en);
		scanf("%c %c",&tc, &hc);
		
		if (tc == '0' && hc == '0') break;
		int t, h;
		t = locate(G,tc);
		h = locate(G,hc);
		G.edge[t][h] = connect;
		G.edge[h][t] = connect;
		G.en++;
	}		
	
	return G;
}

void printfAdjGraph(AdjGraph &G){
	
	printf("----------\n\n");
	for (int i =0; i < G.vn;i++)
		for (int j = 0; j <G.vn;j++)
			if (G.edge[i][j] == connect)
				printf("%c --> %c\n",G.vexs[i],
					G.vexs[j]);
	printf("----------\n\n");
}

int main(void){

	AdjGraph G = createAdjGraph();
		
	printfAdjGraph(G);
	return 0;
}