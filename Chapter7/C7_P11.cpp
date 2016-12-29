#include <stdio.h>

int main(void){
	char FirstName = ' ',c;
	printf("Enter a first and last name: ");
	do{
		c = getchar();
		if (FirstName == ' ')
			FirstName = c;
	}while (c != ' ');
	do{
		c = getchar();
		if (c != '\n')
			putchar(c);
		}while (c != '\n');
	
	printf(", %c.",FirstName);
	
	return 0;
	}