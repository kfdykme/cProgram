#include <stdio.h>

#define MAXSIZE 1000

struct TreeNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
};

typedef struct TreeNode HFTreeNode;
typedef HFTreeNode HuffmanTree;

void Select(HuffmanTree *HT, int g, int *s1, int *s2);
void CreateHuffmanTree(HuffmanTree T[],int n);

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
		scanf("%d",&T[i].weight);	
	}
	
	for (i = n; i <m-1;i++)
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
		if ((HT[j].weight <= HT[k].weight)
			&& (HT[j].parent == 0))
			*s1=j;
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
		if((HT[n].weight<HT[m].weight)
			&&(HT[n].parent == 0)
			&&(n != *s1))
				*s2 =n;
	}
}

int main(void){
	
	return 0;
}