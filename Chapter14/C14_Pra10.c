#include <stdio.h>

#define ERROR(s,i) fprintf(stderr,s,i)

int main(void){
	int index = 9;
	ERROR("Range error:index = %d\n",index);
	return 0;
}