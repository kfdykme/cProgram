//由前中序序列的字符数组构造二叉树

#include <stdio.h>
#include <string.h>
#define M 100
typedef struct node{
	char vex;
	struct node *p,*r,*l;
} TreeNode;



TreeNode readStrings(char *fS, char *mS ,TreeNode *P);
TreeNode locate(TreeNode T,char c);
void printfTree(TreeNode T);

void printfTree(TreeNode T)
{
	if (T.l != NULL && T.r != NULL)
	printf("%c-",T.vex);
	if (T.l != NULL) 
		printfTree(*T.l);
	if (T.r != NULL) 
		printfTree(*T.r);
	
}

TreeNode readStrings(char *fS, char *mS,TreeNode *P)
{
	//init
	TreeNode T;
	T.p = P;
	T.r = NULL;
	T.l = NULL;
	
	//1。在前序序列中找到根节点
	char root = fS[0];
	if (fS[0] != '\0')
	 root = fS[0];
	else 
	{
	//	printf("error fs\n");
		return T;
	}
	printf("\nroot is %c\n",root);
	T.vex = root;
	//2。在中序序列中找到根节点
	int rootPos = 0;
	while (*(mS+rootPos) !='\0')
	{
		if (*(mS+rootPos) == root)
			break;
		rootPos++;
	}
/*	
	if (*(mS+rootPos) == '\0')
	{
			printf("error mS\n");
		return T;
	}
	*/
	//3。在中序序列中分出次级的两个中序
	char clmS[M], crmS[M];
	strcpy(clmS,mS);
	*(clmS+rootPos) = '\0';
	strcpy(crmS,mS+rootPos+1);
	printf("clmS %s, crmS %s\n",clmS,crmS);
		//4。依据长度在前序中分出两个次级的前序序列
	char clfS[M],crfS[M];
	strcpy(clfS,fS+1);
	*(clfS+strlen(clmS)) = '\0';
	strcpy(crfS,fS+strlen(clfS)+1);
	printf("clfS %s, crfS %s\n",clfS,crfS);
	
	//5。分别递归分析两个次级的前序中序，得到左右子树
	TreeNode *left,*right;
	left = (TreeNode*)malloc(sizeof(TreeNode));
	*left = readStrings(clfS,clmS,&T);
//	printf ("left to right\n");
	right = (TreeNode*)malloc(sizeof(TreeNode));
	*right = readStrings(crfS,crmS,&T);
	T.l = left;
	T.r = right;
	//return 
	return T;
}


int main(void)
{
	char fS[M] ="12453";
	char mS[M]= "25413";
	TreeNode T = readStrings(fS,mS,NULL);
	printfTree(T);
	return 0;
}