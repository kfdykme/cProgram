#include <stdio.h>

int main(void){
	int a,b,c =1;
	
	printf("Enter a fraction:(a/b) ");
	scanf("%d/%d",&a,&b);
	
	int num,denom;
	num = a ;
	denom = b;
	
	while( b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	
	num = num /a;
	denom = denom / a;
	
	printf("In lowest terms  : %d/%d ",num,denom);
	
	return 0;
}
	
	