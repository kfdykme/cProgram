#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void){
	int dollar;
	
	printf("Enter a dollar amount: ");
	scanf("%d", &dollar);
	
	int a,b,c,d;
	
	pay_amount(dollar,&a,&b,&c,&d);	
	
	printf("&20 vills: %d\n", a);
	printf("&10 vills: %d\n", b);
	printf("& 5 vills: %d\n", c);
	printf("& 1 vills: %d\n", d);
	
	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
	*twenties = dollars / 20;
	dollars = dollars - *twenties * 20;
	*tens = dollars / 10;
	dollars = dollars - *tens * 10;
	*fives = dollars / 5;
	dollars = dollars - *fives * 5;
	*ones = dollars / 1;
}

