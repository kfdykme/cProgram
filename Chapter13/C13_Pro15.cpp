#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

int do_calc(int n,char mark);
int pop(void);
void push(int i);

void evaluate_RPN_expression(const char *e);


int main(void){
	char s[100];
	int n = 0;
	
	printf("Enter an RPN expression:");
	while ((s[n++] = getchar()) != '\n' );
	s[n-1]= '\0';
	//printf("%s----",s);
	while(1){
		evaluate_RPN_expression(s);
		n = 0;
		while ((s[n++] = getchar()) != '\n' );
		s[n-1]= '\0';
	//	printf("%s----",s);
	//scanf("%s",s);
	}
	return 0;
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
	
void evaluate_RPN_expression(const char *e){
	//printf("s input!\n");
		while(*e != '\0'){
			switch(*e){
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
					push(*e - 48);
					break;
				case '+':
				case '/':
				case '*':
				case '-':
					do_calc(pop(),*e);
					break;
				case '=':
					printf("\nValur of expressing : %d",pop());
					printf("\nEnter an RPN expression:");
				case ' ': case '\0':
					break;
				default:
					exit(0);
			}
			e++;
		}
			
}  
	

int pop(void){
	return stack[--top];
	}
	
void push(int i){
	stack[top++] = i;
	}	
	