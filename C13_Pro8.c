//revise from Pro_4.c

#include <stdio.h>
#include <ctype.h> 
//To ues tpupper()

int compute_scrabble_value(const char *word);

int main(void){
	char s[100];
	int a = 0;
	
	printf("Enter a word: ");
	scanf("%s",s);
	
	printf("Scrabble value: %d", compute_scrabble_value(s));
	printf("\nThis program is stoped");
	
	return 0;
}
	
int compute_scrabble_value(const char *word){
	char *c = word;
	int sum = 0;
	while (*c != '\0'){
		
		if ('a' <= *c && *c <= 'z'){
			*c = toupper(*c);
		}
		
		switch(*c){
			case 'A' : case 'E': case 'I':  case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U': 
				sum += 1;
				break;
			case 'D': case 'G':  
				sum += 2;
				break;
			case 'J': case 'X': 
				sum += 8;
			case 'K':
				sum += 5;
				break;
			case 'B': case 'C': case 'M': case 'P':
				sum += 3;
				break;
			case 'F': case 'H': case 'V': case 'W': case 'Y': 
				sum += 4;
				break;
			case 'Q': case 'Z':
				sum += 10;
				break;
				
		}
	//	printf("Scrabble value: +%c  %d\n", *c, sum);
	
		c++;	
	}
			return sum;
		
}
	