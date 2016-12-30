#include <stdio.h>

#define CANCUT a == '.'||a == ','||a == '!'||a == '?'||a == ':'||a == ';'||a == ' '||a == '\n'
int main(void){
	char a;
	char word[30][20];
	for (int y = 0; y < 30 ; y++)
			word[y][0] ='\0';
		
	
	int wordNum = 0;
	int haveRead = 0;
	printf("Enter a sentence: ");
	int i = 0;
	char s;
	a = getchar();
	while(1){
		if (CANCUT){
			word[wordNum++][ haveRead] = '\0';
			if (a == '\n'){
				word[wordNum++][ haveRead-1] = '\0';
				break;
			} else 
				s = a;	
			
			haveRead = 0;
	
		} else {
			word[wordNum][haveRead++] = a;
		}
			
		a = getchar();
	}
//		printf("%d",i - haveRead);

	
	printf("\nReversal of sentence:");
	for (int r = wordNum -1 ; r >= 0 ; r--){
		printf(word[r]);
		if (r != 0)
			printf(" ");
	}
	
	printf("%c",s);
	return 0;
	
}