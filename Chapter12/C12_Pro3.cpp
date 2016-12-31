#include  <stdio.h>
#define M 110

int main(void){
	char c[M];
	printf("Enter a message:");
	while ((*(c++) = getchar()) != '\n'
		&& (c - &c[0]) != M);
//	printf("%d",p-c);
	printf("Reversal is: ");
	while (c-- !=&c[0])
		printf("%c",*(c-1));
	return 0;
}