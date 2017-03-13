//4. 		

#include <stdio.h>
#include "linkedlistwh.h"
//part 1 create a increseing? linkedlist
//part 2 scanf min & max
//part 3 delete 

int main(void){

	
//part1	
	int a[20];
	int i, min, max;
	for(i = 0; i < 20; i++){
		a[i] = i+20;
	}
	
	LinkedList mL;
	
	mL = LinkedListCreateFromBack(a,20);
	
	printfLinkedList(mL);


//part2
	
	printf("min: ");
	scanf("%d",&min);
	printf("max: ");
	scanf("%d", &max);
	
//part3
	{
		LinkedNode *before, *mNext;
	
		before = LinkedListGetByElement(mL,min);
		mNext = LinkedListGetByElement(mL,max);
		
		while (before->next != mNext){
			before->next = before->next->next;
			free(before->next);
		}		
		printfLinkedList(mL);
		}
		
	
	return 0;
}