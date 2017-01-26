#include <stdio.h>

#define AVG(x,y) ((x+y)/2)
#define AREA(x,y) ((x) * (y))

int main(void){
	
	printf("%d %d", AVG(12,33), AREA(12,12));
	
	return 0;
}