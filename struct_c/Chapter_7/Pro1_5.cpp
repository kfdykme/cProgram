#include <stdio.h>
#include <stdlib.h>

#define M 1000

typedef struct node{
	char vex;
	struct node *next;
} VexNode;

typedef VexNode ALGlist[M];

typedef struct {
	ALGlist list;
	int vn,en;
} ALG;

typedef struct queenNode{
	int data;
	struct queenNode *next;
} QueenNode;

typedef struct queen{
	QueenNode *first;
	QueenNode *last;
} Queen;

void initQueen(Queen *Q){
	QueenNode* q =  (QueenNode*)malloc(sizeof(QueenNode));
	q->next = NULL;
	Q->first = Q->last = q;
}

void EnQueen(Queen *Q, int e)
{
	QueenNode *p;
	p = (QueenNode*)malloc(sizeof(QueenNode));
	
	p->data = e;
	p->next = NULL;
	Q->last->next = p;
	Q->last = p;	
	
	printf("En %d\n",e);
}

int isQueenEmpty(Queen *Q)
{
	if (Q->first == Q->last)
	{
		printf("Empty\n");
		return 1;
	}
	else 
		return 0;
}

int DeQueen(Queen *Q)
{
	
	if (isQueenEmpty(Q))
		exit(0);
		
	QueenNode *p;
	
	 p = Q->first->next;
	 Q->first->next = p->next;
	 int x = p->data;
	 free(p);
	 
	 if (Q->first->next == NULL)
	 	Q->first = Q->last;
	 	
	 printf("De %d\n",x);
	 return x;
	 
	
}

int locateALG(ALG G,char c)
{
	int i;
	for (i = G.vn; i >=0; i--)
		if (G.list[i].vex == c)
			break;
	
	return i;
}

ALG createALG()
{
	//inti
	ALG G;
	G.vn  = 0;
	G.en = 0;
	
	
	//enter vex
	printf("Enter vexs : \n");
	while(1)
	{
		char vex;
		printf("No.%d vex is : ",G.vn);
		scanf(" %c",&vex);
		
		if (vex == '*')
			break;
		
		G.list[G.vn].vex = vex;
		G.vn++;
	}
	
	//enter edge
	printf("Enter edges : \n");
	while (1)
	{
		char head, tail;
		printf("No.%d edges is : ",G.en);
		scanf(" %c %c",&head, &tail);
		
		if (head == '*' || tail == '*' ) break;
		
		int h , t;
		h = locateALG(G,head);
		t = locateALG(G,tail);
		
		if ( h == -1 || t == -1 || h == t) continue;
		
		VexNode *p;
		p = (VexNode*)malloc(sizeof(VexNode));
		p->vex = head;
		p->next = G.list[t].next;
		G.list[t].next = p;
		p = (VexNode*)malloc(sizeof(VexNode));
		p->vex = tail;
		p->next = G.list[h].next;
		G.list[h].next = p;
		G.en++;
	}
	
	
	return G;
}


void printfALG(ALG G)
{
	printf("print ALG\n");
	
	printf("It has %d vex(s), and %d edge(s)\n",G.vn, G.en);
	
	for (int i =0; i < G.vn; i++)
	{
		printf(" %c \n",G.list[i].vex);
		VexNode * e;
		e =G.list[i].next;
		while(e){
			printf("-> %c\n",e->vex);
			e = e->next;
		}
		printf("\n");
		
	}
	printf("\n");
	
	printf("printf end\n");
}

int visited[M] = {0};
Queen Q;

void BFS(ALG G,char c)
{
	initQueen(&Q);
	
	for (int i =0; i <=G.vn ; i++)
		visited[i] = 0;
	
	int pos = locateALG(G,c);
	if (pos == -1) return ;
	printf("%d - %c\n",pos,c);
	visited[pos] = 1;
	EnQueen(&Q,pos);
	
	while(!isQueenEmpty(&Q))
	{
		int i = DeQueen(&Q);
		VexNode *p;
		p = G.list[i].next;
				
		while (p)
		{
			
			char vex = p->vex;
			int j = locateALG(G,vex);
			//printf("has %c\t",vex);
			
			if (!visited[j])
			{
				EnQueen(&Q,j);
				visited[j] = 1;
			}
			p = p->next;
		}
		
	}
	//printf("De->&d",DeQueen(&Q));	
}
		

int main( void )
{
	ALG G = createALG();
	printfALG(G);
	

	//EnQueen(&Q,locateALG(G,'a'));
	BFS(G,'a');
	//Queen Q;

	initQueen(&Q);
	for (int i = 0 ; i < 8 ; i++)
		EnQueen(&Q,i);
	while (!isQueenEmpty(&Q))
		printf("%d-",DeQueen(&Q));

	return 0;
}