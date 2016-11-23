#include <stdio.h>

double getTaxRevenue(double iicome);

int main(void){
	
	double income;
	
	printf("Enter your income: ");
	scanf("%lf", &income);
	
	
	printf("Your tax revenue:$ %8.2lf", getTaxRevenue(income));
	
	return 0;
	
}


double getTaxRevenue(double income){
	double taxRevenue;
		if ( income <= 750){
		taxRevenue = 0.01f * income;
	} else if (income >750 && income <= 2250){
		taxRevenue = 7.5f + 0.02f * (income - 750);
	} else if ( income > 2250 && income <= 3750){
		taxRevenue = 37.5f +0.03f * (income - 2250);
		} else if ( income >3750 && income <= 5250){
			taxRevenue = 82.5f + 0.04f * (income - 3750);
			} else if ( income > 5250 && income <= 7000){
				taxRevenue = 142.5f + 0.05f * (income - 5250);
			} else if ( income > 7000){
				taxRevenue = 230.0f + 0.06f * (income - 7000);
			};

	return taxRevenue;
}