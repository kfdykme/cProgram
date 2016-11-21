#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void){
	int low_rate, num_years, year;
	double value[5];
	
		printf("Enter interest rate: ");
		scanf("%d", &low_rate);	
		printf("Enter number of years: ");
		scanf("%d", &num_years);
		
		printf("\nYears");
		for(int i = 0; i <NUM_RATES;i++){
			printf("%6d%", low_rate + i);
			value[i] = INITIAL_BALANCE;
		}
		
		printf("\n");
		
		for (year = 1 ; year <= num_years*12; year++){
			if( year %12 == 1)
				printf("%3d    ", year);
			for ( int i = 0; i< NUM_RATES; i++ ){
				value[i] += (low_rate + i) / 100.0 * value[i];
				if( year %12 == 1)
				printf("%7.2f", value[i]);
				}
				if( year %12 == 1)
				printf("\n");
		}
	
	return 0;
}