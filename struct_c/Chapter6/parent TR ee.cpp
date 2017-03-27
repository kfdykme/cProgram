#include <stdio.h>

#define MAXTREESIZE 100

struct PTreeNode{
	int data;
	int parent;
};
typedef struct PTreeNode;
struct PTree{
	PTreeNode nodes[MAXTREESIZE];
	int n;
};
typedef struct PTree;

struct ChNode{
	int child;
	struct ChNode *next;
};
typedef struct ChNode ChNode;

struct PTNode{
	int data;
	ChNode *firstChild;
};

typedef struct PTNode PTNode;

struct ChTree{
	PTNode nodes[MAXTREESIZE];
	int n, root;
};
typedef struct ChTree ChTree;

struct CSnode{
	int data;
	struct CSnode *firstcChild,*nextSlibing;
};

typedef struct CSNode CSNode;

int main(void)
{

		
	return 0;
}