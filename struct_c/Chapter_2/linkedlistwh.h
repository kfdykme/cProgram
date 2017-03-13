
// 单链表

#include <stdio.h>
#include <stdlib.h>


struct IntLinkedList{
	int data;
	struct IntLinkedList * next;
};

typedef struct IntLinkedList LinkedNode;
typedef struct IntLinkedList *LinkedList;


void LinkedListInit(LinkedList L);

int LinkedListLength(LinkedList L);

LinkedNode * LinkedListGetByLocate(LinkedList L, int i);

LinkedNode * LinkedListGetByElement(LinkedList L, int e);

LinkedNode *LinkedListLocate(LinkedList L, int e);

void LinkedListInsert(LinkedList L, LinkedList p, int e);

void LinkedListDel(LinkedList L, int e);

LinkedList LinkedListCreate(int array[], int length);

LinkedList LinkedListCreateFromBack(int array[], int length);

void printfLinkedList(LinkedList mL);



void LinkedListInit(LinkedList L){
	
	L = (LinkedNode * )malloc(sizeof(LinkedNode));
	if (L == NULL){
		printf("申请空间失败!\n");
		exit(0);
	}
	L -> next = NULL;
}

int LinkedListLength(LinkedList L){
	LinkedNode *p;
	p = L -> next;
	int j = 0;
	while (p != NULL){
		j++;
		p = p -> next;
		
	}
	
	return j;
}

LinkedNode * LinkedListGetByLocate(LinkedList L, int i){
	LinkedNode *p;
	p = L-> next;
	int j = 1;
	while ((p!= NULL) && (j < i)){
		p = p -> next;
		j++;
	}
	return p;
}


LinkedNode* LinkedListGetByElement(LinkedList L, int e){
	LinkedList p;
	p = L->next;
	while((p!=NULL)&& (p->data != e)){
		p = p->next;
	}
	
	return p;
}

LinkedNode * LinkedListLocate(LinkedList L, int e){
	LinkedNode *p = L->next;
	int j = 1;
	
	while((p!=NULL) && (p->data != e)){
		p = p -> next;
	}
	
	return p;
}

void LinkedListInsert(LinkedList L, LinkedList p, int e){
	LinkedNode *q = (LinkedNode *)malloc(sizeof(LinkedNode));
	if(q == NULL){
		printf("申请空间失败");
		exit(0);
	}
	q->data = e;
	
	LinkedList pre = L;
	
	while ((pre != NULL )&& (pre->next != p))
		pre = pre-> next;
	
	q->next = pre->next;
	pre->next = q;
	
	
	
}
	
void LinkedListDel(LinkedList L, int e){
	LinkedList pre = L;
	while ((pre->next != NULL) && (pre->next->data != e))
		pre= pre->next;
	LinkedNode *p = pre->next;
	
	if (p != NULL){
		pre -> next = p -> next;
		free(p);
	}
}

LinkedList LinkedListCreateFromBack(int array[], int length){
	LinkedList L = (LinkedList )malloc(sizeof(LinkedNode));
	
	if ( L == NULL){
		printf("申请空间失败");
		exit(0);
	}
	L->next = NULL;
	
	
	for (int i = length-1; i >= 0; i--){
		 LinkedList p = (LinkedList)malloc(sizeof(LinkedNode));
		if(p ==NULL){
			printf("申请空间失败");
			exit(0);
		}
		
		p->data = array[i];
		p -> next = L -> next;
		L -> next = p;
		}
	
	return L;
}

LinkedList LinkedListCreate(int array[], int length){
	LinkedList L = (LinkedList )malloc(sizeof(LinkedNode));
	
	if ( L == NULL){
		printf("申请空间失败");
		exit(0);
	}
	L->next = NULL;
	
	
	for (int i = 0; i < length; i++){
		 LinkedList p = (LinkedList)malloc(sizeof(LinkedNode));
		if(p ==NULL){
			printf("申请空间失败");
			exit(0);
		}
		
		p->data = array[i];
		p -> next = L -> next;
		L -> next = p;
		}
	
	return L;
}


void printfLinkedList(LinkedList mL){
	LinkedList L = mL;
	printf("\n------ --------\n"
	       "\t\t\tAll data\n");
	while (L -> next != NULL){
		printf("%d\n",L->next->data); 
		L = L->next;
	}
	printf("----- ------\n");
}
	
	
	