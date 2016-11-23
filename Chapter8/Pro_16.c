#include <stdio.h>
#include <ctype.h>

int main(void){
	char a;
	int alpha[27] = {0};
	int i=0;
	
	printf("Enter first word: ");
	
	do{
		a = toupper(getchar()) ;
		alpha[a- 'A']++;
	}while(a != '\n');
	
	printf("Enter second word: ");
	
	i = 0;
	
	do{
		a = toupper(getchar());
		alpha[a- 'A']--;
	}while(a != '\n');
	
	for (int i = 0;i<27;i++){
	}
	
	for (int i = 0;i<27;i++){
	
		if (alpha[i] != 0)
			break;
		if( i == 26 )
			printf("The words are anagrams.");
	}
	printf("The words are not anagrams.");
			
	return 0;
	
}
	