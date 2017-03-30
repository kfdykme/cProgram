#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode{
	
	struct treeNode *p,*lc, *rc;
	char data ;
} Tree;


Tree TreeInit(){
	Tree a;
	a.p = NULL;
	return a;
}
/*
1
2          3
0   4      0     0
00 50   00  0 0
*/

/*
	注意函数内的内存分配问题
	有的不懂 摸索着用先
*/

char* TreeCreatFromInts(Tree *root,char * datas,int mG, int cG){
	root->data = *datas;
//	printf("+%c+\t",*datas);
	
			
	root->lc = (Tree*)malloc(sizeof(Tree));
	root->rc = (Tree*)malloc(sizeof(Tree));
	
	if(cG<=mG)
	{		
	
	//	printf("left %d %d\n",cG, mG);
		datas = TreeCreatFromInts(
				root->lc,
				++datas,
				mG,
				cG+1);				
		printf("right %d %d\n",cG, mG);
		datas = TreeCreatFromInts(
				root->rc,
				++datas,
				mG,
				cG+1);
	}
	
	
	
	return datas;
}

void PreOrderTraverse(Tree *t)
{
	if(t !=NULL)
	{
		printf("%c",t->data);
		if(t->lc != NULL)
		PreOrderTraverse(t->lc);
		if(t->rc != NULL)
		PreOrderTraverse(t->rc);
	}
}

int main(void){
	
	Tree root;

	root = TreeInit();	

	int data[15] = {1,2,0,4,0,0,5, 0,3,0,0,0,0,0,0};
	char datas[16] =
	 "120400503000000";		
	TreeCreatFromInts(&root,datas,4,2);
	
	PreOrderTraverse(&root);
	return 0;
}