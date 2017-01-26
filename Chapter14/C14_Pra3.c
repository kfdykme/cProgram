#include <stdio.h>

#define DOUBLE(x) 2*x

int main(void){
	printf("(a) %d \n"
	       	"(b) %d \n", DOUBLE(1+2),
	       	 4/DOUBLE(2));
	       	 
	return 0;
}

//(c) #define DOUBLE(x) (2*x)
	       	 