#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#include "stack.h"

#include "stack.c"


int do_calc(int n,char mark);

int main(void){
	char ch;
	int n;
	
	printf("Enter an RPN expression:");
	
	for(;;){
		scanf(" %c",&ch);
		//printf("\nstack[%d] : %d ch = %d",top,stack[top],ch);
		
		switch(ch){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				push(ch - 48);
				break;
			case '+':
			case '/':
			case '*':
			case '-':
				do_calc(pop(),ch);
				break;
			case '=':
				printf("Valur of expressing : %d",pop());
				printf("\nEnter an RPN expression:");
			case ' ': case '\n':
				break;
			default: 
				return 0;;
		}
			
	}  
	
}

int do_calc(int n, char mark){
	int i;
	switch(mark){
		case '+':
			i = pop() + n;
			push(i);
			break;
		case '-':
			i = pop() - n;
			push(i);
			break;
		case '*':
			i = pop() * n;
			push(i);
			break;
		case '/':
			i = pop() / n;
			push(i);
			break;
	}
}
	


