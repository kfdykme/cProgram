#include  <stdio.h>
#define M 110

int main(void){
	char c[M], *p = c;	
	printf("Enter a message:");
	while ((*p++ = getchar()) != '\n'
		&& (p - c) != M);
//	printf("%d",p-c);
	printf("Reversal is: ");
	while (p-- !=c)
		printf("%c",*(p-1));
	return 0;
}