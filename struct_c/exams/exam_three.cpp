


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 100


#define infinity 1000

typedef struct {
	char vex[M];
	int edge[M][M];	
	int vn ;
	int en;
} AdjGraph;


typedef struct {
	int h;
	int t;
	int w;
} Edge;

int locate(AdjGraph G,char vex)
{
	for (int i =0; i < G.vn; i++)
		if (G.vex[i] == vex)
			return i;
	//printf("Can't find.\n");
	return -1;
}

int isLianTong(AdjGraph G,char tc,char hc)
{
	int t, h;
	t = locate(G,tc);
	h = locate(G,hc);
	if(t == -1 || h == -1) return 0;
	
	int tempt = t;
	
	int is = 0;	
		
		for (int i =0; i < G.vn; i++)
		{
	
			if(G.edge[tempt][i] != infinity)
			{
	 			tempt = i;	 			
			}
			is += isLianTong(G,tempt,h);
			if ( tempt == h) is++;
		}
		
	return is;
	
}

void MiniSpanTree_Kruskal(AdjGraph G)
{
	Edge E[G.en];
	int En = 0;
	int min = infinity;
	int max = 0;
	for (int j = 0 ; j < G.vn; j++)
	{
		
		for(int i = 0 ;i < G.vn;i++)
			if(G.edge[j][i] != infinity)
			{
				int t = G.edge[j][i];
				printf("%c -> %c [%d]\n",G.vex[j],G.vex[i],t);

				if (min > t){
				printf("Bigger\n");
				min = t;	
				} 
				if(max < t){
					max =t;
				}
				
				E[En].t = G.vex[j];
				E[En].h = G.vex[i];
				E[En].w= G.edge[j][i];
				En++;
			}
			
	}
	
	printf("min %d max %d",min,max);
	
	Edge E2[En];
	int En2 = 0;
	while(min <= max)
	{
		for (int i = 0; i < En; i++)
		{
			if (E[i].w == min)
			{
				
				E2[En2] = E[i];
				En2++;
			}
		}
		min++;
		
	}
	
	AdjGraph G2 = G;
	
	for (int j = 0 ; j < G2.vn; j++)
		for(int i = 0 ;i < G2.vn;i++)
		G2.edge[j][i] = infinity;
		
	int sum = 0;	
	for (int i = 0; i < G2.vn; i++ )
	{
		printf("\n%c ->%c(%d)",E2[i].t,E2[i].h,E2[i].w); 
		if(!isLianTong(G2,E2[i].t,E2[i].h))
		{ 
			G2.edge[locate(G2,E2[i].t)][locate(G2,E2[i].h)]= E2[i].w;
			sum += E2[i].w;
		}
	}
	
	
	printf("\nG2\n");
	
	for (int j = 0 ; j < G2.vn; j++)
		for(int i = 0 ;i < G2.vn;i++)
			if(G2.edge[j][i] != infinity)
				printf("%c -> %c [%d]\n",G2.vex[j],G2.vex[i],G2.edge[j][i]);

	
	printf("lowcost %d",sum);
	
}

int main(void){
	
	// init
	AdjGraph G;
	
	
	G.vn = 0;
	G.en = 14;	
	printf("enter vex:\n");
	while(1){
		printf("No %d : ",G.vn);
		G.vex[G.vn] = getchar();
		getchar();
		if(G.vex[G.vn] == '0') break;
		G.vn++;
		
	}
 
			
	
	 
	for (int j = 0 ; j < G.vn; j++)
		for(int i = 0 ;i < G.vn;i++)
			G.edge[j][i] = infinity;
	
	while(1){
		char tc,hc;
		int w,t,h;
		printf("Input tail head wight: ");
		scanf(" %c %c %d",&tc,&hc,&w);
		t = locate(G,tc);
		h = locate(G,hc);
		if(w == 0) break;
		
		G.edge[t][h] = w;
		G.en++;
		
	}
	
	/*
	G.edge[0][1] = 4;
	G.edge[0][2] = 7;
	G.edge[1][2] = 3;
	G.edge[1][3] = 6;
	G.edge[1][4] = 8;
	G.edge[2][4] = 11;
	G.edge[2][5] = 9;
	G.edge[3][4] = 15;
	G.edge[3][6] = 10;
	G.edge[4][5] = 1;
	G.edge[4][6] = 5;
	G.edge[4][7] = 14;
	G.edge[5][7] = 12;
	G.edge[6][7] = 2;
*/
	MiniSpanTree_Kruskal(G);
	
	
	
	 
	return 0;
} 
