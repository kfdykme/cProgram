#include <stdio.h>

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denminator);

int main(void){
	int a,b;
	
	printf("Enter a fraction:(a/b) ");
	scanf("%d/%d",&a,&b);
	
	int num,denom;
	num = a ;
	denom = b;
	
	reduce(a,b,&num,&denom);
	
	printf("In lowest terms  : %d/%d ",num,denom);
	
	return 0;
}
	
void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denminator){
	int c = 1;
	
	while( denominator != 0){
		c = numerator % denominator;
		numerator = denominator;
		denominator = c;
	}
	
	*reduced_numerator = *reduced_numerator /a;
	*reduced_denminator = *reduced_denminator / a;
	
}
	
	
	