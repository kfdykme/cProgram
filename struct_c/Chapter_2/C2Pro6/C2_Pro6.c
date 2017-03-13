//6.

#include <stdio.h>
#include "circlelinkedlist.h"

int main(void){
	
	int a[10] ={1,2,3,4,5,6,7,8,9};
	
	CircleLinkedList mC;
	
	mC = CircleLinkedListCreate(a,10);

	printfCircleLinkedList(mC);
		
	CircleLinkedNode *s = CircleLinkedListLocate(mC,3);
	CircleLinkedNode *tempNode ;
	tempNode = s;
	CircleLinkedNode *tempNext = s->next;
	while (tempNext->next != s){
		tempNext = tempNext ->next;
		tempNode = tempNode->next;
	}
	free(tempNext);
	tempNode->next = s;
	printfCircleLinkedList(mC);			
	return 0;
}