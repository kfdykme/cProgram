#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct {
	char vex[M];
	int edge[M][M];
	int vn, en;
} AdjG;

typedef struct {
	char vex[M];
	int edge[M][M][M];
	int vn,en;
} IncG;

typedef struct node{
	char vex;
	struct node *next;
} VexNode;

typedef struct{
	int vn,en;
	VexNode g[M]; 
} ALG;
AdjG createAdjG();
int locateAdjG(AdjG G, char c);
int outDegreeAdjG(AdjG G,char c);
int inDegreeAdjG(AdjG G,char c);
IncG createIncG();
int locateIncG(IncG G, char c);
ALG createALG();
int locateALG(ALG G, char c);
void printALG(ALG G);

void printALG(ALG G)
{
	printf("this alg has %d vex and %d edges\n",G.vn,G.en);
	for (int i =0; i < G.vn; i++)
	{
		printf("%c",G.g[i].vex);
		VexNode *p;
		p = G.g[i].next;
		while(p)
		{
			printf("->%c",p->vex);
			p = p->next;
		}
		printf("\n");
	}
}
int locateALG(ALG G, char c){
	int i = G.vn;
	
	for (; i >= 0 ; i--)
		if (G.g[i].vex == c)
			break;
	return i;
}

ALG craeteALG(){
	
	//init
	ALG G;
	G.vn = 0;
	G.en = 0;
	//enter vex
	printf("Please enter vexs:\n");
	while (1)
	{
		char vex;
		printf("No . %d  vex is : ",G.vn);
		scanf(" %c",&vex);
		if (vex == '*') break;
		G.g[G.vn].vex = vex;
		
		//init next
		G.g[G.vn].next = NULL;
		G.vn++;
	}
	
	//enter edge
	printf("Please enter edges : \n");
	while (1)
	{
	char hC , tC;
		int hP, tP;
		printf("No . %d edge is : ",G.en);
		scanf(" %c %c",&hC, &tC);
		
		//end enter
		if (hC == '*' || tC == '*')
			break;
		
		hP = locateALG(G,hC);
		tP = locateALG(G,tC);
		
		
		//entered invaild edge
		if (hP == -1 || tP == -1 || hP == tP)	
		{
			printf("invaild %d %d\n",hP, tP);
				continue;
		}
		//save edge
		VexNode *p;
		p = (VexNode*)malloc(sizeof(VexNode));
		p->vex = tC;
		p->next = G.g[hP].next;
		G.g[hP].next = p;
		
		G.en++;
	}
	return G;
}


int locateIncG(IncG G,char c){
	int pos = G.vn;
	for (; pos >= 0; pos--)
		if (G.vex[pos] == c)
			break;
	return pos;
}	

IncG createIncG(){
	//init G
	IncG G;
	G.vn = 0;
	G.en = 0;
	
	//enter vexs
	printf("Please enter vex:\n");
	while (1)
	{
		printf("No%d vex is : ",G.vn);
		scanf(" %c",&G.vex[G.vn]);
		if (G.vex[G.vn] == '*')break;	
		G.vn++;
	}
	
	//init Edge
	for (int i =0; i < G.vn; i++)
		for (int j =0; j < G.vn ; j ++)
			for (int k = 0; k < G.vn ; k ++)
			G.edge[i][j][k] = 0;
	//enter edge		
	printf("Please enter edges: \n");
	while(1){
		char hC , tC;
		int hP, tP;
		printf("No . %d edge is : ",G.en);
		scanf(" %c %c",&hC, &tC);
		
		//end enter
		if (hC == '*' || tC == '*')
			break;
		
		hP = locateIncG(G,hC);
		tP = locateIncG(G,tC);
		
		
		//entered invaild edge
		if (hP == -1 || tP == -1 || hP == tP)	
			continue;
			
		//save edge
		G.edge[G.en][hP][tP] = 1;
		G.en++;
	}
	return G;
}
int outDegreeAdjG(AdjG G,char c)
{
	int pos = locateAdjG(G,c);
	int degree = 0;
	for (int i =0; i < G.vn ; i++)
		if (G.edge[pos][i] != 0)
			degree++;
	return degree;
}
int inDegreeAdjG(AdjG G,char c)
{
	int pos = locateAdjG(G,c);
	int degree = 0;
	for (int i =0; i < G.vn ; i++)
		if (G.edge[i][pos] != 0)
			degree++;
	return degree;
}
AdjG createAdjG(){
	//init G
	AdjG G;
	G.vn = 0;
	G.en = 0;


	//enter vexs
	printf("Please enter vexs:\n");
	while(1)
	{
		printf("No.%d vex is : ",G.vn);
		scanf(" %c",&G.vex[G.vn]);
		if (G.vex[G.vn] == '*') break;
		G.vn++;
	}
	
	//init Edge
	for (int i =0; i < G.vn; i++)
		for (int j =0; j < G.vn ; j ++)
			G.edge[i][j] = 0;
	
	//enter edges
	printf("Please enter edegs : \n");
	while (1)
	{
		char head, tail;
		int weight;
		printf("No.%d edges is : ",G.en);
		scanf(" %c %c %d",&head, &tail,&weight);
		
		//end enter
		if (head == '*' || tail == '*')
			break;
		
		int hPos, tPos;
		hPos = locateAdjG(G,head);
		tPos = locateAdjG(G,tail);
		
		
		//entered invaild edge
		if (hPos == -1 || tPos == -1 || hPos == tPos)	
			continue;
			
		//save edge
		G.edge[hPos][tPos] = weight;
		G.en++;
	}
	printf("Enter AjdG end;\n");
	return G;
}

int locateAdjG(AdjG G, char c)
{	
	int i = G.vn;
	for (; i >= 0; i --)
		if (G.vex[i] == c)
			break;
	return i;
}



int main(void)
{
	
	ALG alG = craeteALG();
	
	printALG(alG);
	
	IncG incG = createIncG();
	
	
	//
	AdjG G = createAdjG();
	for (int i =0; i < G.vn ; i++)
	{
		printf("%c %d %d\n",G.vex[i],outDegreeAdjG(G,G.vex[i]),inDegreeAdjG(G,G.vex[i]));
	}
	return 0;
}