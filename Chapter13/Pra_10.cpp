#include <stdio.h>
#include <string.h>

int main(void){
	
	char a[4] = "abc";
	char *q;
	char *p = a;
	char b[6];
	strcpy(b,p);
	
	printf("%s",b);
	return 0;
	
}