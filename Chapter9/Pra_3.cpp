#include <stdio.h>

int gcd (int m, int n); 

int main(void){
	int a,b;
	printf("Enter x y : ");
	scanf("%d %d",&a,&b);
	
	printf("%d" ,gcd(a,b));
//	printf("\nend"); 
	return 0;
}
int gcd (int n, int m){
	int i;
	while( n != 0){ 
		i = m % n;
		m = n;
		n = i;
	}
	return m;
}
	
	
	
	