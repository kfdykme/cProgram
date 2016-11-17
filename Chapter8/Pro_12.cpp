#include <stdio.h>
#include <ctype.h> 

int main(void){
	char c;
	int sum = 0;
	int alphbet[25];
	char alphbet0 ;
	for (int i = 0; i< 26;i++){
		alphbet0 = 'A' + i;
		switch(alphbet0){
			case 'A' : case 'E': case 'I':  case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U': 
				alphbet[i] = 1;
				break;
			case 'D': case 'G':  
				alphbet[i] = 2;
				break;
			case 'J': case 'X': 
				alphbet[i] = 8;
			case 'K':
				alphbet[i] = 5;
				break;
			case 'B': case 'C': case 'M': case 'P':
				alphbet[i] = 3;
				break;
			case 'F': case 'H': case 'V': case 'W': case 'Y': 
				alphbet[i] = 4;
				break;
			case 'Q': case 'Z':
				alphbet[i] = 10;
				break;
		}
	}
	
	printf("Enter a word: ");
		c = getchar();
	while(c != '\n'){
		c = 'a' <= c && c <= 'z' ? toupper(c):c;
		sum += alphbet[c - 'A'];
		c = getchar();
	}
	
	printf("%d",sum);
	return 0;
}
	
	