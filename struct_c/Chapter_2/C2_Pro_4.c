//4. 实现单链表求表长操作

#include <stdio.h>

#include "linkedList.h"
int main(void){
	
	LinkedList mL;
	int a[3] = {1,2,3};
	mL = LinkedListWHCreate1(mL,a,3);
	
	printfLinkedListWH(mL);
	int i = LinkedListWHLength(mL);
	printf("\n%d\n",i);
	return 0;
}