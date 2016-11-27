#include <stdio.h>

int num_digit(int number);

int main(void){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	printf("%d",num_digit(n));
	return 0;
	
}
int num_digit(int number){
	int digit=0;
	while(number>0){
		digit++;
		number /= 10;
	}
	return digit;
}
