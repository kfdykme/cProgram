#include <stdio.h>

void selection_sort(int length,int numberArray[]);

int main(void){
	int digit = 0;
	int eachNumber[999];
	
	char a;
	printf("Enter some number: (Enter \\n after a number to end) :\n");
	
	do{
		scanf("%d%c",&eachNumber[digit],&a);
		digit++;
	}while( a != '\n');
	
	selection_sort(digit ,eachNumber);
	
	for(int i = 0 ; i < digit ; i++)
		printf("\neN = %d ",eachNumber[i]);
	
	return 0;
}

void selection_sort(int length,int numberArray[]){
	int max = 0;
	int maxDig;
	
	for (int i = 0 ; i<length;i++){
		if(max < numberArray[i]){
			max = numberArray[i];
			maxDig = i;
		}
	}
	
	for (maxDig;maxDig < length -1;maxDig++)
		numberArray[maxDig] = numberArray[maxDig+1];
	numberArray[length-1] = max;
	if(length-- >1)
		selection_sort(length,numberArray);
}