#include <stdio.h>

#define LEN 999 
#define DEFAULT -10
#define CANCUT string[i] == '.'||string[i] == ','||string[i] == '!'||string[i] == '?'||string[i] == ':'||string[i] == ';'||string[i] == ' '
int main(void){
	int stringMainlyLength = 1;
	char string[LEN] = {' '};
	char middleString[LEN];
	int wordStart = DEFAULT,wordEnd = DEFAULT;
	char a;
	
	
	printf("Enter a sentence: ");
	
	a = getchar();
	
	while(a != '\n'){
		string[stringMainlyLength] = a;
		stringMainlyLength++;
		a = getchar();;
	}
	
	printf("Reversal of sentence: ");
	
	for (int i = stringMainlyLength-1; i > -1  ;i--){
		if (i == 0){
			wordStart = 0;
			if (wordStart != DEFAULT && wordEnd != DEFAULT){
			//printf("\nend = %d start = %d",wordEnd,wordStart);
			for (int j = 0;j <= wordEnd - wordStart;j++){
				middleString[j] = string[wordEnd  -j];
			}
			
			for (int j = 0;j <= wordEnd - wordStart;j++){
				
				string[wordStart +j] = middleString[j];
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
			//	printf("\nmS[%d] (%c) = s[%d] (%c) ",j,middleString[j],wordEnd -j,string[wordEnd -j]);
				middleString[j] = string[wordEnd  -j];
			}
			for (int j = 1;j < wordEnd - wordStart;j++){
			//	printf("\ns[%d] (%c) = mS[%d] (%c) ",wordStart +j,string[wordStart +j],j,middleString[j]);
				
				string[wordStart +j] = middleString[j];
				}
			wordEnd = wordStart; 
			wordStart = DEFAULT;
		}
	}
	
	for (int i = stringMainlyLength-2; i > 0  ;i--){
		printf("%c",string[i]);
		//printf("\n string[%d] = %c\t stringMainlyLength = %d\ti = %d",i,string[i],stringMainlyLength,i);
	}
		printf("%c",string[stringMainlyLength-1]);
	return 0;
	
}