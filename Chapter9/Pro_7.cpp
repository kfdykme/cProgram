#include <stdio.h>

int power(int x,int n);

int main(void){
	int a, b;
	
	printf("Enter x n:");
	scanf("%d%d",&a,&b);
	
	printf("%d",power(a,b));
	
	return 0;
	
}

int power(int x,int n){
	if(n == 0)
		return 1;
	
	if (n % 2 == 0)
		return power(x,n/2) * power(x,n/2);
	else if ((n -1) %2 == 0)
		return x * power(x,n-1);

}