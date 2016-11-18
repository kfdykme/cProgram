#include <stdio.h>

int main(void){
	
	int charLength = 0;
	char string[charLength];
	char endChar;
	int wordStart,wordEnd;
	char a;
	
	
	printf("Enter a sentence: ");
	
	a = getchar();
	
	while(a != '\n'){
		string[charLength] = a;
		printf("\nstring[%d] = %c",charLength,string[charLength]);
		charLength++;
		//printf("\na = %c",a);
		a = getchar();;
	}
	
	printf("Reversal of sentence: ");
	
	for (int i = charLength-1; i > -1  ;i--){
		printf("\n string[%d] = %c\t charLength = %d\ti = %d",i,string[i],charLength,i);
	}
	
	
	return 0;
	
}