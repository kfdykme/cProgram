#include <stdio.h>

#define P3(x) ((x)*(x)*(x))
#define NS54(x) (x % 4)
#define Cab(a,b) ( a*b < 100 ? 1: 0)
int main(void){
	
	int n;
	
	printf("Enter a number to caculate its : ");
	
	scanf("%d",&n);
	
	//printf("%d\n",n);
	
	printf("%d^3 = %d\n",n, P3(n));
	printf("NS54(%d) = %d\n",n, NS54(n));	
	printf("Enter another number: ");
	int n2;
	scanf("%d",&n2);
	printf("Cab(%d,%d) = %d",n, n2,Cab(n,n2));
	
	return 0;
		
	}	