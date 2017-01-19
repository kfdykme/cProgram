#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

void read_line(char s[]);

int main(void){
	char s[120];
	printf("Enter a first and last name: ");
	read_line(s);
	
	reverse_name(s);
	printf("%s",s);
	
	return 0;
}

void read_line(char s[]){
	char *p = s, c;
	while ((c = getchar()) != '\n')
		*(p++) = c;
	*p = '\0';
} 


void reverse_name(char *name){
	char *c = name, FirstName = ' ';
	
	while (*c != ' ') {
		if (FirstName == ' ')
			FirstName = *c;
		c++;
	}
	
	strcpy(name,++c);
	strcat(name,", ");
	char l[3] = {FirstName,'.','\0'};
	strcat(name,l);
}
	
