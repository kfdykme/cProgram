#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_line(char str[], int n);


int main(void){
	char a[100] ={' '};
	char b[100];
  printf("get: ");
  read_line(a,10);
 
   printf("put: ");
  	 	puts(a);
read_line(b,10);	

   printf("put: ");
  	 	puts(b);	return 0;
	
}

int read_line(char str[], int n){
	int ch, i = 0;
	while((ch = getchar()) == ' ');
	while( ch != '\n')
		if ( i < n){
			if ( isspace(ch) &&i>0)
				return i;
			else
				str[i++] = ch;
			ch = getchar();
		}
	str[i] = '\0';
	
	return i;

}