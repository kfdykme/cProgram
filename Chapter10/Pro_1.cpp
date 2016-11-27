#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100


char contents[STACK_SIZE];
int top = 0;

void stackOverflow(void){
	printf("\nOver flow!");
	exit(0);
	}

bool stackUnderflow(void){
	return false;
}

void makeEmpty(void){
	top = 0;
	} 
	
bool isEmpty(void){
	return top == 0;
}

bool isFull(void){
	return top == STACK_SIZE;
}

void push(char i){
	if (isFull()){
	 stackOverflow();
	}else{
	contents[top++] = i;
	}
}

char pop(void){
	if(isEmpty())
		stackUnderflow();
	else 
		return contents[--top];
	}


void print_not_ested(){
	printf("Parenteses/braces are not ested properly."); 
	}

void print_ested(){
	printf("Parenteses/braces are ested properly."); 

	}

int main(void){
	bool properly_nested = true;
	char c;
	printf("Enter parenteses and/or braces: ");
	do{
	
		
		c = getchar();
	
		if (c == '(' || c == '{'){
			push(c);
		
		}else if( c == ')'&& pop() != '(' ){
				properly_nested = false;
		}else if ( c == '}'&&pop() != '{' ){
		
				properly_nested = false;
		
	}
	}while(c != '\n' );
	
	if (isEmpty() && properly_nested)
	print_ested(); 
	else
	print_not_ested();
	
	return 0;
}
	