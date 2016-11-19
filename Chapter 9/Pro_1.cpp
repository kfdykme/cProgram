#include<stdio.h>

#define false 0
#define true 1
#define isRepeat 2

typedef int Isre;

int main(void){
	Isre numberArray[10] = {false};
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
	
	printf("Repeatedr digit(s):");
	
	for(int i = 0;i <10;i++){
		if (numberArray[i] > true )
			printf("%d ",i);
	}
	
	return 0;
}