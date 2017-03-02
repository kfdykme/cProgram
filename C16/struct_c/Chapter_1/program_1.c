//1.写一个判断素数的函数

#include <stdio.h>

int isPrime(int number){
	
	for(int i = 2; i * i < number; i++)
		if((number % i) != 0)
			return 1; 
	
	return 0;
}


int main(void){


	int i = 4;
	
	printf("i = %d is ? : %d\n",i, isPrime(i) );	
		
				
	return 0;
}