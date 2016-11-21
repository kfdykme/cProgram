#include <stdio.h>
#include <ctype.h>

int main(void){
	char oneChar;
	long length = 0;
	char longChar[length];
	printf("Enter message:");
	
	oneChar = getchar();
	while(oneChar != '\n'){
		oneChar = toupper(oneChar);
		
		switch(oneChar){
			case 'E':
				oneChar = '3';
				break;
			case 'I':
				oneChar = '1';
				break;
			case 'S':
				oneChar = '5';
				break;
			case 'B':
				oneChar = '8';
				break;
			case 'O':
				oneChar = '0';
				break;
			case 'A':
				oneChar = '4';
				break;
				}
		
		longChar[length++] = oneChar;
		
		oneChar = getchar();
	}
	
	printf("In B1FF-speak: ");
	for(int i = 0; i <= length-1;i++){
		printf("%c",longChar[i]);
	}
	printf("!!!!!!!\n");
	return 0;
	
}