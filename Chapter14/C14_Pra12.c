#include <stdio.h>

#define M 10

int main(void){
	
	#if M
		printf("(a)\n");
	#endif
	
	#ifdef M 
		printf("(b)\n");
	#endif
	
	#ifndef M
		printf("(c)\n");
	#endif
	
	#if defined(M)
		printf("(d)\n");
	#endif
	
	#if !defined(M)
		printf("(e)\n");
	#endif
	
	return 0;
}