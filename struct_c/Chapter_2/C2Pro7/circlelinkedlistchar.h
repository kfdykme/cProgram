
//单循环链表

#include <stdio.h>
#include <stdlib.h>


struct charCircleLinkedList{
	char data;
	struct charCircleLinkedList * next;
};

typedef struct charCircleLinkedList CircleLinkedNode;
typedef struct charCircleLinkedList *CircleLinkedList;


CircleLinkedList CircleLinkedListCreateFromBack(int array[], int length){
	CircleLinkedList L = (CircleLinkedList )malloc(sizeof(CircleLinkedNode));
	
	if ( L == NULL){
		printf("申请空间失败");
		exit(0);
	}
	L->next = L;
	
		
		
	for (int i = length-1; i >= 0; i--){
		 CircleLinkedList p = (CircleLinkedList)malloc(sizeof(CircleLinkedNode));
		if(p ==NULL){
			printf("申请空间失败");
			exit(0);
		}
		
		p->data = array[i];
		if (!i){
			L = p;
			p->next = p;
		} else{
			p->next = L->next;
			L->next = p;
		}
	}
	
	return L;
}

CircleLinkedList CircleLinkedListCreate(char array[], int length){
	CircleLinkedList L = (CircleLinkedList )malloc(sizeof(CircleLinkedNode));
	
	if ( L == NULL){
		printf("申请空间失败");
		exit(0);
	}
	L->next = L;
	
	
	for (int i = 0; i < length; i++){
		 CircleLinkedList p = (CircleLinkedList)malloc(sizeof(CircleLinkedNode));
		
		if(p ==NULL){
			printf("申请空间失败");
			exit(0);
		}
		
		p->data = array[i];
		if (!i){
			L = p;
			p->next = p;
		} else{
			p->next = L->next;
			L->next = p;
		}
		}
	
	return L;
}



int CircleLinkedListLength(CircleLinkedList L){
	CircleLinkedNode *p;
	p = L ;
	int j = 1;
	
	
	
	while (p->next != L){
		j++;
		p = p -> next;
	}
	
	return j;
}



CircleLinkedNode* CircleLinkedListGetByElement(CircleLinkedList L, char e){
	CircleLinkedList p;
	p = L;
	while((p->next!=L)&& (p->data != e)){
		p = p->next;
	}
	
	return p;
}

CircleLinkedNode * CircleLinkedListLocate(CircleLinkedList L, char e){
	CircleLinkedNode *p = L;
	
	while((p->next != L ) && (p->data != e)){
		p = p -> next;
	}
	
	return p;
}

void CircleLinkedListInsert(CircleLinkedList L, CircleLinkedList p,char e){
	
	
	CircleLinkedNode *q = (CircleLinkedNode *)malloc(sizeof(CircleLinkedNode *));
	if(q == NULL){
		printf("申请空间失败");
		exit(0);
	}
	q->data = e;
		
	CircleLinkedNode *pre = L;
	
	while((pre->next != L ) && (pre->next != p)){
		pre = pre -> next;
	}	
	
	q->next  = p;
	pre -> next = q;
	
}
	
void CircleLinkedListDel(CircleLinkedList L, char e){
	CircleLinkedList pre = L;
	while ((pre->next != L) && (pre->next->data != e))
		pre= pre->next;
	CircleLinkedNode *p = pre->next;
	
	if (p != L){
		pre -> next = p -> next;
		free(p);
	}
}


void printfCircleLinkedList(CircleLinkedList mL){
	CircleLinkedList L = mL;
	printf("\n------ --------\n"
	       "\t\t\tAll data\n");
	do{
		printf("%c\n",L->next->data); 
		L = L->next;
	}while (L != mL);
	printf("----- ------\n");
}
	
	
	