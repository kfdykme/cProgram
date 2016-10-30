#include <stdio.h>

int main(void){
	float loan, rate, monthlyPayment;
	float balRemaining;
	int payTimes;
	
	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	
	 printf("Enter interest rate: ");
	 scanf("%f", &rate);
	 
	 printf("Enter monthly payment: "); 
	 scanf("%f" , &monthlyPayment);
	 
	 printf("Enter interest pay time(s): ");
	 scanf("%d", &payTimes);
	 
	 balRemaining = loan - monthlyPayment + loan * rate * 0.01f /12;
	 
	 for ( int i = 0 ; i < payTimes ; i++){
	 	printf("Balance remaining after payment: $%.2f\n", balRemaining);
	 	
	 	balRemaining = balRemaining - monthlyPayment + balRemaining * rate * 0.01f /12;
	 }
	 
	 return 0 ;
}
	 