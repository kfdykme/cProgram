#include <stdio.h>

void selection_sort(int length,int numberArray[]);

int main(void){
	int digit = 0;
	int eachNumber[digit];
	
	char a;
	printf("Enter some number: (Enter \n after a number to end) ");
	do{
		scanf("%d%c",&eachNumber[digit],&a);
		digit++;
	}while( a == ' ');
	
	selection_sort(digit,eachNumber[]);
	
	for(int i = 0;i<--digit;i++){
		printf("%d ",eachNumber[i]);
	}
	
	printf("\nend while!");
	return 0;
}

void selection_sort(int length,int numberArray[length]){
	int maxNumber= 0;
	for(int i = 0; i < length-1;i++){
		maxNumber = maxNumber > numberArray[i] ?
					maxNumber:numberArray[i];
	}
	if(!(--length!=0))
		selection_sort(length,numberArray[]);
}