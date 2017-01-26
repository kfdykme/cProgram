#include <stdio.h>

void f(void);

int main(void){
	
	f();
	
	return 0;
}

void f(void){
	printf("N is %d\n", 100);
}

//输出 N is 100