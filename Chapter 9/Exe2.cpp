#include <stdio.h>

int check(int x,int y,int n);

int main(void){
	
	int a= 4 ,b=2 ,c=4;

	printf("%d",check(a,b,c));	


	return 0;
}

int check(int x,int y ,int n){
	return x <= n -1 
		   && x>= 0
		   && y <= n -1
		   && y >= 0 ? 1: 0;
}