#include  <stdio.h>
#define M 110

int main(void){
	char c[M];
	int n = 0;
	printf("Enter a message:");
	while ((c[n++] = getchar()) != '\n'
		&& n != M);
	printf("Reversal is: ");
	while (n-- !=0)
		printf("%c",c[n-1]);
	return 0;
}