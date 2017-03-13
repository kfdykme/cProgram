//3.若在一个递增有序的线性表中，有数值相同的元素存在。试分别用顺序表和单链表作为存储结构，实现去掉相同元素的操作，然后分析算法的时间复杂度。

//section1 Seqlist
//part1. create a seqlist with currect elements;
//part2. operate the datas;
//section2 linkedlist
#include <stdio.h>
#include "linkedlist.h"
#include "seqlist.h"

int main(void){
//section1
//part1.
	printf("\n\n\t\t\tSeqList\n\n");
	 int mEles[10] = {1,1,1,1,2,3,4,5,5,5};
	
	SeqList mSl ;
	SeqListCreat(&mSl,
				mEles,
				sizeof(mEles)/sizeof(int));
	SeqListTraverse(mSl);
	
//part2.	
	 int nEles[SeqListLength(mSl)];
	 int i, j, k, e;
	 
	 for (i = 1, j = 0; i <= SeqListLength(mSl); i++){
	 		e = SeqListGet(mSl, i);
	 		
	 		if (i == 1){
	 			nEles[j++] = e;
	 		} else {
	 			for (k = 0; k < j; k++){
	 				if(nEles[k] == e){
	 					break;
	 				} else if (k == j -1){
	 					nEles[j++] = e;
	 				}
	 			}
	 		}
	 }
	SeqListInit(&mSl);
	SeqListCreat(&mSl,nEles,j);
	SeqListTraverse(mSl);
	
//section2
	printf("\n\n\t\t\tLinkedList\n\n");
//part1.
	int mLinkedEles[10] = {3,42,32,43,42,3,3,4,4,1};
	LinkedList mLl;
	mLl = LinkedListWHCreate1(mLl,
					mLinkedEles,
					10);				
	printfLinkedListWH(mLl);
//part2.	
	{
		int nLinkedEles[10];
		int i, j, k, e;
		for (i = 1, j = 0; i <= LinkedListWHLength(mLl); i++){
	 		e = LinkedListWHGet(mLl,i) ->data;
	 		if (i == 1){
	 			nLinkedEles[j++] = e;
	 		} else {
	 			for (k = 0; k < j; k++){
	 				if (nLinkedEles[k] == e){
	 					break;
	 				} else if (k == j -1){
	 					nLinkedEles[j++] = e;
	 				}
	 			}
	 		}
		 }
		 
		 LinkedListWHInit(mLl);
		 mLl = LinkedListWHCreate1(mLl,
		 	nLinkedEles,
		 	j);
		 printfLinkedListWH(mLl);
	}
	
	
	//time n * n
	
	// may be have anther easy method
	// Should I go to listen teacher's class?
	return 0;
}
