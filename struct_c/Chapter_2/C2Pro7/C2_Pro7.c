//7. 已知由单链表表示的线性表中，含有3类字符的数据元素（如字母字符、数字字符和其他字符），试编程实现：构造柱个以循环链表表示的线性表，使每个表中只含有同一类的字符，且利用原表中的节点空间作为这3个表的节点空间，头结点可另辟空间。

//part1. 构建链表
//part2. 构建循环链表
//part3. 将原始表以三个循环链表表示

#include <stdio.h>

#include "circlelinkedlistchar.h"

int main(void){
//part1.
	char a[50] = "1234567890qwertyuiopasdfghjklzxcvbnm<>?:|_+";
	
	CircleLinkedList mC = CircleLinkedListCreate(a,43);
	
	printfCircleLinkedList(mC);
//part2.
	
	CircleLinkedList Ln,La,Lo, temp;
	temp = mC;
	Ln = CircleLinkedListCreate("null",0);
	La = CircleLinkedListCreate("null",0);
	Lo = CircleLinkedListCreate("null",0);
	char e;
	while (temp->next != mC){
		e = temp->data;
		if ( e <= '9' && e >= '0'){	
			CircleLinkedListInsert(Ln, Ln,e);
		} else if ( e <= 'z' && e >= 'a'){
			CircleLinkedListInsert(La, La,e);
		} else {
			CircleLinkedListInsert(Lo, Lo,e);
		}
		temp = temp->next;
	}
	
	printfCircleLinkedList(Ln);
	printfCircleLinkedList(La);
	printfCircleLinkedList(Lo);
	
	return 0;
}