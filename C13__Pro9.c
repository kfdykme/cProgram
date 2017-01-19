#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);
void read_line(char s[]);

int main(void){
	char s[190];
	int vN = 0;
	printf("Enter a sentence: ");
	read_line(s);
	vN = compute_vowel_count(s);
	printf("Your sentence contains %d vowels.", vN);
	
	return 0;
}

int compute_vowel_count(const char *sentence){
	char *c = sentence;
	int vN = 0;
	while (*c != '\0'){
		*c = toupper(*c);
		
		switch(*c){
			case 'A' : case 'E': case 'I' : case 'O': case 'U':
				vN++;
				break;			
		}
		//printf("*c = %c ; vN = %d\n",*c,vN);
		c++;
	}
	return vN;
}

void read_line(char s[]){
	char *p = s,c;
	while ( (c = getchar()) != '\n')
		*(p++) = c;
	*p = '\0';
	
}
	
