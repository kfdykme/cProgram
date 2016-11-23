#include <stdio.h>

int main(void){
	char  N,firstNameFirst = ' ';
	char Name[20];
	int secondNameStart = 0,secondNameEnd =0;
	bool isFirstNameEnd = false;
	printf("Enter a first name and last name: ");
	
	N = getchar();
	
	while( N != '\n'){
		Name[secondNameEnd] = N;
		firstNameFirst = N >= 'A' &&N <= 'Z'&& firstNameFirst  == ' '  ? firstNameFirst = N :firstNameFirst ;	
		
		secondNameStart = isFirstNameEnd ? secondNameStart: secondNameStart+1;
		isFirstNameEnd = firstNameFirst != ' ' && N == ' ' && isFirstNameEnd == false ? true: isFirstNameEnd;
		
		secondNameEnd++;
		N = getchar();
	}
	
	printf("Your enered the name: ");
	
	for (int i = 0; i < secondNameEnd - secondNameStart;i++){
		putchar(Name[secondNameStart + i]);
	} 
	
	printf(", %c.", firstNameFirst);
	
	return 0 ;
	}
	
					
			