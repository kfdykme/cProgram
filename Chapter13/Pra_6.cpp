#include <stdio.h>

void censor(char str[]);

int main(void){
	char s[100];
	scanf("%s",s);
	printf("%s",s);
	
	return 0;
}
void censor(char str[]){
	char *p = str;
	char is_foo[4] = "foo";
	
	for (int i = 0 ;*p != '\0';*p++){
		if(*p == is_foo[i]){
			i++;
		} else {
			i = 0;
		}
		
		if (i == 3){
			*p = 'x';
			*(p-1) = 'x';
			*(p-2) = 'x';
		}
		
	}
	
}