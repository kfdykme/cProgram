#include<stdio.h>


int main(void){
	int numberArray[10] = {0};
	int digit ;
	long number;
	printf("Enter a number: ");
	scanf("%d",&number);
//	printf("%d %d\n",number,(int)number/10);
	digit = (int )number % 10;
		
	while(number!=0){	
		numberArray[digit] ++;
//		printf("%d = %d\n",digit,numberArray[digit]);
		number = (int ) number / 10;
		digit = (int )number%10;
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