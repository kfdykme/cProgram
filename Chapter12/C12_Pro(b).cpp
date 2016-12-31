#include <stdio.h>
#include <ctype.h>

int main(void){
	char s[100], *p = s;
	char c;
	printf("Enter a mesage: ");
	
	while ((c = toupper(getchar())) != '\n')
		if (c >= 'A' && c <= 'Z')
			*p++ = c;
	p--;
	char *p2 = s;
	for (int i = 0; i < p-s; i++)
		if ( *p2++ != *p--){
			printf("Not a plaindrome");
			return 0;
			}
			
	printf("Plaindrome");
	
	return 0;
	}		