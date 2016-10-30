#include <stdio.h>

int main(void){
	int a,b,c =1;
	
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	
	while( b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	
	printf("Greatest common divisor: %d ",a);
	
	return 0;
}
	
	