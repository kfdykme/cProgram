//1.编写出打印一个单链表所有元素的的程序

//1. 单链表

//2. 打印单链表

#include <stdio.h>
#include <stdlib.h>

struct pro1_single_list{
	int data;
	struct pro1_single_list * next;
};

typedef struct pro1_single_list MList;
typedef struct pro1_single_list *LinkedList;

void LinkedListInitWH(LinkedList L){
	
	L = (MList * )malloc(sizeof(MList));
	if (L == NULL){
		printf("申请空间失败!\n");
		exit(0);
	}
	L -> next = NULL;
}

int LinkedListWHLength(LinkedList L){
	MList *p;
	p = L -> next;
	int j = 0;
	while (p != NULL){
		j++;
		p = p -> next;
	}
	return j;
}

LinkedList LinkedListWHGet(LinkedList L, int i){
	MList *p;
	p = L-> next;
	int j = 1;
	while ((p!= NULL) && (j < i)){
		p = p -> next;
		j++;
	}
	
	return p;
}

MList * LinkedListWHLocate(LinkedList L, int e){
	MList *p = L->next;
	int j = 1;
	
	while((p!=NULL) && (p->data != e)){
		p = p -> next;
	}
	
	return p;
}

void LinkedListWHInsert(LinkedList L, LinkedList p, int e){
	MList *q = (MList *)malloc(sizeof(MList));
	if(q == NULL){
		printf("申请空间失败");
		exit(0);
	}
	q->data = e;
	
	LinkedList pre = L;
	while ((pre != NULL )&& (pre->next != p)){
		pre = pre-> next;
	
	q->next = pre->next;
	pre->next = q;
	}
}
	
void LInkedListWHDel(LinkedList L, int e){
	LinkedList pre = L;
	while ((pre->next != NULL) && (pre->next->data != e))
		pre= pre->next;
	MList *p = pre->next;
	
	if (p != NULL){
		pre -> next = p -> next;
		free(p);
	}
}

void LinkedListWHCreate1(LinkedList L, int array[], int length){
	L = (MList * )malloc(sizeof(MList));
	
	if ( L == NULL){
		printf("申请空间失败");
		exit(0);
	}
	L->next = NULL;
	
	for (int i = 0; i < length; i++){
		MList *p = (MList * )malloc(sizeof(MList));
		if(p ==NULL){
			printf("申请空间失败");
			exit(0);
		}
		
		p->data = array[i];
		p->next = L->next;
		L->next = p;
	}
}

int main(void){
	
	return 0;
	}

