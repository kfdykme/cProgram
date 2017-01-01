#include  <stdio.h>
#define M 110

int main(void){
	char c[M];
	int i = 0;
	printf("Enter a message:");
	while ((*(c + i++) = getchar()) != '\n'
		&& i != M);
	i--;
//	printf("%d",p-c);
	printf("Reversal is: ");
	while (i-- !=0)
		printf("%c",*(c+i));
	return 0;
}