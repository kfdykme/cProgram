#include <stdio.h>
int doCalc(int a);

int main(void){
	int n ;
	printf("Enter a number to do calc: ");
	scanf("%d",&n);
	
	printf("%d",doCalc(n));
	
	return 0;
}

int doCalc(int a){
	return 3*a*a*a*a*a + 2*a*a*a*a - 5*a*a*a - a*a + 7*a -6;
}