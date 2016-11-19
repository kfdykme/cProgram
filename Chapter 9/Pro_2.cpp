#include<stdio.h>


int main(void){
	int numberArray[10] = {0};
	int digit ;
	long number;
	printf("Enter a number: ");
	scanf("%ldigit",&number);
	digit = number%10;
	
	while(digit>0){	
		digit = number%10;
		numberArray[digit] ++;
		number /= 10;
		}
printf("Digit:      ");
	
	for(int i = 0;i <10;i++){
			printf("%d ",i);
	}
	
	printf("\nOccurrences:");
	
	for(int i = 0;i <10;i++){
			printf("%d ",numberArray[i]);
	}
	
	return 0;
}