#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))


int main(void){
	int a[4];
	
	printf("%d", NELEMS(a));
	
	return 0;
}