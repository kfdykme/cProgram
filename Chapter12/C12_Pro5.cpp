#include <stdio.h>

#define LEN 999 
#define DEFAULT -10
#define CANCUT str[i] == '.'||str[i] == ','||str[i] == '!'||str[i] == '?'||str[i] == ':'||str[i] == ';'||str[i] == ' '
int main(void){
	char str[LEN],  *c = str;
	char middleString[LEN];
	int wordStart = DEFAULT,wordEnd = DEFAULT;
	char a;
	
	
	printf("Enter a sentence: ");
	
	
	while((*c++ = getchar()) != '\n');
	//c--;
	*c = '\0';
	printf("%s\n",str);
	printf("Reversal of sentence: ");
	//int c - str; = c - str;
	for (int i = c - str-1; i > -1  ;i--){
		if (i == 0){
			wordStart = 0;
			if (wordStart != DEFAULT && wordEnd != DEFAULT){
			//printf("\nend = %d start = %d",wordEnd,wordStart);
			for (int j = 0;j <= wordEnd - wordStart;j++){
				middleString[j] = str[wordEnd  -j];
			}
			
			for (int j = 0;j <= wordEnd - wordStart;j++){
				
				str[wordStart +j] = middleString[j];
			}
				
			wordEnd = wordStart; 
			wordStart = DEFAULT;
			
			}
		}
		if ( CANCUT){
			wordStart = wordEnd != DEFAULT && wordStart == DEFAULT ? i : wordStart;
			wordEnd = wordEnd == DEFAULT && wordStart == DEFAULT ? i:wordEnd;
			
			//printf("\n'z' 'a' if is done!\n");
			}
		if (wordStart != DEFAULT && wordEnd != DEFAULT){
			//printf("\nend = %d start = %d",wordEnd,wordStart);
			for (int j = 1;j < wordEnd - wordStart;j++){
			//	printf("\nmS[%d] (%c) = s[%d] (%c) ",j,middleString[j],wordEnd -j,str[wordEnd -j]);
				middleString[j] = str[wordEnd  -j];
			}
			for (int j = 1;j < wordEnd - wordStart;j++){
			//	printf("\ns[%d] (%c) = mS[%d] (%c) ",wordStart +j,str[wordStart +j],j,middleString[j]);
				
				str[wordStart +j] = middleString[j];
				}
			wordEnd = wordStart; 
			wordStart = DEFAULT;
		}
	}
	
	for (int i = c - str-2; i > 0  ;i--){
		printf("%c",str[i]);
		printf("\n str[%d] = %c\t c - str; = %d\ti = %d",i,str[i],c - str,i);
	}
		printf("%c",str[c - str-1]);
	return 0;
	
}