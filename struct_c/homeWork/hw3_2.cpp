#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

//save HuffmanTree's vex number
int number;


struct TreeNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char vex;
};

typedef struct TreeNode HFTreeNode;
typedef HFTreeNode HuffmanTree;

struct codeNode{
	char vex;
	char *bits;
};

typedef struct codeNode CodeNode;
typedef CodeNode *HuffmanCode;

void Select(HuffmanTree *HT, int g, int *s1, int *s2);
void CreateHuffmanTree(HuffmanTree T[],int n);
void printfHuffmanTree(HuffmanTree *T);
void charSetHuffmanEncoding(HuffmanTree *T,HuffmanCode C);

void charSetHuffmanEncoding(HuffmanTree *T, HuffmanCode C)
{
	int child,parent;
	char *code;
	code = (char*)malloc(sizeof(char)*(number+1));
	code[number] = '\0';

	for ( int i = 1; ; i++)
	{

		if (T[i].parent == 0) break;
		C[i].vex = T[i].vex;
		int start = number;
		child = i;
		while ((parent = T[child].parent) != 0)
		{
			if (T[parent].lchild == child)
				code[--start] = '0';
			else if (T[parent].rchild == child)
				code[--start] = '1';
			child = parent;

		}
		C[i].bits = (char*)malloc(sizeof(code[start]));
		strcpy(C[i].bits,code+start);
	}
}


int main(void){

	HuffmanTree HT[MAXSIZE];
	printf("enter vex number :");
	scanf("%d",&number);
	CreateHuffmanTree(HT,number+1);

	printfHuffmanTree(HT);
		return 0;
}

void printfHuffmanTree(HuffmanTree *T){
	for (int i =1 ;  ;i++){

	if (T[i].vex == '\0')
		T[i].vex = 'X';
		printf("No.%d node vex: %c w:%d p:%d l:%d r:%d \n",i,T[i].vex,T[i].weight, T[i].parent, T[i].lchild, T[i].rchild);
		if(!T[i].parent)
			break;
	}

	printf("Encoding start!\n");

	HuffmanCode C;
	C = (CodeNode*)malloc(sizeof(CodeNode) * number+1);
	charSetHuffmanEncoding(T, C);

	printf("Encoding end!\n");
	for (int i = 1; i <= number; i++)
	{
		printf("%c %s\n",C[i].vex, C[i].bits);
	}


}


void CreateHuffmanTree(HuffmanTree T[], int n){
	int i, p1, p2;
	int m;
	if (n <1)
		return ;

	m = 2*n;
	for (i =1;i<m;i++)
	{
		T[i].parent =0;
		T[i].lchild =0;
		T[i].rchild =0;
		T[i].weight =0;
	}

	for (i =1;i<n;i++)
	{
		scanf(" %c %d",&T[i].vex,&T[i].weight);
	}

	for (i = n; i <m-2;i++)
	{
		Select(T,i-1,&p1,&p2);
		T[p1].parent = i;
		T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight+T[p2].weight;
	}
}

void Select(HuffmanTree *HT,int g, int *s1, int *s2){
	int j,k,m,n;
	for (k = 1; k <= g; k++)
	{
		if(HT[k].parent == 0)
		{
			*s1 = k;
			break;
		}
	}

	for (j =1;j<=g;j++)
	{
		if ((HT[j].weight <= HT[*s1].weight)
			&& (HT[j].parent == 0))
		{
			*s1 = j;

		}
	}

	for (m = 1; m <=g;m++)
	{
		if ((HT[m].parent == 0)
			&& (m != *s1))
		{
			*s2=m;
			break;
		}
	}

	for (n=1; n<= g;n++)
	{
		if((HT[n].weight<HT[*s2].weight)
			&&(HT[n].parent == 0)
			&&(n != *s1))
				*s2 =n;
	}
}
