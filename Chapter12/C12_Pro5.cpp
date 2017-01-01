#include <stdio.h>

#define LEN 999 
#define DEFAULT -10
#define CANCUT *p == '.'||*p == ','||*p == '!'||*p == '?'||*p == ':'||*p == ';'||*p == ' '
int main(void){
//	int strMainlyLength = 1;
	char str[LEN], *p = str,*p2 = str,*p3,*p1 = str;
	char middlestr[LEN];
	int wordStart = DEFAULT,wordEnd = DEFAULT;
	char c;
	
	printf("Enter a sentence: ");
	
	
	while ((*(p++) = getchar()) != '\n');
	p--;
	
	printf("Reversal of sentence: ");
	while (p2++ != p){
		if (CANCUT){
			*p3 = *(p2-1);
			c = *p3;
			*p3-- = *p1;
			*p1++ = c;
		}
		printf("%c\n",*p2);
	}
	
	
	
	for (; (p--) - str > 0  ;)
		printf("%c",*p);
		//printf("\n str[%d] = %c\t strMainlyLength = %d\ti = %d",i,*p,strMainlyLength,i);
	
	return 0;
	
}