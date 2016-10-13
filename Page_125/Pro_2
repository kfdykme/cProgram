#include <stdio.h>

int main(void){
	int d;
	long eNum;
	int nArr[10] = {0};
	

	printf("Enter a number: ");
	scanf("%ld", &eNum);
	
	while(eNum > 0){
		d = eNum % 10;
		nArr[d]++;
		eNum = eNum / 10;
	}
		
			
	printf("Digit:\t\t");
	
	for(int i = 0; i < 10; i ++){
		printf("%d ", i);
		}
	
	printf("\nOccurrences:\t");
	
	for(int i = 0; i < 10; i ++){
		printf("%d ", nArr[i]);
		}
	
	return 0;
	
		}	