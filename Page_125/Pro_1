/*
	part one:
		defien vars;
	patr two:
		enter a number;
	part three:
		check each digit number of the entered number;
		if a same number turn up twice, pick this number;
	part four:
		print the picked number; 

*/

#include <stdio.h>

int main(void){
	long eNum;
	int d;
	int nArr[11] = {0};
	
	//try
	/*for ( int i = 0; i < 10; i++){
		printf("%d",nArr[i]);
	};
	printf("\n");
	*/
	
	printf("Enter a number: ");
	scanf("%ld", &eNum);
	
	while(eNum > 0){
		d = eNum % 10;
		nArr[d]++;
		eNum = eNum / 10;
	}
		
	for ( int i = 0; i < 10; i++){
		//printf("%d\n",nArr[i]);
		
		if (nArr[i] > 1){		
			printf("Repeated digit(s): ");
			break;
		} else {
			nArr[11]++;
		}	
		if(nArr[11] == 10){
			printf("No repeated!");
		}
	}
		
	for ( int i = 0; i < 10; i++){
		//printf("%d\n",nArr[i]);
		
		if(nArr[i] > 1){		
			printf("%d  ",i);
			nArr[i] = 0;
		} 
	}	

	
			
	return 0;
}
	