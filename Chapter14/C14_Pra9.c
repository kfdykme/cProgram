#include <stdio.h>

#define CHECK(x,y,n) ((x) > 0 	\
			&& (x) < (n - 1)	  \
			&& (y) > 0			\
			&& (y) < (n - 1) ? 1: 0)
			
#define MEDIAN(x,y,z) (((x) + (y) + (z)) / 3)

#define POLYNOMIAL(x) (((((3*x+2) *x - 5)*x -1)*x+7)*x-6)

int main(void){
	
	printf("%d %d %d",CHECK(1,2,3),MEDIAN(1,2,3),POLYNOMIAL(0));
	
	return 0;
}